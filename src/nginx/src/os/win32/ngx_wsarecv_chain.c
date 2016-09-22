
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


#define NGX_WSABUFS  8


ssize_t
ngx_wsarecv_chain(ngx_connection_t *c, ngx_chain_t *chain, off_t limit)
{
    int           rc;
    u_char       *prev;
    u_long        bytes, flags;
    size_t        n, size;
    ngx_err_t     err;
    ngx_array_t   vec;
    ngx_event_t  *rev;
    LPWSABUF      wsabuf;
    WSABUF        wsabufs[NGX_WSABUFS];

    prev = NULL;
    wsabuf = NULL;
    flags = 0;
    size = 0;
    bytes = 0;

    vec.elts = wsabufs;
    vec.nelts = 0;
    vec.size = sizeof(WSABUF);
    vec.nalloc = NGX_WSABUFS;
    vec.pool = c->pool;

    /* coalesce the neighbouring bufs */

    while (chain) {
        n = chain->buf->end - chain->buf->last;

        if (limit) {
            if (size >= (size_t) limit) {
                break;
            }

            if (size + n > (size_t) limit) {
                n = (size_t) limit - size;
            }
        }

        if (prev == chain->buf->last) {
            wsabuf->len += n;

        } else {
            wsabuf = ngx_array_push(&vec);
            if (wsabuf == NULL) {
                return NGX_ERROR;
            }

            wsabuf->buf = (char *) chain->buf->last;
            wsabuf->len = n;
        }

        size += n;
        prev = chain->buf->end;
        chain = chain->next;
    }

    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
                   "WSARecv: %d:%d", vec.nelts, wsabuf->len);


    rc = WSARecv(c->fd, vec.elts, vec.nelts, &bytes, &flags, NULL, NULL);

    rev = c->read;

    if (rc == -1) {
        rev->ready = 0;
        err = ngx_socket_errno;

        if (err == WSAEWOULDBLOCK) {
            ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err,
                           "WSARecv() not ready");
            return NGX_AGAIN;
        }

        rev->error = 1;
        ngx_connection_error(c, err, "WSARecv() failed");
        return NGX_ERROR;
    }

    if (bytes < size) {
        rev->ready = 0;
    }

    if (bytes == 0) {
        rev->eof = 1;
    }

    return bytes;
}

#define NGX_IOVS  16


ssize_t
ngx_post_overlapped_wsarecv_chain(ngx_connection_t *c, ngx_chain_t *chain, off_t limit)
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

    ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "Post WSARecv chain: fd:%d rc:%d", c->fd, rc);

    err = ngx_socket_errno;

    if (rc == 0) {
        if (ngx_win32_version >= NGX_WIN32_VER_600) {
            ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "iocp post WSARecv() chain success");

            rev->ovlp.posted_zero_byte = 0;
            rev->ready = 1;

            return NGX_OK;
        }

        rev->ovlp.posted_zero_byte = 1;
        rev->ready = 0;
        c->ovlp_count++;
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp post WSARecv() chain success, ovlp_count fd: %d, count: %ul", c->fd, c->ovlp_count);
        return NGX_AGAIN;
    }

    if (err == WSA_IO_PENDING) {
        rev->ovlp.posted_zero_byte = 1;
        rev->ready = 0;
        c->ovlp_count++;
        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0, "iocp post WSARecv() chain not ready, ovlp_count fd: %d, count: %ul", c->fd, c->ovlp_count);

        return NGX_AGAIN;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "iocp post WSARecv() chain not ready retry");

        /* post another overlapped-io WSARecv() */
        rev->ovlp.posted_zero_byte = 0;
        goto retry;
    }

    ngx_connection_error(c, err, "iocp post WSARecv() chain failed");

    rev->ready = 0;
    rev->error = 1;

    return NGX_ERROR;
}


ssize_t
ngx_overlapped_wsarecv_chain(ngx_connection_t *c, ngx_chain_t *chain, off_t limit)
{
    int             flags, rc;
    u_char         *prev;
    WSABUF         *buf, bufs[NGX_IOVS];
    size_t          size;
    ssize_t         n;
    ngx_err_t       err;
    ngx_array_t     vec;
    ngx_chain_t    *cl;
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
            rc = ngx_post_overlapped_wsarecv_chain(c, chain, limit);
            if (rc != NGX_OK) {
                return rc;
            }
        }
        ngx_connection_error(c, 0, "WSARecv() chain is already post");
        return NGX_AGAIN;
    }


retry:

    vec.nelts = 0;
    vec.elts = bufs;
    vec.size = sizeof(WSABUF);
    vec.nalloc = NGX_IOVS;
    vec.pool = c->pool;

    ovlp = NULL;

    cl = chain;
    prev = NULL;
    buf = NULL;
    size = 0;

    /* coalesce the neighbouring bufs */

    while (cl && vec.nelts < NGX_IOVS) {
        n = (cl->buf->end - cl->buf->last);

        if (limit) {
            if (size >= (size_t) limit) {
                break;
            }

            if (size + n > (size_t) limit) {
                n = (size_t) limit - size;
            }
        }

        if (prev == cl->buf->last) {
            buf->len += (DWORD) n;

        } else {
            buf = ngx_array_push(&vec);
            if (buf == NULL) {
                return NGX_ERROR;
            }

            buf->buf = (CHAR *) cl->buf->last;
            buf->len = (DWORD) n;
        }

        size += (size_t) n;
        prev = cl->buf->end;
        cl = cl->next;
    }

    n = 0;
    flags = 0;

    rc = WSARecv(c->fd, vec.elts, (DWORD) vec.nelts, (DWORD *) &n,
                 (LPDWORD) &flags, ovlp, NULL);
    ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, 0,
        "do WSARecv chain: fd:%d rc:%d %ul of %z", c->fd, rc, n, size);

    err = ngx_socket_errno;

    if (rc == 0) {
        if (c->type != SOCK_DGRAM) {
            if (n == 0) {
                rev->eof = 1;
            }

            if ((size_t) n < size) {
                ngx_post_overlapped_wsarecv(c, buf, size);
            }
        }

        return n;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "do WSARecv() chain not ready retry");
        return ngx_post_overlapped_wsarecv(c, buf, size);
    }

    ngx_connection_error(c, err, "do WSARecv() chain failed");

    rev->ready = 0;
    rev->error = 1;

    return NGX_ERROR;
}
