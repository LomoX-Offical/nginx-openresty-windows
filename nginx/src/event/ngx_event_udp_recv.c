
/*
 * Copyright (C) Ngwsx
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


typedef struct {
    ngx_event_t     event;
    ngx_pool_t     *pool;
    ngx_buf_t      *buffer;
    u_char          sockaddr[NGX_SOCKADDRLEN];
    socklen_t       socklen;
} ngx_udp_recv_event_t;


#if (NGX_WIN32)
static ngx_int_t ngx_event_post_one_udp_recv(ngx_listening_t *ls,
    ngx_udp_recv_event_t *event);
#endif
static void ngx_close_udp_connection(ngx_connection_t *c);


void
ngx_event_udp_recv(ngx_event_t *ev)
{
    u_char                *buf;
    size_t                 size;
    ssize_t                n;
    ngx_listening_t       *ls;
    ngx_connection_t      *lc;
    ngx_udp_recv_event_t   event;

    lc = ev->data;
    ls = lc->listening;

    ngx_memcpy(&event.event, ev, sizeof(ngx_event_t));

    event.pool = ngx_create_pool(ls->pool_size, ngx_cycle->log);
    if (event.pool == NULL) {
        return;
    }

    event.buffer = ngx_create_temp_buf(event.pool, ls->udp_recv_buffer_size);
    if (event.buffer == NULL) {
        ngx_destroy_pool(event.pool);
        return;
    }

    buf = event.buffer->last;
    size = event.buffer->end - event.buffer->last;

    event.socklen = NGX_SOCKADDRLEN;

#if (NGX_UDT)
    n = ngx_recvfrom(lc->fd, (char *) buf, size, 0,
                     (struct sockaddr *) event.sockaddr, &event.socklen);
#else
    n = recvfrom(lc->fd, (char *) buf, size, 0,
                 (struct sockaddr *) event.sockaddr, &event.socklen);
#endif

    if (n == -1) {
#if (NGX_UDT)
        ngx_log_error(NGX_LOG_ALERT, ev->log, ngx_socket_errno,
                      "ngx_recvfrom() failed");
#else
        ngx_log_error(NGX_LOG_ALERT, ev->log, ngx_socket_errno,
                      "recvfrom() failed");
#endif
        ngx_destroy_pool(event.pool);
        return;
    }

    event.buffer->last += n;

    ngx_event_udp_aio_recv((ngx_event_t *) &event);
}


void
ngx_event_udp_aio_recv(ngx_event_t *ev)
{
    ngx_udp_recv_event_t *event = (ngx_udp_recv_event_t *) ev;

    ngx_log_t         *log;
    ngx_event_t       *rev, *wev;
    ngx_listening_t   *ls;
    ngx_connection_t  *c, *lc;

    ev->ready = 0;

    lc = ev->data;
    ls = lc->listening;

    if (ev->error) {
        ngx_destroy_pool(event->pool);
        goto post_udp_recv;
    }

#if (NGX_STAT_STUB)
    (void) ngx_atomic_fetch_add(ngx_stat_accepted, 1);
#endif

    ev->log->data = &ls->addr_text;

    c = ngx_get_connection(lc->fd, ev->log);

    if (c == NULL) {
        ngx_destroy_pool(event->pool);
        goto post_udp_recv;
    }

#if (NGX_STAT_STUB)
    (void) ngx_atomic_fetch_add(ngx_stat_active, 1);
#endif

    c->pool = event->pool;
    c->buffer = event->buffer;

#if (NGX_WIN32) && (NGX_HAVE_IOCP)
    if (ngx_event_flags & NGX_USE_IOCP_EVENT) {
        c->buffer->last += ev->available;
        ev->available = 0;
    }
#endif

    c->sockaddr = ngx_palloc(c->pool, event->socklen);
    if (c->sockaddr == NULL) {
        ngx_close_udp_connection(c);
        goto post_udp_recv;
    }

    ngx_memcpy(c->sockaddr, event->sockaddr, event->socklen);

    log = ngx_palloc(c->pool, sizeof(ngx_log_t));
    if (log == NULL) {
        ngx_close_udp_connection(c);
        goto post_udp_recv;
    }

    *log = ls->log;

    c->recv = ngx_recv;
    c->send = ngx_send;
    c->recv_chain = ngx_recv_chain;
    c->send_chain = ngx_send_chain;

    c->log = log;
    c->pool->log = log;

    c->socklen = event->socklen;
    c->listening = ls;
    c->local_sockaddr = ls->sockaddr;

    c->unexpected_eof = 1;

#if (NGX_HAVE_UNIX_DOMAIN)
    if (c->sockaddr->sa_family == AF_UNIX) {
        c->tcp_nopush = NGX_TCP_NOPUSH_DISABLED;
        c->tcp_nodelay = NGX_TCP_NODELAY_DISABLED;
    }
#endif

    rev = c->read;
    wev = c->write;

    wev->ready = 1;

    if (ngx_event_flags & (NGX_USE_AIO_EVENT|NGX_USE_RTSIG_EVENT)) {
        /* rtsig, aio, iocp */
        rev->ready = 1;
    }

    if (ev->deferred_accept) {
        rev->ready = 1;
    }

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

