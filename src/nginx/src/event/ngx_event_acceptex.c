
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>

#include <ngx_iocp_module.h>

typedef struct {
    ngx_event_t      ev;
    ngx_socket_t     fd;
#if 0
    ngx_pool_t      *pool;
    ngx_buf_t       *buffer;
#endif
    u_char           addr_buf[NGX_SOCKADDRLEN * 2 + 32];
} ngx_acceptex_event_t;


static ngx_int_t ngx_event_post_one_acceptex(ngx_listening_t *ls,
    ngx_acceptex_event_t *aev);
static void ngx_close_accepted_connection(ngx_connection_t *c);

static ngx_str_t debug_str = { 1, "-" };

#if (NGX_DEBUG)
static void ngx_debug_accepted_connection(ngx_event_conf_t *ecf,
                                          ngx_connection_t *c);
#endif

void
ngx_event_acceptex(ngx_event_t *ev)
{
    ngx_acceptex_event_t *aev = (ngx_acceptex_event_t *) ev;

    u_char            *buf, *local_sa, *remote_sa;
    socklen_t          socklen, local_socklen, remote_socklen;
    ngx_log_t         *log;
    ngx_socket_t       s;
    ngx_event_t       *rev, *wev;
    ngx_listening_t   *ls;
    ngx_connection_t  *c, *lc;
    ngx_event_conf_t  *ecf;

    ecf = ngx_event_get_conf(ngx_cycle->conf_ctx, ngx_event_core_module);


    lc = ev->data;
    ls = lc->listening;
    ev->ready = 0;


    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, ev->log, 0,
                   "accept on %V, ready: %d", &ls->addr_text, ev->available);


    buf = aev->addr_buf;
    s = aev->fd;

    /* TODO: SO_UPDATE_ACCEPT_CONTEXT */

    socklen = NGX_SOCKADDRLEN + 16;

    /* TODO: dwReceiveDataLength */

    ngx_getacceptexsockaddrs(buf, 0, socklen, socklen,
                             (LPSOCKADDR *) &local_sa, &local_socklen,
                             (LPSOCKADDR *) &remote_sa, &remote_socklen);

#if (NGX_STAT_STUB)
    (void) ngx_atomic_fetch_add(ngx_stat_accepted, 1);
#endif

    ngx_accept_disabled = ngx_cycle->connection_n / 8
                          - ngx_cycle->free_connection_n;

    ev->log->data = &ls->addr_text;

    c = ngx_get_connection(s, ev->log);

    if (c == NULL) {
        if (ngx_close_socket(s) == -1) {
            ngx_log_error(NGX_LOG_ALERT, ev->log, ngx_socket_errno,
                          ngx_close_socket_n " failed");
        }

        goto post_acceptex;
    }

    c->type = SOCK_STREAM;

#if (NGX_STAT_STUB)
    (void) ngx_atomic_fetch_add(ngx_stat_active, 1);
#endif

    c->pool = ngx_create_pool(ls->pool_size, ev->log);
    if (c->pool == NULL) {
        ngx_close_accepted_connection(c);
        goto post_acceptex;
    }

    c->sockaddr = ngx_palloc(c->pool, remote_socklen);
    if (c->sockaddr == NULL) {
        ngx_close_accepted_connection(c);
        goto post_acceptex;
    }

    ngx_memcpy(c->sockaddr, remote_sa, remote_socklen);

    c->local_sockaddr = ngx_palloc(c->pool, local_socklen);
    if (c->local_sockaddr == NULL) {
        ngx_close_accepted_connection(c);
        goto post_acceptex;
    }

    ngx_memcpy(c->local_sockaddr, local_sa, local_socklen);

    log = ngx_palloc(c->pool, sizeof(ngx_log_t));
    if (log == NULL) {
        ngx_close_accepted_connection(c);
        goto post_acceptex;
    }

    *log = ls->log;

    c->recv = ngx_recv;
    c->send = ngx_send;
    c->recv_chain = ngx_recv_chain;
    c->send_chain = ngx_send_chain;

    c->log = log;
    c->pool->log = log;

    c->socklen = remote_socklen;
    c->local_socklen = local_socklen;
    c->listening = ls;



    rev = c->read;
    wev = c->write;

    wev->ready = 1;
    rev->ready = 0;

    rev->log = log;
    wev->log = log;

    /*
     * TODO: MT: - ngx_atomic_fetch_add()
     *             or protection by critical section or light mutex
     *
     * TODO: MP: - allocated in a shared memory
     *           - ngx_atomic_fetch_add()
     *             or protection by critical section or light mutex
     */

    c->number = ngx_atomic_fetch_add(ngx_connection_counter, 1);

