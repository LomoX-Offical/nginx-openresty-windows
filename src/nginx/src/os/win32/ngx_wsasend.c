
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


ssize_t
ngx_wsasend(ngx_connection_t *c, u_char *buf, size_t size)
{
    int           n;
    u_long        sent;
    ngx_err_t     err;
    ngx_event_t  *wev;
    WSABUF        wsabuf;

    wev = c->write;

    if (!wev->ready) {
        return NGX_AGAIN;
    }

    /*
     * WSABUF must be 4-byte aligned otherwise
     * WSASend() will return undocumented WSAEINVAL error.
     */

    wsabuf.buf = (char *) buf;
    wsabuf.len = size;

    sent = 0;

    n = WSASend(c->fd, &wsabuf, 1, &sent, 0, NULL, NULL);

    ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, 0,
                   "WSASend: fd:%d, %d, %ul of %uz", c->fd, n, sent, size);

    if (n == 0) {
        if (sent < size) {
            wev->ready = 0;
        }

        c->sent += sent;

        return sent;
    }

    err = ngx_socket_errno;

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "WSASend() not ready");
        wev->ready = 0;
        return NGX_AGAIN;
    }

    wev->error = 1;
    ngx_connection_error(c, err, "WSASend() failed");

    return NGX_ERROR;
}

ssize_t
ngx_overlapped_wsasend(ngx_connection_t *c, u_char *buf, size_t size)
{
    int             rc;
    WSABUF          wsabuf;
    ssize_t         n;
    ngx_err_t       err;
    ngx_event_t    *wev;
    WSAOVERLAPPED  *ovlp;

    wev = c->write;

    if (wev->closed) {
        return 0;
    }

    if (wev->error) {
        return NGX_ERROR;
    }

retry:

    if (ngx_event_flags & NGX_USE_IOCP_EVENT && !wev->ovlp.posted_zero_byte) {
        ovlp = (WSAOVERLAPPED *) &wev->ovlp;

        /* overlapped io */

        wsabuf.buf = NULL;
        wsabuf.len = 0;

    } else {
        ovlp = NULL;

        /* non-blocking io */

        wsabuf.buf = (CHAR *) buf;
        wsabuf.len = (ULONG) size;
    }

    n = 0;

    rc = WSASend(c->fd, &wsabuf, 1, (DWORD *) &n, 0, ovlp, NULL);
    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "WSASend: fd:%d, s:%ul", c->fd, n);

    err = ngx_socket_errno;

    if (rc == 0) {
        if (ovlp != NULL) {
            wev->ovlp.posted_zero_byte = 1;
            wev->ready = 0;
            return NGX_AGAIN;
        }

#if 0
        if ((size_t) n < size) {
            wev->ready = 0;
        }
#endif

        wev->ovlp.posted_zero_byte = 0;

        return n;
    }

    if (err == WSA_IO_PENDING) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "WSASend() not ready");
        wev->ovlp.posted_zero_byte = 1;
        wev->ready = 0;
        return NGX_AGAIN;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "WSASend() not ready");

        if ((ngx_event_flags & NGX_USE_IOCP_EVENT) == 0) {
            wev->ready = 0;
            return NGX_AGAIN;
        }

        /* post another overlapped-io WSASend() */
        wev->ovlp.posted_zero_byte = 0;
        goto retry;
    }

    ngx_connection_error(c, err, "WSASend() failed");

    wev->ready = 0;
    wev->error = 1;

    return NGX_ERROR;
}