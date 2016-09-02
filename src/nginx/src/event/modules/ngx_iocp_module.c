
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>
#include <ngx_iocp_module.h>


static ngx_int_t ngx_iocp_init(ngx_cycle_t *cycle, ngx_msec_t timer);
static void ngx_iocp_done(ngx_cycle_t *cycle);
static ngx_int_t ngx_iocp_add_event(ngx_event_t *ev, ngx_int_t event,
									ngx_uint_t flags);
static ngx_int_t ngx_iocp_del_event(ngx_event_t *ev, ngx_int_t event,
									ngx_uint_t flags);
static ngx_int_t ngx_iocp_add_connection(ngx_connection_t *c);
static ngx_int_t ngx_iocp_del_connection(ngx_connection_t *c,
										 ngx_uint_t flags);
static ngx_int_t ngx_iocp_process_events(ngx_cycle_t *cycle, ngx_msec_t timer,
										 ngx_uint_t flags);

static void *ngx_iocp_create_conf(ngx_cycle_t *cycle);
static char *ngx_iocp_init_conf(ngx_cycle_t *cycle, void *conf);



static ngx_str_t      iocp_name = ngx_string("iocp");

static ngx_command_t  ngx_iocp_commands[] = {

    { ngx_string("iocp_threads"),
      NGX_EVENT_CONF|NGX_CONF_TAKE1,
      ngx_conf_set_num_slot,
      0,
      offsetof(ngx_iocp_conf_t, threads),
      NULL },

    { ngx_string("post_acceptex"),
      NGX_EVENT_CONF|NGX_CONF_TAKE1,
      ngx_conf_set_num_slot,
      0,
      offsetof(ngx_iocp_conf_t, post_acceptex),
      NULL },

    { ngx_string("acceptex_read"),
      NGX_EVENT_CONF|NGX_CONF_FLAG,
      ngx_conf_set_flag_slot,
      0,
      offsetof(ngx_iocp_conf_t, acceptex_read),
      NULL },

      ngx_null_command
};



static ngx_event_module_t  ngx_iocp_module_ctx = {
    &iocp_name,
    ngx_iocp_create_conf,                /* create configuration */
    ngx_iocp_init_conf,                  /* init configuration */

    {
        ngx_iocp_add_event,              /* add an event */
        ngx_iocp_del_event,              /* delete an event */
        ngx_iocp_add_event,              /* enable an event */
        ngx_iocp_del_event,              /* disable an event */
        ngx_iocp_add_connection,         /* add an connection */
        ngx_iocp_del_connection,         /* delete an connection */
        NULL,                            /* process the changes */
        ngx_iocp_process_events,         /* process the events */
        ngx_iocp_init,                   /* init the events */
        ngx_iocp_done,                   /* done the events */
    }
};

ngx_module_t  ngx_iocp_module = {
    NGX_MODULE_V1,
    &ngx_iocp_module_ctx,                /* module context */
    ngx_iocp_commands,                   /* module directives */
    NGX_EVENT_MODULE,                    /* module type */
    NULL,                                /* init master */
    NULL,                                /* init module */
    NULL,                                /* init process */
    NULL,                                /* init thread */
    NULL,                                /* exit thread */
    NULL,                                /* exit process */
    NULL,                                /* exit master */
    NGX_MODULE_V1_PADDING
};



HANDLE                     iocp;
static OVERLAPPED_ENTRY   *event_list;
static ngx_uint_t          nevents;

static struct sockaddr_in   ngx_iocp_sa_v4;
static struct sockaddr_in6  ngx_iocp_sa_v6;
ngx_addr_t                 ngx_iocp_local_addr_v4;
ngx_addr_t                 ngx_iocp_local_addr_v6;

ngx_os_io_t  ngx_iocp_io = {
    ngx_overlapped_wsarecv,
    ngx_overlapped_wsarecv_chain,
    ngx_overlapped_wsarecv,
    ngx_overlapped_wsasend,
    NULL,
    ngx_overlapped_wsasend_chain,
    0
};

