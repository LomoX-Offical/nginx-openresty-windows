
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>
#include <ngx_iocp_module.h>


#define GET_STATUS(overlapped)                                             \
    ((NTSTATUS) (overlapped.Internal))

#define OVERLAPPED_SUCCESS(overlapped)                                     \
  (NT_SUCCESS(GET_STATUS(overlapped)))

#define GET_REQ_SOCK_ERROR(overlapped)                                     \
  (ngx_ntstatus_to_winsock_error(GET_STATUS((overlapped))))


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

ngx_int_t ngx_iocp_shutdown(ngx_connection_t *c);
void ngx_iocp_shutdown_handler(ngx_event_t *ev);


static ngx_str_t      iocp_name = ngx_string("iocp");
static ngx_pool_t    *ngx_iocp_pool;
static ngx_log_t     *iocp_log;

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



int ngx_ntstatus_to_winsock_error(LONG status) {
    switch (status) {
    case STATUS_SUCCESS:
        return ERROR_SUCCESS;

    case STATUS_PENDING:
        return ERROR_IO_PENDING;

    case STATUS_INVALID_HANDLE:
    case STATUS_OBJECT_TYPE_MISMATCH:
        return WSAENOTSOCK;

    case STATUS_INSUFFICIENT_RESOURCES:
    case STATUS_PAGEFILE_QUOTA:
    case STATUS_COMMITMENT_LIMIT:
    case STATUS_WORKING_SET_QUOTA:
    case STATUS_NO_MEMORY:
    case STATUS_QUOTA_EXCEEDED:
    case STATUS_TOO_MANY_PAGING_FILES:
    case STATUS_REMOTE_RESOURCES:
        return WSAENOBUFS;

    case STATUS_TOO_MANY_ADDRESSES:
    case STATUS_SHARING_VIOLATION:
    case STATUS_ADDRESS_ALREADY_EXISTS:
        return WSAEADDRINUSE;

    case STATUS_LINK_TIMEOUT:
    case STATUS_IO_TIMEOUT:
    case STATUS_TIMEOUT:
        return WSAETIMEDOUT;

    case STATUS_GRACEFUL_DISCONNECT:
        return WSAEDISCON;

    case STATUS_REMOTE_DISCONNECT:
    case STATUS_CONNECTION_RESET:
    case STATUS_LINK_FAILED:
    case STATUS_CONNECTION_DISCONNECTED:
    case STATUS_PORT_UNREACHABLE:
    case STATUS_HOPLIMIT_EXCEEDED:
        return WSAECONNRESET;

    case STATUS_LOCAL_DISCONNECT:
    case STATUS_TRANSACTION_ABORTED:
    case STATUS_CONNECTION_ABORTED:
        return WSAECONNABORTED;

    case STATUS_BAD_NETWORK_PATH:
    case STATUS_NETWORK_UNREACHABLE:
    case STATUS_PROTOCOL_UNREACHABLE:
        return WSAENETUNREACH;

    case STATUS_HOST_UNREACHABLE:
        return WSAEHOSTUNREACH;

    case STATUS_CANCELLED:
    case STATUS_REQUEST_ABORTED:
        return WSAEINTR;

    case STATUS_BUFFER_OVERFLOW:
    case STATUS_INVALID_BUFFER_SIZE:
        return WSAEMSGSIZE;

    case STATUS_BUFFER_TOO_SMALL:
    case STATUS_ACCESS_VIOLATION:
        return WSAEFAULT;

    case STATUS_DEVICE_NOT_READY:
    case STATUS_REQUEST_NOT_ACCEPTED:
        return WSAEWOULDBLOCK;

    case STATUS_INVALID_NETWORK_RESPONSE:
    case STATUS_NETWORK_BUSY:
    case STATUS_NO_SUCH_DEVICE:
    case STATUS_NO_SUCH_FILE:
    case STATUS_OBJECT_PATH_NOT_FOUND:
    case STATUS_OBJECT_NAME_NOT_FOUND:
    case STATUS_UNEXPECTED_NETWORK_ERROR:
        return WSAENETDOWN;

    case STATUS_INVALID_CONNECTION:
        return WSAENOTCONN;

    case STATUS_REMOTE_NOT_LISTENING:
    case STATUS_CONNECTION_REFUSED:
        return WSAECONNREFUSED;

    case STATUS_PIPE_DISCONNECTED:
        return WSAESHUTDOWN;

    case STATUS_CONFLICTING_ADDRESSES:
    case STATUS_INVALID_ADDRESS:
    case STATUS_INVALID_ADDRESS_COMPONENT:
        return WSAEADDRNOTAVAIL;

    case STATUS_NOT_SUPPORTED:
    case STATUS_NOT_IMPLEMENTED:
        return WSAEOPNOTSUPP;

    case STATUS_ACCESS_DENIED:
        return WSAEACCES;

    default:
        if ((status & (FACILITY_NTWIN32 << 16)) == (FACILITY_NTWIN32 << 16) &&
            (status & (ERROR_SEVERITY_ERROR | ERROR_SEVERITY_WARNING))) {
                /* It's a windows error that has been previously mapped to an */
                /* ntstatus code. */
                return (DWORD) (status & 0xffff);
        } else {
            /* The default fallback for unmappable ntstatus codes. */
            return WSAEINVAL;
        }
    }
}


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
    ngx_iocp_local_addr_v6.name.len  = sizeof("INADDR_ANY_V6") - 1;
    ngx_iocp_local_addr_v6.name.data = (u_char *) "INADDR_ANY_V6";

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

    ngx_iocp_pool = ngx_create_pool(NGX_CYCLE_POOL_SIZE, cycle->log);

    iocp_log = cycle->log;

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

    ngx_destroy_pool(ngx_iocp_pool);
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

    ev->ovlp.number = c->number;
    ev->ovlp.event  = ev;
    ev->active = 1;

    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, ev->log, 0,
        "iocp add: fd:%d k:%ui, ov:%p", c->fd, &ev->ovlp);

    if (CreateIoCompletionPort((HANDLE) c->fd, iocp, (ULONG_PTR) c->number, 0) == NULL)
    {
        ngx_log_error(NGX_LOG_ALERT, ev->log, ngx_errno,
            "add event %d CreateIoCompletionPort() failed",  c->fd);

        return NGX_ERROR;
    }

    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, ev->log, 0,
        "add event %d:%uA CreateIoCompletionPort() success", c->fd, c->number);

    if (ngx_win32_version >= NGX_WIN32_VER_600) {
        if (!ngx_set_file_completion_notification_modes((HANDLE) c->fd, 
            FILE_SKIP_SET_EVENT_ON_HANDLE |
            FILE_SKIP_COMPLETION_PORT_ON_SUCCESS)) 
        {
            ngx_log_debug1(NGX_LOG_DEBUG_EVENT, ev->log, ngx_errno,
                "add event %d SetFileCompletionNotificationModes() failed",  c->fd);
        }
    }

    if (!c->iocp) {
        c->iocp = ngx_pcalloc(ngx_iocp_pool, sizeof(ngx_iocp_connection_t));

        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
            "c->iocp created: fd:%d, result:%p", c->fd, c->iocp);

        if (c->iocp == NULL) {
            return NGX_ERROR;
        }
    }

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

    ev->active = 0;
    ev->ovlp.number = 0;

    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "delete event %d success", c->fd);

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

    rev->ovlp.number = c->number;
    wev->ovlp.number = c->number;

    rev->active = 1;
    wev->active = 1;

    if (CreateIoCompletionPort((HANDLE) c->fd, iocp, (ULONG_PTR) c->number, 0) == NULL)
    {
        ngx_log_error(NGX_LOG_ALERT, c->log, ngx_errno,
            "add connection %d CreateIoCompletionPort() failed", c->fd);
        return NGX_ERROR;
    }

    if (ngx_win32_version >= NGX_WIN32_VER_600) {
        if (!ngx_set_file_completion_notification_modes((HANDLE) c->fd, 
            FILE_SKIP_SET_EVENT_ON_HANDLE |
            FILE_SKIP_COMPLETION_PORT_ON_SUCCESS)) 
        {
            ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, ngx_errno,
                "add connection %d SetFileCompletionNotificationModes() failed",  c->fd);
        }
    }


    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "add connection %d:%uA CreateIoCompletionPort() success", c->fd, c->number);

    if (!c->iocp) {
        c->iocp = ngx_pcalloc(ngx_iocp_pool, sizeof(ngx_iocp_connection_t));
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
            "c->iocp created: fd:%d, result:%p", c->fd, c->iocp);

        if (c->iocp == NULL) {
            return NGX_ERROR;
        }
    }

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

    rev->ovlp.number = 0;
    wev->ovlp.number = 0;

    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "delete connection %d success", c->fd);

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
    ngx_atomic_uint_t  number;
    ngx_event_ovlp_t  *ovlp;

    ngx_set_errno(0);

    if (ngx_win32_version >= NGX_WIN32_VER_600) {
        events = 0;

        rc = ngx_get_queued_completion_status_ex(iocp, event_list,
                                                 (ULONG) nevents,
                                                 (PULONG) &events,
                                                 (DWORD) timer, FALSE);

    } else {

        rc = GetQueuedCompletionStatus(iocp, (LPDWORD) &n, (ULONG_PTR *) &number,
                                       (OVERLAPPED **) &ovlp, (DWORD) timer);

        if (ovlp != NULL) {
            events = 1;

            event_list[0].lpCompletionKey = (ULONG_PTR) number;
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

        number = (u_long) event_list[i].lpCompletionKey;
        ovlp   = (ngx_event_ovlp_t *) event_list[i].lpOverlapped;
        n      = (size_t) event_list[i].dwNumberOfBytesTransferred;

        if ((number != ovlp->number) || (ovlp->event == NULL) || (ovlp->event->data == NULL))
        {
            ngx_log_debug3(NGX_LOG_DEBUG_EVENT, cycle->log, err,
                "iocp ignored (ov:%p) event number:%d, ovlp->number:%d", ovlp, number, (ovlp == NULL) ? -1 : ovlp->number);

#if (NGX_DEBUG)
            if (ovlp != NULL) {

                err = 0;
                rc = OVERLAPPED_SUCCESS(ovlp->ovlp);
                if (!rc) {
                    err = GET_REQ_SOCK_ERROR(ovlp->ovlp);
                }

                ngx_log_debug4(NGX_LOG_DEBUG_EVENT, cycle->log, err,
                    "iocp event rc: %d, result: %d, error: %d, %ul bytes", rc, GET_STATUS(ovlp->ovlp), err, n);
            }
#endif
            continue;
        }

        ev = ovlp->event;
        ev->complete = 1;

        c = ev->data;
        c->ovlp_count--;

        err = 0;
        rc = OVERLAPPED_SUCCESS(ovlp->ovlp);
        if (!rc) {
            err = GET_REQ_SOCK_ERROR(ovlp->ovlp);
        }

        ngx_log_debug7(NGX_LOG_DEBUG_EVENT, cycle->log, err,
            "iocp event (ov:%p) fd: %d ready: %s, rc: %d, result:%d, %ul bytes, ovlp_count: %d", ovlp, c->fd, ev->write ? "write" : "read", rc, GET_STATUS(ovlp->ovlp), n, c->ovlp_count);

        if (c->type == SOCK_DGRAM) {
            if (err == WSAEMSGSIZE) {
                err = 0;
                rc = 1;
            }
        }

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

        if (ev->ovlp.is_connecting) {
            ngx_log_debug2(NGX_LOG_DEBUG_EVENT, cycle->log, 0,
                "iocp fd: %d, connected successfully, is_connecting is %d", c->fd, ev->ovlp.is_connecting);

            if (c->recv(c, NULL, 0) == NGX_ERROR) {
                err = ngx_socket_errno;
                ngx_log_debug1(NGX_LOG_DEBUG_EVENT, cycle->log, err,
                    "iocp fd: %d post recv failed after connected successfully", c->fd);
            }

            ev->ovlp.is_connecting = 0;
            ev->ovlp.posted_zero_byte = 0;
        }


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

ngx_int_t ngx_iocp_shutdown(ngx_connection_t *c)
{
    if (ngx_terminate || ngx_quit || ngx_exiting) {
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp shutdown immediately fd: %d, count: %ul", c->fd, c->ovlp_count);

        ngx_pfree(ngx_iocp_pool, c->iocp);
        c->iocp = NULL;
        return NGX_OK;
    }

    c->read->handler = ngx_iocp_shutdown_handler;
    c->write->handler = ngx_iocp_shutdown_handler;
    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp shutdown fd: %d, count: %ul", c->fd, c->ovlp_count);

    if (c->ovlp_count == 0) {
        ngx_pfree(ngx_iocp_pool, c->iocp);
        c->iocp = NULL;
        return NGX_OK;
    }

    c->read->log  = iocp_log;
    c->write->log = iocp_log;
    c->log        = iocp_log;

    CancelIo(c->fd);

    return NGX_AGAIN;
}


static void
ngx_iocp_shutdown_handler(ngx_event_t *ev)
{
    ngx_connection_t           *c;
    ngx_connection_handler_pt   handler;

    c = ev->data;
    handler = c->iocp->handler;

    if (ev->timedout) {
        c->timedout = 1;
    }

    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, ev->log, 0, "iocp shutdown fd:%d handler", c->fd);

    handler(c);
}