#if (NGX_THREADS)
    rev->lock = &c->lock;
    wev->lock = &c->lock;
    rev->own_lock = &c->lock;
    wev->own_lock = &c->lock;
#endif

    if (ls->addr_ntop) {
        c->addr_text.data = ngx_pnalloc(c->pool,
                                  ls->addr_text_max_len + sizeof(":65535") - 1);
        if (c->addr_text.data == NULL) {
            ngx_close_udp_connection(c);
            goto post_udp_recv;
        }

        c->addr_text.len = ngx_sock_ntop(c->sockaddr, c->addr_text.data,
                               ls->addr_text_max_len + sizeof(":65535") - 1, 1);
        if (c->addr_text.len == 0) {
            ngx_close_udp_connection(c);
            goto post_udp_recv;
        }
    }

#if (NGX_DEBUG)
    {
    in_addr_t            i;
    ngx_event_conf_t    *ecf;
    ngx_event_debug_t   *dc;
    struct sockaddr_in  *sin;

    sin = (struct sockaddr_in *) c->sockaddr;

    ecf = ngx_event_get_conf(ngx_cycle->conf_ctx, ngx_event_core_module);

    dc = ecf->debug_connection.elts;
    for (i = 0; i < ecf->debug_connection.nelts; i++) {
        if ((sin->sin_addr.s_addr & dc[i].mask) == dc[i].addr) {
            log->log_level = NGX_LOG_DEBUG_CONNECTION|NGX_LOG_DEBUG_ALL;
            break;
        }
    }
    }
#endif

    log->data = NULL;
    log->handler = NULL;

    ls->handler(c);

post_udp_recv:

#if (NGX_WIN32)

    if (ngx_event_flags & NGX_USE_IOCP_EVENT) {
        ngx_event_post_one_udp_recv(ls, event);
    }

#endif

    return;
}


#if (NGX_WIN32)

ngx_int_t
ngx_event_post_udp_recv(ngx_listening_t *ls, ngx_uint_t n)
{
    ngx_uint_t             i;
    ngx_udp_recv_event_t  *udp_events, *ev;

    udp_events = ngx_alloc(sizeof(ngx_udp_recv_event_t) * n, ngx_cycle->log);
    if (udp_events == NULL) {
        return NGX_ERROR;
    }

    for (i = 0; i < n; i++) {
        ev = &udp_events[i];

        ngx_memcpy(&ev->event, ls->connection->read, sizeof(ngx_event_t));

        ev->event.ovlp.event = &ev->event;

        if (ngx_event_post_one_udp_recv(ls, ev) != NGX_OK) {
            return NGX_ERROR;
        }
    }

    return NGX_OK;
}


static ngx_int_t
ngx_event_post_one_udp_recv(ngx_listening_t *ls, ngx_udp_recv_event_t *event)
{
    int        rc;
    DWORD      flags;
    WSABUF     wsabuf;
    ngx_err_t  err;

    event->pool = ngx_create_pool(ls->pool_size, ngx_cycle->log);
    if (event->pool == NULL) {
        return NGX_ERROR;
    }

    event->buffer = ngx_create_temp_buf(event->pool, ls->udp_recv_buffer_size);
    if (event->buffer == NULL) {
        ngx_destroy_pool(event->pool);
        return NGX_ERROR;
    }

    wsabuf.buf = (CHAR *) event->buffer->last;
    wsabuf.len = (DWORD) (event->buffer->end - event->buffer->last);

    flags = 0;

    event->socklen = NGX_SOCKADDRLEN;

    rc = WSARecvFrom(ls->connection->fd, &wsabuf, 1, NULL, &flags,
                     (struct sockaddr *) event->sockaddr,
                     (LPINT) &event->socklen,
                     (LPWSAOVERLAPPED) &event->event.ovlp, NULL);

    err = ngx_socket_errno;

    if (rc == SOCKET_ERROR && err != WSA_IO_PENDING) {
        ngx_log_error(NGX_LOG_ALERT, ngx_cycle->log, err,
                      "WSARecvFrom() failed");
        return NGX_ERROR;
    }

    return NGX_OK;
}

#endif


static void
ngx_close_udp_connection(ngx_connection_t *c)
{
    ngx_free_connection(c);

    if (c->pool) {
        ngx_destroy_pool(c->pool);
    }

#if (NGX_STAT_STUB)
    (void) ngx_atomic_fetch_add(ngx_stat_active, -1);
#endif
}