static ngx_int_t
ngx_iocp_init(ngx_cycle_t *cycle, ngx_msec_t timer)
{
    ngx_iocp_conf_t  *cf;

    ngx_iocp_sa_v4.sin_family = AF_INET;
    ngx_iocp_sa_v4.sin_addr.s_addr = htonl(INADDR_ANY);
    ngx_iocp_sa_v4.sin_port = htons(0);

    ngx_iocp_local_addr_v4.sockaddr  = (struct sockaddr *) &ngx_iocp_sa_v4;
    ngx_iocp_local_addr_v4.socklen   = sizeof(struct sockaddr_in);
    ngx_iocp_local_addr_v4.name.len  = sizeof("INADDR_ANY") - 1;
    ngx_iocp_local_addr_v4.name.data = (u_char *) "INADDR_ANY";

    ngx_iocp_sa_v6.sin6_family = AF_INET6;
    ngx_iocp_sa_v6.sin6_addr   = in6addr_any;
    ngx_iocp_sa_v6.sin6_port   = htons(0);

    ngx_iocp_local_addr_v6.sockaddr  = (struct sockaddr *) &ngx_iocp_sa_v6;
    ngx_iocp_local_addr_v6.socklen   = sizeof(struct sockaddr_in6);
    ngx_iocp_local_addr_v6.name.len  = sizeof("INADDR_ANY") - 1;
    ngx_iocp_local_addr_v6.name.data = (u_char *) "INADDR_ANY";

    cf = ngx_event_get_conf(cycle->conf_ctx, ngx_iocp_module);

    if (iocp == NULL) {
        iocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0,
            (DWORD) cf->threads);

        if (iocp == NULL) {
            ngx_log_error(NGX_LOG_EMERG, cycle->log, ngx_errno,
                "INVALID_HANDLE_VALUE CreateIoCompletionPort() failed");
            return NGX_ERROR;
        }

        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, cycle->log, 0,
            "CreateIoCompletionPort() init success");
    }

    if (nevents < cf->events) {
        if (event_list) {
            ngx_free(event_list);
        }

        event_list = ngx_alloc(sizeof(OVERLAPPED_ENTRY) * cf->events,
            cycle->log);
        if (event_list == NULL) {
            return NGX_ERROR;
        }
    }

    nevents = cf->events;

    ngx_io = ngx_iocp_io;

    ngx_event_actions = ngx_iocp_module_ctx.actions;

    ngx_event_flags = NGX_USE_IOCP_EVENT|NGX_USE_AIO_EVENT;

    return NGX_OK;
}


static void
ngx_iocp_done(ngx_cycle_t *cycle)
{
    if (CloseHandle(iocp) == 0) {
        ngx_log_error(NGX_LOG_ALERT, cycle->log, ngx_errno,
            "iocp CloseHandle() failed");
    }

    iocp = NULL;

    ngx_free(event_list);
    event_list = NULL;
    nevents = 0;
}

static ngx_int_t
ngx_iocp_add_event(ngx_event_t *ev, ngx_int_t event, ngx_uint_t flags)
{
    ngx_connection_t  *c;

    c = ev->data;

    if (ev->accept) {
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, ev->log, 0,
            "overlap accept add: fd:%d, ov:%p", c->fd, &ev->ovlp);

        ev->ovlp.event = ev;

        return NGX_OK;
    }


    ev->ovlp.event = ev;
    ev->active = 1;

    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, ev->log, 0,
        "iocp add: fd:%d k:%ui, ov:%p", c->fd, &ev->ovlp);

    if (CreateIoCompletionPort((HANDLE) c->fd, iocp, (ULONG_PTR) c, 0) == NULL)
    {
        ngx_log_error(NGX_LOG_ALERT, ev->log, ngx_errno,
            "add event %d CreateIoCompletionPort() failed",  c->fd);
        return NGX_ERROR;
    }

    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, ev->log, 0,
        "add event %d  CreateIoCompletionPort() success", c->fd);

    return NGX_OK;
}

static ngx_int_t
ngx_iocp_del_event(ngx_event_t *ev, ngx_int_t event, ngx_uint_t flags)
{
    ngx_connection_t  *c;

    c = ev->data;

    if (ev->accept) {
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, ev->log, 0,
            "overlap accept delete: fd:%d, ov:%p", c->fd, &ev->ovlp);

        return NGX_OK;
    }

    CancelIo((HANDLE)c->fd);

    ev->active = 0;
    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, ev->log, 0,
        "delete event %d  CancelIo() success", c->fd);

    return NGX_OK;
}


static ngx_int_t
ngx_iocp_add_connection(ngx_connection_t *c)
{
    ngx_event_t  *rev, *wev;

    rev = c->read;
    wev = c->write;

    rev->ovlp.event = rev;
    wev->ovlp.event = wev;

    rev->active = 1;
    wev->active = 1;

    if (CreateIoCompletionPort((HANDLE) c->fd, iocp, (ULONG_PTR) c, 0) == NULL)
    {
        ngx_log_error(NGX_LOG_ALERT, c->log, ngx_errno,
            "add connection %d CreateIoCompletionPort() failed", c->fd);
        return NGX_ERROR;
    }

    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "add connection %d  CreateIoCompletionPort() success", c->fd);

    return NGX_OK;
}