#if (NGX_STAT_STUB)
    (void) ngx_atomic_fetch_add(ngx_stat_handled, 1);
#endif

    if (ls->addr_ntop) {
        c->addr_text.data = ngx_pnalloc(c->pool, ls->addr_text_max_len);
        if (c->addr_text.data == NULL) {
            ngx_close_accepted_connection(c);
            goto post_acceptex;
        }

        c->addr_text.len = ngx_sock_ntop(c->sockaddr, c->socklen, 
                                         c->addr_text.data,
                                         ls->addr_text_max_len, 0);
        if (c->addr_text.len == 0) {
            ngx_close_accepted_connection(c);
            goto post_acceptex;
        }
    }

#if (NGX_DEBUG)
    {
    ngx_str_t  addr;
    u_char     text[NGX_SOCKADDR_STRLEN];

    ngx_debug_accepted_connection(ecf, c);

    if (log->log_level & NGX_LOG_DEBUG_EVENT) {
        addr.data = text;
        addr.len = ngx_sock_ntop(c->sockaddr, c->socklen, text,
                                 NGX_SOCKADDR_STRLEN, 1);

        ngx_log_debug3(NGX_LOG_DEBUG_EVENT, log, 0,
                       "*%uA accept: %V fd:%d", c->number, &addr, s);
    }

    }
#endif

    if (ngx_add_conn) {
        if (ngx_add_conn(c) == NGX_ERROR) {
            ngx_close_accepted_connection(c);
            goto post_acceptex;
        }
    }

    log->data = NULL;
    log->handler = NULL;

    if (c->recv(c, NULL, 0) == NGX_ERROR) {
        ngx_close_accepted_connection(c);
        goto post_acceptex;
    }

    ls->handler(c);

post_acceptex:

    ngx_event_post_one_acceptex(ls, aev);
}


ngx_int_t
ngx_event_post_acceptex(ngx_listening_t *ls, ngx_uint_t n)
{
    ngx_uint_t             i;
    ngx_event_t           *ls_rev, *rev;
    ngx_acceptex_event_t  *events, *ev;

    ls_rev = ls->connection->read;

    events = ngx_alloc(sizeof(ngx_acceptex_event_t) * n, ngx_cycle->log);
    if (events == NULL) {
        return NGX_ERROR;
    }

    for (i = 0; i < n; i++) {
        ev = &events[i];
        rev = &ev->ev;

        ngx_memcpy(rev, ls_rev, sizeof(ngx_event_t));

        rev->ovlp.event = rev;
        rev->wait_handle = INVALID_HANDLE_VALUE;

        rev->event_handle = CreateEvent(NULL, 0, 0, NULL);
        if (!rev->event_handle) {
            ngx_log_error(NGX_LOG_ALERT, rev->log, ngx_errno,
                "ngx_event_post_acceptex CreateEvent() failed");
            return NGX_ERROR;
        }

        if (ngx_event_post_one_acceptex(ls, ev) != NGX_OK) {
            return NGX_ERROR;
        }
    }

    return NGX_OK;
}



static void CALLBACK ngx_post_completion(void* context, BOOLEAN timed_out) {
    ngx_event_t* rev;

    rev = (ngx_event_t*) context;
    if (rev == NULL) {
        ngx_log_error(NGX_LOG_ALERT, rev->log, GetLastError(),
            "post_completion rev == NULL, failed");
        return;
    }

    if (timed_out) {
        ngx_log_error(NGX_LOG_ALERT, rev->log, GetLastError(),
            "post_completion timer == TRUE, failed");
        return;
    }

    if (!PostQueuedCompletionStatus(iocp,
        rev->ovlp.ovlp.InternalHigh, 0,
        &rev->ovlp.ovlp)) {

            ngx_log_error(NGX_LOG_ALERT, rev->log, GetLastError(),
                "PostQueuedCompletionStatus failed");
            return;
    }

    ngx_log_debug0(NGX_LOG_DEBUG_EVENT, rev->log, 0,
        "run ngx_post_completion() success");
}


