
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


ssize_t
ngx_wsarecv(ngx_connection_t *c, u_char *buf, size_t size)
{
    int           rc;
    u_long        bytes, flags;
    WSABUF        wsabuf[1];
    ngx_err_t     err;
    ngx_int_t     n;
    ngx_event_t  *rev;

    wsabuf[0].buf = (char *) buf;
    wsabuf[0].len = size;
    flags = 0;
    bytes = 0;

    rc = WSARecv(c->fd, wsabuf, 1, &bytes, &flags, NULL, NULL);

    ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, 0,
                   "WSARecv: fd:%d rc:%d %ul of %z", c->fd, rc, bytes, size);

    rev = c->read;

    if (rc == -1) {
        rev->ready = 0;
        err = ngx_socket_errno;

        if (err == WSAEWOULDBLOCK) {
            ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err,
                           "WSARecv() not ready");
            return NGX_AGAIN;
        }

        n = ngx_connection_error(c, err, "WSARecv() failed");

        if (n == NGX_ERROR) {
            rev->error = 1;
        }

        return n;
    }

    if (bytes < size) {
        rev->ready = 0;
    }

    if (bytes == 0) {
        rev->eof = 1;
    }

    return bytes;
}


ssize_t
ngx_post_overlapped_wsarecv(ngx_connection_t *c, u_char *buf, size_t size) 
{
    int             flags, rc;
    WSABUF          wsabuf;
    ssize_t         n;
    ngx_err_t       err;
    ngx_event_t    *rev;
    WSAOVERLAPPED  *ovlp;

    rev = c->read;

    if (rev->eof || rev->closed) {
        return 0;
    }

    if (rev->error) {
        return NGX_ERROR;
    }

retry:
    ovlp = (WSAOVERLAPPED *) &rev->ovlp;

    wsabuf.buf = NULL;
    wsabuf.len = 0;

    n = 0;
    flags = 0;

    if (c->type == SOCK_DGRAM) {
        flags = MSG_PEEK;
    }

    rc = WSARecv(c->fd, &wsabuf, 1, (DWORD *) &n, (LPDWORD) &flags, ovlp, NULL);

    ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "iocp post WSARecv: fd:%d rc:%d %ul of %z", c->fd, rc, n, size);

    err = ngx_socket_errno;

    if (rc == 0) {
        if (ngx_win32_version >= NGX_WIN32_VER_600) {
            if ((buf == NULL) && (size == 0)) {
                ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "iocp post WSARecv() success, need to call PostQueuedCompletionStatus!");

                if (!PostQueuedCompletionStatus(iocp,
                    0, c->number,
                    &rev->ovlp.ovlp)) 
                {
                    err = ngx_socket_errno;
                    ngx_log_error(NGX_LOG_ALERT, rev->log, err, "iocp call PostQueuedCompletionStatus() failed");
                    return NGX_ERROR;
                }

                ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp call PostQueuedCompletionStatus() success!");

                rev->ovlp.posted_zero_byte = 1;
                rev->ready = 0;
                c->ovlp_count++;
                ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp ovlp_count fd: %d, count: %ul", c->fd, c->ovlp_count);

                return NGX_AGAIN;
            }


            ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "iocp post WSARecv() success");

            rev->ovlp.posted_zero_byte = 0;
            rev->ready = 1;

            return NGX_OK;
        }

        rev->ovlp.posted_zero_byte = 1;
        rev->ready = 0;
        c->ovlp_count++;
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp post WSARecv() success, ovlp_count fd: %d, count: %ul", c->fd, c->ovlp_count);
        return NGX_AGAIN;
    }

    if (err == WSA_IO_PENDING) {
        rev->ovlp.posted_zero_byte = 1;
        rev->ready = 0;
        c->ovlp_count++;
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp post WSARecv() not ready, ovlp_count fd: %d, count: %ul", c->fd, c->ovlp_count);

        return NGX_AGAIN;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "iocp post WSARecv() not ready retry");

        /* post another overlapped-io WSARecv() */
        rev->ovlp.posted_zero_byte = 0;
        goto retry;
    }

    ngx_connection_error(c, err, "iocp post WSARecv() failed");

    rev->ready = 0;
    rev->error = 1;

    return NGX_ERROR;
}

ssize_t
ngx_overlapped_wsarecv(ngx_connection_t *c, u_char *buf, size_t size)
{
    int             flags, rc;
    WSABUF          wsabuf;
    ssize_t         n;
    ngx_err_t       err;
    ngx_event_t    *rev;
    WSAOVERLAPPED  *ovlp;

    rev = c->read;

    if (rev->eof || rev->closed) {
        return NGX_AGAIN;
    }

    if (rev->error) {
        return NGX_ERROR;
    }

    if (rev->ready == 0){
        if (rev->ovlp.posted_zero_byte == 0) {
            rc = ngx_post_overlapped_wsarecv(c, buf, size);
            if (rc != NGX_OK) {
                return rc;
            }
        } else {
            ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, 0,
                "iocp WSARecv() is already post: fd:%d", c->fd);
            return NGX_AGAIN;
        }
    }


retry:
    ovlp = NULL;

    wsabuf.buf = (CHAR *) buf;
    wsabuf.len = (ULONG) size;

    n = 0;
    flags = 0;

    rc = WSARecv(c->fd, &wsabuf, 1, (DWORD *) &n, (LPDWORD) &flags, ovlp, NULL);

    ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "iocp WSARecv: fd:%d rc:%d %ul of %z", c->fd, rc, n, size);

    err = ngx_socket_errno;

    if (rc == 0) {
        if (c->type != SOCK_DGRAM) {
            if (n == 0) {
                rev->eof = 1;
            }

            if ((size_t) n < size) {
                ngx_post_overlapped_wsarecv(c, NULL, 0);
            }
        }

        return n;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "iocp WSARecv() not ready retry");
        return ngx_post_overlapped_wsarecv(c, NULL, 0);
    }

    ngx_connection_error(c, err, "iocp WSARecv() failed");

    rev->ready = 0;
    rev->error = 1;

    return NGX_ERROR;
}

