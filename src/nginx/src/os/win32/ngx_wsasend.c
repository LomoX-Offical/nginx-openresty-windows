
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
    u_long          sent;
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

    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "finish WSASend: fd:%d, sent %ul bytes", c->fd, wev->available);

    if (!wev->ready) {
        ngx_connection_error(c, 0, "WSASend() is already post");
        return NGX_AGAIN;
    }

retry:

    ovlp = (WSAOVERLAPPED *) &wev->ovlp;

    /* non-blocking io */

    wsabuf.buf = (CHAR *) buf;
    wsabuf.len = (ULONG) size;

    sent = 0;

    rc = WSASend(c->fd, &wsabuf, 1, (DWORD *) &sent, 0, ovlp, NULL);
    ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "WSASend: fd:%d, %d, %ul of %uz", c->fd, rc, sent, size);

    err = ngx_socket_errno;

    if (rc == 0) {
        if (ngx_win32_version >= NGX_WIN32_VER_600) {
            ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "iocp post WSASend() success");

            wev->ovlp.posted_zero_byte = 0;
            wev->ready = 1;
            c->sent += size;
            return size;
        }

        wev->ovlp.posted_zero_byte = 1;
        wev->ready = 0;
        c->sent += size;
        c->ovlp_count++;
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp post WSASend() success, ovlp_count fd: %d, count: %ul", c->fd, c->ovlp_count);

        return size;
    }

    if (err == WSA_IO_PENDING) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "Post WSASend() not ready");
        wev->ovlp.posted_zero_byte = 1;
        wev->ready = 0;
        c->sent += size;
        c->ovlp_count++;
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp post WSASend() not ready, ovlp_count fd: %d, count: %ul", c->fd, c->ovlp_count);

        return size;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "iocp post WSASend() not ready, retry");

        wev->ovlp.posted_zero_byte = 0;
        goto retry;
    }

    ngx_connection_error(c, err, "iocp post WSASend() failed");

    wev->ovlp.posted_zero_byte = 0;
    wev->ready = 0;
    wev->error = 1;

    return NGX_ERROR;
}