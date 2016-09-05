
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


    if (c->type == SOCK_DGRAM) {
        return ngx_wsasend(c, buf, size);
    }

    wev = c->write;

    if (wev->closed) {
        return 0;
    }

    if (wev->error) {
        return NGX_ERROR;
    }

    if (wev->ovlp.is_connecting) {
        ngx_log_debug3(NGX_LOG_DEBUG_EVENT, c->log, 0,
            "connected successfully: fd:%d, sent %ul bytes, is_connecting is %d", c->fd, wev->available, wev->ovlp.is_connecting);
        if (c->recv(c, NULL, 0) == NGX_ERROR) {
            err = ngx_socket_errno;
            ngx_connection_error(c, err, "post recv failed after connected successfully");
            return NGX_CHAIN_ERROR;
        }
        wev->ovlp.is_connecting = 0;
        wev->ovlp.posted_zero_byte = 0;
    } else {
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
            "finish WSASend: fd:%d, sent %ul bytes", c->fd, wev->available);
    }

    if (!wev->ready) {
        ngx_connection_error(c, 0, "WSASend() is already post");
        return NGX_AGAIN;
    }

retry:

    ovlp = (WSAOVERLAPPED *) &wev->ovlp;

    /* non-blocking io */

    wsabuf.buf = (CHAR *) buf;
    wsabuf.len = (ULONG) size;

    n = 0;

    rc = WSASend(c->fd, &wsabuf, 1, (DWORD *) &n, 0, ovlp, NULL);
    ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "WSASend: fd:%d, %d, %ul of %uz", c->fd, rc, n, size);

    err = ngx_socket_errno;

    if (rc == 0) {
        wev->ovlp.posted_zero_byte = 1;
        wev->ready = 0;
        return size;
    }

    if (err == WSA_IO_PENDING) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "Post WSASend() not ready");
        wev->ovlp.posted_zero_byte = 1;
        wev->ready = 0;
        return NGX_AGAIN;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "Post WSASend() not ready, retry");

        wev->ovlp.posted_zero_byte = 0;
        goto retry;
    }

    ngx_connection_error(c, err, "Post WSASend() failed");

    wev->ovlp.posted_zero_byte = 0;
    wev->ready = 0;
    wev->error = 1;

    return NGX_ERROR;
}