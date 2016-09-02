
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


#define NGX_WSABUFS  8


ngx_chain_t *
ngx_wsasend_chain(ngx_connection_t *c, ngx_chain_t *in, off_t limit)
{
    int           rc;
    u_char       *prev;
    u_long        size, sent, send, prev_send;
    ngx_err_t     err;
    ngx_event_t  *wev;
    ngx_array_t   vec;
    ngx_chain_t  *cl;
    LPWSABUF      wsabuf;
    WSABUF        wsabufs[NGX_WSABUFS];

    wev = c->write;

    if (!wev->ready) {
        return in;
    }

    /* the maximum limit size is the maximum u_long value - the page size */

    if (limit == 0 || limit > (off_t) (NGX_MAX_UINT32_VALUE - ngx_pagesize)) {
        limit = NGX_MAX_UINT32_VALUE - ngx_pagesize;
    }

    send = 0;

    /*
     * WSABUFs must be 4-byte aligned otherwise
     * WSASend() will return undocumented WSAEINVAL error.
     */

    vec.elts = wsabufs;
    vec.size = sizeof(WSABUF);
    vec.nalloc = NGX_WSABUFS;
    vec.pool = c->pool;

    for ( ;; ) {
        prev = NULL;
        wsabuf = NULL;
        prev_send = send;

        vec.nelts = 0;

        /* create the WSABUF and coalesce the neighbouring bufs */

        for (cl = in;
             cl && vec.nelts < ngx_max_wsabufs && send < limit;
             cl = cl->next)
        {
            if (ngx_buf_special(cl->buf)) {
                continue;
            }

            size = cl->buf->last - cl->buf->pos;

            if (send + size > limit) {
                size = (u_long) (limit - send);
            }

            if (prev == cl->buf->pos) {
                wsabuf->len += cl->buf->last - cl->buf->pos;

            } else {
                wsabuf = ngx_array_push(&vec);
                if (wsabuf == NULL) {
                    return NGX_CHAIN_ERROR;
                }

                wsabuf->buf = (char *) cl->buf->pos;
                wsabuf->len = cl->buf->last - cl->buf->pos;
            }

            prev = cl->buf->last;
            send += size;
        }

        sent = 0;

        rc = WSASend(c->fd, vec.elts, vec.nelts, &sent, 0, NULL, NULL);

        if (rc == -1) {
            err = ngx_errno;

            if (err == WSAEWOULDBLOCK) {
                ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err,
                               "WSASend() not ready");

            } else {
                wev->error = 1;
                ngx_connection_error(c, err, "WSASend() failed");
                return NGX_CHAIN_ERROR;
            }
        }

        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
                       "WSASend chain: fd:%d, s:%ul", c->fd, sent);

        c->sent += sent;

        in = ngx_chain_update_sent(in, sent);

        if (send - prev_send != sent) {
            wev->ready = 0;
            return in;
        }

        if (send >= limit || in == NULL) {
            return in;
        }
    }
}

#if (IOV_MAX > 64)
#define NGX_IOVS  64
#else
#define NGX_IOVS  IOV_MAX
#endif