static ngx_int_t
ngx_event_post_one_acceptex(ngx_listening_t *ls, ngx_acceptex_event_t *aev)
{
    int                rc;
    ngx_err_t          err;
    socklen_t          socklen;
    ngx_event_t       *rev;
    ngx_socket_t       s;
    ngx_connection_t  *c;

    c = ls->connection;
    rev = &aev->ev;

    s = ngx_socket(ls->sockaddr->sa_family, ls->type, 0);
    if (s == -1) {
        ngx_log_error(NGX_LOG_EMERG, ngx_cycle->log, ngx_socket_errno,
            ngx_socket_n " failed");
        return NGX_ERROR;
    }

    if (ngx_nonblocking(s) == -1) {
        ngx_log_error(NGX_LOG_ALERT, ngx_cycle->log, ngx_socket_errno,
            ngx_nonblocking_n " failed");
        ngx_close_socket(s);
        return NGX_ERROR;
    }

    socklen = NGX_SOCKADDRLEN + 16;

    /* TODO: dwReceiveDataLength */
    rev->ovlp.ovlp.hEvent = rev->event_handle;
    rc = ngx_acceptex(c->fd, s, aev->addr_buf, 0, socklen, socklen, NULL,
        (LPOVERLAPPED) &rev->ovlp);

    err = ngx_socket_errno;

    if (rc == 0 && err != WSA_IO_PENDING) {
        ngx_log_error(NGX_LOG_ALERT, ngx_cycle->log, err,
            "ngx_acceptex() failed");
        ngx_close_socket(s);
        return NGX_ERROR;
    }

    rev->log->data = &debug_str; // for debugging ngx_post_completion function
    if (rev->wait_handle == INVALID_HANDLE_VALUE &&
        !RegisterWaitForSingleObject(&(rev->wait_handle),
        rev->event_handle, ngx_post_completion, (void*) rev,
        INFINITE, WT_EXECUTEINWAITTHREAD)) {

            ngx_log_error(NGX_LOG_ALERT, ngx_cycle->log, GetLastError(),
                "RegisterWaitForSingleObject() failed");
            return NGX_ERROR;
    }

    aev->fd = s;

    return NGX_OK;
}


static void
ngx_close_accepted_connection(ngx_connection_t *c)
{
    ngx_socket_t  fd;

    ngx_free_connection(c);

    fd = c->fd;
    c->fd = (ngx_socket_t) -1;

    if (ngx_close_socket(fd) == -1) {
        ngx_log_error(NGX_LOG_ALERT, c->log, ngx_socket_errno,
            ngx_close_socket_n " failed");
    }

    if (c->pool) {
        ngx_destroy_pool(c->pool);
    }

#if (NGX_STAT_STUB)
    (void) ngx_atomic_fetch_add(ngx_stat_active, -1);
#endif
}


u_char *
ngx_acceptex_log_error(ngx_log_t *log, u_char *buf, size_t len)
{
    return ngx_snprintf(buf, len, " while accepting new connection on %V",
        log->data);
}

#if (NGX_DEBUG)

static void
ngx_debug_accepted_connection(ngx_event_conf_t *ecf, ngx_connection_t *c)
{
    struct sockaddr_in   *sin;
    ngx_cidr_t           *cidr;
    ngx_uint_t            i;
#if (NGX_HAVE_INET6)
    struct sockaddr_in6  *sin6;
    ngx_uint_t            n;
#endif

    cidr = ecf->debug_connection.elts;
    for (i = 0; i < ecf->debug_connection.nelts; i++) {
        if (cidr[i].family != (ngx_uint_t) c->sockaddr->sa_family) {
            goto next;
        }

        switch (cidr[i].family) {

#if (NGX_HAVE_INET6)
        case AF_INET6:
            sin6 = (struct sockaddr_in6 *) c->sockaddr;
            for (n = 0; n < 16; n++) {
                if ((sin6->sin6_addr.s6_addr[n]
                & cidr[i].u.in6.mask.s6_addr[n])
                    != cidr[i].u.in6.addr.s6_addr[n])
                {
                    goto next;
                }
            }
            break;
#endif

#if (NGX_HAVE_UNIX_DOMAIN)
        case AF_UNIX:
            break;
#endif

        default: /* AF_INET */
            sin = (struct sockaddr_in *) c->sockaddr;
            if ((sin->sin_addr.s_addr & cidr[i].u.in.mask)
                != cidr[i].u.in.addr)
            {
                goto next;
            }
            break;
        }

        c->log->log_level = NGX_LOG_DEBUG_CONNECTION|NGX_LOG_DEBUG_ALL;
        break;

next:
        continue;
    }
}

#endif