static ngx_int_t
ngx_iocp_del_connection(ngx_connection_t *c, ngx_uint_t flags)
{
    ngx_event_t  *rev, *wev;

    rev = c->read;
    wev = c->write;

    rev->active = 0;
    wev->active = 0;

    CancelIo((HANDLE)c->fd);

    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "delete connection %d  CancelIo() success", c->fd);

    return NGX_OK;
}

static ngx_int_t
ngx_iocp_process_events(ngx_cycle_t *cycle, ngx_msec_t timer, ngx_uint_t flags)
{
    int                rc, events;
    size_t             n;
    ngx_int_t          i;
    ngx_err_t          err;
    ngx_event_t       *ev;
    ngx_queue_t       *queue;

    ngx_connection_t  *c;
    ngx_event_ovlp_t  *ovlp;

    ngx_set_errno(0);

    if (ngx_win32_version >= NGX_WIN32_VER_600) {
        events = 0;

        rc = ngx_get_queued_completion_status_ex(iocp, event_list,
                                                 (ULONG) nevents,
                                                 (PULONG) &events,
                                                 (DWORD) timer, FALSE);

    } else {

        c = NULL;

        rc = GetQueuedCompletionStatus(iocp, (LPDWORD) &n, (ULONG_PTR *) &c,
                                       (OVERLAPPED **) &ovlp, (DWORD) timer);

        if (ovlp != NULL) {
            events = 1;

            event_list[0].lpCompletionKey = (ULONG_PTR) c;
            event_list[0].lpOverlapped = (OVERLAPPED *) ovlp;
            event_list[0].dwNumberOfBytesTransferred = (DWORD) n;

        } else {
            events = 0;
        }
    }

    err = ngx_errno;

    if (flags & NGX_UPDATE_TIME) {
        ngx_time_update();
    }

    /* TODO: err == ERROR_SEM_TIMEOUT */

    if (err == WAIT_TIMEOUT) {
        return NGX_OK;
    }

    for (i = 0; i < events; i++) {

        c = (ngx_connection_t *) event_list[i].lpCompletionKey;
        ovlp = (ngx_event_ovlp_t *) event_list[i].lpOverlapped;
        n = event_list[i].dwNumberOfBytesTransferred;

        if ((c != NULL && c->fd == -1) || (ovlp != NULL && ovlp->event == NULL))
        {
            continue;
        }

        ev = ovlp->event;
        ev->complete = 1;

        if (rc != 0) {
            ev->available = (int) n;
            ev->error = 0;

            if (n == 0 && !ev->accept && !ev->write && !ovlp->posted_zero_byte)
            {
                ev->eof = 1;

            } else {
                ev->eof = 0;
            }

        } else {

            ev->available = 0;
            ev->error = 1;

            ev->ovlp.error = err;
        }

        ev->ready = 1;

        if (c == NULL) {
            c = ev->data;
        }

        
        ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, err,
            "iocp ready %d, %s available %ul bytes, error %d", c->fd, ev->write ? "write" : "read", ev->available, ev->error);


        if (flags & NGX_POST_EVENTS) {

            queue = ev->accept ? &ngx_posted_accept_events
                : &ngx_posted_events;

            ngx_post_event(ev, queue);

        } else {
            ev->handler(ev);
        }
    }

    return NGX_OK;
}

static void *
ngx_iocp_create_conf(ngx_cycle_t *cycle)
{
    ngx_iocp_conf_t  *cf;

    cf = ngx_palloc(cycle->pool, sizeof(ngx_iocp_conf_t));
    if (cf == NULL) {
        return NULL;
    }

    cf->threads = NGX_CONF_UNSET_UINT;
    cf->events = NGX_CONF_UNSET_UINT;
    cf->post_acceptex = NGX_CONF_UNSET_UINT;
    cf->acceptex_read = NGX_CONF_UNSET_UINT;

    return cf;
}



static char *
ngx_iocp_init_conf(ngx_cycle_t *cycle, void *conf)
{
    ngx_iocp_conf_t *cf = conf;

    ngx_conf_init_uint_value(cf->threads, 0);
    ngx_conf_init_uint_value(cf->events, 512);
    ngx_conf_init_uint_value(cf->post_acceptex, 1);
    ngx_conf_init_uint_value(cf->acceptex_read, 0);

    return NGX_CONF_OK;
}