ngx_chain_t *
ngx_post_overlapped_wsasend_chain(ngx_connection_t *c, ngx_chain_t *in, off_t limit)
{
    int             rc;
    off_t           size, send;
    u_char         *prev;
    WSABUF         *buf, bufs[NGX_IOVS];
    ssize_t         n;
    ngx_err_t       err;
    ngx_array_t     vec;
    ngx_chain_t    *cl;
    ngx_event_t    *wev;
    WSAOVERLAPPED  *ovlp;

    wev = c->write;

    if (wev->closed) {
        return NULL;
    }

    if (wev->error) {
        return NGX_CHAIN_ERROR;
    }

retry:

    vec.nelts = 0;
    vec.elts = bufs;
    vec.size = sizeof(WSABUF);
    vec.nalloc = NGX_IOVS;
    vec.pool = c->pool;


    ovlp = (WSAOVERLAPPED *) &wev->ovlp;

    /* non-blocking io */

    /* the maximum limit size is the maximum size_t value - the page size */

    if (limit == 0 || limit > (off_t) (NGX_MAX_SIZE_T_VALUE - ngx_pagesize))
    {
        limit = NGX_MAX_SIZE_T_VALUE - (off_t) ngx_pagesize;
    }

    /* create the WSABUF and coalesce the neighbouring bufs */

    prev = NULL;
    buf = NULL;
    send = 0;

    for (cl = in; cl && vec.nelts < NGX_IOVS && send < limit; cl = cl->next)
    {
        if (ngx_buf_special(cl->buf)) {
            continue;
        }

        size = (off_t) (cl->buf->last - cl->buf->pos);

        if (send + size > limit) {
            size = limit - send;
        }

        if (prev == cl->buf->pos) {
            buf->len += (ULONG) size;

        } else {
            buf = ngx_array_push(&vec);
            if (buf == NULL) {
                return NGX_CHAIN_ERROR;
            }

            buf->buf = (CHAR *) cl->buf->pos;
            buf->len = (ULONG) size;
        }

        send += size;
        prev = cl->buf->pos + size;
    }

    n = 0;

    rc = WSASend(c->fd, vec.elts, (DWORD) vec.nelts, (DWORD *) &n, 0, ovlp, NULL);

    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "Post WSASend chain: fd:%d, s:%ul", c->fd, n);

    err = ngx_socket_errno;

    if (rc == 0) {
        wev->ovlp.posted_zero_byte = 1;
        wev->ready = 0;
        return in;
    }

    if (err == WSA_IO_PENDING) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "Post WSASend() not ready");
        wev->ovlp.posted_zero_byte = 1;
        wev->ready = 0;
        return in;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "Post WSASend() not ready, retry");

        /* post another overlapped-io WSASend() */
        wev->ovlp.posted_zero_byte = 0;
        goto retry;
    }

    ngx_connection_error(c, err, "Post WSASend() failed");

    wev->ovlp.posted_zero_byte = 0;
    wev->ready = 0;
    wev->error = 1;

    return NGX_CHAIN_ERROR;
}


ngx_chain_t *
ngx_overlapped_wsasend_chain(ngx_connection_t *c, ngx_chain_t *in, off_t limit)
{
    int             rc;
    off_t           size, send;
    u_char         *prev;
    WSABUF         *buf, bufs[NGX_IOVS];
    ssize_t         n;
    ngx_err_t       err;
    ngx_array_t     vec;
    ngx_chain_t    *cl;
    ngx_event_t    *wev;
    WSAOVERLAPPED  *ovlp;

    wev = c->write;

    if (wev->closed) {
        return NULL;
    }

    if (wev->error) {
        return NGX_CHAIN_ERROR;
    }

    if (wev->ovlp.is_connecting) {
        ngx_log_debug3(NGX_LOG_DEBUG_EVENT, c->log, 0,
            "connected successfully: fd:%d, sent %ul bytes, is_connecting is %d", c->fd, wev->available, wev->ovlp.is_connecting);
        wev->ovlp.is_connecting = 0;
        wev->ovlp.posted_zero_byte = 0;
    }

retry:

    if (wev->ovlp.posted_zero_byte == 0) {
        return ngx_post_overlapped_wsasend_chain(c, in, limit);
    }

    if (wev->ready == 0) {
        ngx_connection_error(c, 0, "WSASend() chain is already post");
        return in;
    }

    n = wev->available;
    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "finish WSASend chain: fd:%d, sent %ul bytes", c->fd, n);

    c->sent += (off_t) n;

    for (cl = in; cl; cl = cl->next) {

        if (ngx_buf_special(cl->buf)) {
            continue;
        }

        if (n == 0) {
            break;
        }

        size = (off_t) (cl->buf->last - cl->buf->pos);

        if (n >= size) {
            n -= (ssize_t) size;
            cl->buf->pos = cl->buf->last;

            continue;
        }

        cl->buf->pos += n;

        break;
    }

    wev->ovlp.posted_zero_byte = 0;
    wev->ready = 1;

    if (cl != NULL) {
        in = cl;
        goto retry;
    }

    return cl;
}


