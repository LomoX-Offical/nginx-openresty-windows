
/*
 * Copyright (C) Ngwsx
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


#if (IOV_MAX > 64)
#define NGX_IOVS  64
#else
#define NGX_IOVS  IOV_MAX
#endif


ngx_chain_t *
ngx_transmit_buffer(ngx_connection_t *c, ngx_chain_t *in, off_t limit)
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

    if (ngx_event_flags & NGX_USE_IOCP_EVENT && !wev->ovlp.posted_zero_byte) {
        ovlp = (WSAOVERLAPPED *) &wev->ovlp;

        /* overlapped io */

        buf = ngx_array_push(&vec);
        if (buf == NULL) {
            return NGX_CHAIN_ERROR;
        }

        buf->buf = NULL;
        buf->len = 0;

    } else {
        ovlp = NULL;

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

            if (!ngx_buf_in_memory_only(cl->buf)) {
                break;
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
    }

    n = 0;

    rc = WSASend(c->fd, vec.elts, (DWORD) vec.nelts, (DWORD *) &n, 0, ovlp,
                 NULL);

    err = ngx_socket_errno;

    if (rc == 0) {
        if (ovlp != NULL) {
            wev->ovlp.posted_zero_byte = 1;
            wev->ready = 0;
            return in;
        }

#if 0
        if (n < send) {
            wev->ready = 0;
        }
#endif

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

        return ngx_transmitpackets_chain(c, cl, limit);
    }

    if (err == WSA_IO_PENDING) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "WSASend() not ready");
        wev->ovlp.posted_zero_byte = 1;
        wev->ready = 0;
        return in;
    }

    if (err == WSAEWOULDBLOCK) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err, "WSASend() not ready");

        if ((ngx_event_flags & NGX_USE_IOCP_EVENT) == 0) {
            wev->ready = 0;
            return in;
        }

        /* post another overlapped-io WSASend() */
        wev->ovlp.posted_zero_byte = 0;
        goto retry;
    }

    ngx_connection_error(c, err, "WSASend() failed");

    wev->ready = 0;
    wev->error = 1;

    return NGX_CHAIN_ERROR;
}


#if 1

ngx_chain_t *
ngx_transmitpackets_chain(ngx_connection_t *c, ngx_chain_t *in, off_t limit)
{
    int                        rc;
    off_t                      size, send, aligned, sent, fprev;
    ngx_fd_t                   fd;
    ngx_err_t                  err;
    ngx_array_t                vec;
    ngx_event_t               *wev;
    ngx_chain_t               *cl;
    WSAOVERLAPPED             *ovlp;
    TRANSMIT_PACKETS_ELEMENT  *tpe, tpes[NGX_IOVS];

    if (!c->sendfile || !(ngx_event_flags & NGX_USE_IOCP_EVENT)) {
        return ngx_wsasend_chain(c, in, limit);
    }

    if (in == NULL) {
        return in;
    }

    for (cl = in; cl; cl = cl->next) {

        if (ngx_buf_special(cl->buf)) {
            continue;
        }

        if (!ngx_buf_in_memory_only(cl->buf)) {
            break;
        }

        return ngx_transmit_buffer(c, in, limit);
    }

    wev = c->write;

    if (wev->closed) {
        return NULL;
    }

    if (wev->error) {
        return NGX_CHAIN_ERROR;
    }

    sent = wev->available;

    if (wev->ready && sent > 0) {

        wev->available = 0;
        c->sent += sent;

        for (cl = in; cl; cl = cl->next) {

            if (ngx_buf_special(cl->buf)) {
                continue;
            }

            if (sent == 0) {
                break;
            }

            size = ngx_buf_size(cl->buf);

            if (sent >= size) {
                sent -= size;

                if (ngx_buf_in_memory(cl->buf)) {
                    cl->buf->pos = cl->buf->last;
                }

                if (cl->buf->in_file) {
                    cl->buf->file_pos = cl->buf->file_last;
                }

                continue;
            }

            if (ngx_buf_in_memory(cl->buf)) {
                cl->buf->pos += sent;
            }

            if (cl->buf->in_file) {
                cl->buf->file_pos += sent;
            }

            break;
        }

        return cl;
    }

    /* the maximum limit size is the maximum size_t value - the page size */

    if (limit == 0 || limit > (off_t) (NGX_MAX_SIZE_T_VALUE - ngx_pagesize)) {
        limit = NGX_MAX_SIZE_T_VALUE - (off_t) ngx_pagesize;
    }

    send = 0;

    vec.nelts = 0;
    vec.elts = tpes;
    vec.size = sizeof(TRANSMIT_PACKETS_ELEMENT);
    vec.nalloc = NGX_IOVS;
    vec.pool = c->pool;

    /*
     * create the TRANSMIT_PACKETS_ELEMENT and
     * coalesce the neighbouring bufs
     */

    fd = INVALID_HANDLE_VALUE;
    tpe = NULL;
    fprev = 0;

    for (cl = in; cl && vec.nelts < NGX_IOVS && send < limit;
         cl = cl->next)
    {
        if (ngx_buf_special(cl->buf)) {
            continue;
        }

        if (ngx_buf_in_memory_only(cl->buf)) {
            break;
        }

        size = cl->buf->file_last - cl->buf->file_pos;

        if (send + size > limit) {
            size = limit - send;

            aligned = ngx_align(cl->buf->file_pos + size,
                                (off_t) ngx_pagesize);

            if (aligned <= cl->buf->file_last) {
                size = aligned - cl->buf->file_pos;
            }
        }

        if (fd == cl->buf->file->fd && fprev == cl->buf->file_pos) {
            tpe->cLength += (ULONG) size;

        } else {
            tpe = ngx_array_push(&vec);
            if (tpe == NULL) {
                return NGX_CHAIN_ERROR;
            }

            /*
             * caching performance is improved by opening this handle
             * with FILE_FLAG_SEQUENTIAL_SCAN
             */

            fd = cl->buf->file->fd;

            tpe->dwElFlags = TP_ELEMENT_FILE;
            tpe->hFile = fd;
            tpe->nFileOffset.QuadPart = cl->buf->file_pos;
            tpe->cLength = (ULONG) size;
        }

        fprev = cl->buf->file_pos + size;

        send += size;
    }

    wev->ovlp.event = wev;
    ovlp = (WSAOVERLAPPED *) &wev->ovlp;

    ngx_memzero(ovlp, sizeof(WSAOVERLAPPED));

    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, 0,
                   "TransmitPackets: %O", send);

    /*
     * nSendSize and dwFlags parameter of TransmitPackets
     *
     * Set nSendSize to zero to let the sockets layer select a default
     * send size. But when using the TP_ELEMENT_EOP flag in the
     * TRANSMIT_PACKETS_ELEMENT, You should setting nSendSize to 0xFFFFFFF.
     *
     * dwFlags:
     * TP_DISCONNECT、TP_REUSE_SOCKET、TP_USE_DEFAULT_WORKER、
     * TP_USE_SYSTEM_THREAD、TP_USE_KERNEL_APC.
     */

    rc = ngx_transmitpackets(c->fd, vec.elts, (DWORD) vec.nelts, 0, ovlp, 0);

    err = ngx_socket_errno;

    if (rc != 0) {
        wev->ready = 0;
        return in;
    }

    if (err == ERROR_IO_PENDING) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err,
                       "TransmitPackets() not ready");
        wev->ready = 0;
        return in;
    }

    ngx_connection_error(c, err, "TransmitPackets() failed");

    wev->error = 1;

    return NGX_CHAIN_ERROR;
}

#else

ngx_chain_t *
ngx_transmitpackets_chain(ngx_connection_t *c, ngx_chain_t *in, off_t limit)
{
    int                        rc;
    u_char                    *prev;
    off_t                      size, send, aligned, sent, fprev;
    ngx_fd_t                   fd;
    ngx_err_t                  err;
    ngx_array_t                vec;
    ngx_event_t               *wev;
    ngx_chain_t               *cl;
    WSAOVERLAPPED             *ovlp;
    TRANSMIT_PACKETS_ELEMENT  *tpe, tpes[NGX_IOVS];

    if (!c->sendfile || !(ngx_event_flags & NGX_USE_IOCP_EVENT)) {
        return ngx_writev_chain(c, in, limit);
    }

    wev = c->write;

    if (wev->closed) {
        return NULL;
    }

    if (wev->error) {
        return NGX_CHAIN_ERROR;
    }

    sent = wev->available;

    if (wev->ready && sent > 0) {

        wev->available = 0;
        c->sent += sent;

        for (cl = in; cl; cl = cl->next) {

            if (ngx_buf_special(cl->buf)) {
                continue;
            }

            if (sent == 0) {
                break;
            }

            size = ngx_buf_size(cl->buf);

            if (sent >= size) {
                sent -= size;

                if (ngx_buf_in_memory(cl->buf)) {
                    cl->buf->pos = cl->buf->last;
                }

                if (cl->buf->in_file) {
                    cl->buf->file_pos = cl->buf->file_last;
                }

                continue;
            }

            if (ngx_buf_in_memory(cl->buf)) {
                cl->buf->pos += sent;
            }

            if (cl->buf->in_file) {
                cl->buf->file_pos += sent;
            }

            break;
        }

        return cl;
    }

    /* the maximum limit size is the maximum size_t value - the page size */

    if (limit == 0 || limit > (off_t) (NGX_MAX_SIZE_T_VALUE - ngx_pagesize)) {
        limit = NGX_MAX_SIZE_T_VALUE - (off_t) ngx_pagesize;
    }

    send = 0;

    vec.nelts = 0;
    vec.elts = tpes;
    vec.size = sizeof(TRANSMIT_PACKETS_ELEMENT);
    vec.nalloc = NGX_IOVS;
    vec.pool = c->pool;

    /*
     * create the TRANSMIT_PACKETS_ELEMENT and
     * coalesce the neighbouring bufs
     */

    fd = INVALID_HANDLE_VALUE;
    prev = NULL;
    fprev = 0;

    for (cl = in; cl && vec.nelts < NGX_IOVS && send < limit;
         cl = cl->next)
    {
        if (ngx_buf_special(cl->buf)) {
            continue;
        }

        if (ngx_buf_in_memory_only(cl->buf)) {

            fd = INVALID_HANDLE_VALUE;
            fprev = 0;

            size = (off_t) (cl->buf->last - cl->buf->pos);

            if (send + size > limit) {
                size = limit - send;
            }

            if (prev == cl->buf->pos) {
                tpe->cLength += (ULONG) size;

            } else {
                tpe = ngx_array_push(&vec);
                if (tpe == NULL) {
                    return NGX_CHAIN_ERROR;
                }

                tpe->dwElFlags = TP_ELEMENT_MEMORY;
                tpe->pBuffer = cl->buf->pos;
                tpe->cLength = (ULONG) size;
            }

            prev = cl->buf->pos + size;

        } else {

            prev = NULL;

            size = cl->buf->file_last - cl->buf->file_pos;

            if (send + size > limit) {
                size = limit - send;

                aligned = ngx_align(cl->buf->file_pos + size,
                                    (off_t) ngx_pagesize);

                if (aligned <= cl->buf->file_last) {
                    size = aligned - cl->buf->file_pos;
                }
            }

            if (fd == cl->buf->file->fd && fprev == cl->buf->file_pos) {
                tpe->cLength += (ULONG) size;

            } else {
                tpe = ngx_array_push(&vec);
                if (tpe == NULL) {
                    return NGX_CHAIN_ERROR;
                }

                /*
                 * caching performance is improved by opening this handle
                 * with FILE_FLAG_SEQUENTIAL_SCAN
                 */

                fd = cl->buf->file->fd;

                tpe->dwElFlags = TP_ELEMENT_FILE;
                tpe->hFile = fd;
                tpe->nFileOffset.QuadPart = cl->buf->file_pos;
                tpe->cLength = (ULONG) size;
            }

            fprev = cl->buf->file_pos + size;
        }

        send += size;
    }

    wev->ovlp.event = wev;
    ovlp = (WSAOVERLAPPED *) &wev->ovlp;

    ngx_memzero(ovlp, sizeof(WSAOVERLAPPED));

    ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, 0,
                   "TransmitPackets: %O", send);

    /*
     * nSendSize and dwFlags parameter of TransmitPackets
     *
     * Set nSendSize to zero to let the sockets layer select a default
     * send size. But when using the TP_ELEMENT_EOP flag in the
     * TRANSMIT_PACKETS_ELEMENT, You should setting nSendSize to 0xFFFFFFF.
     *
     * dwFlags:
     * TP_DISCONNECT、TP_REUSE_SOCKET、TP_USE_DEFAULT_WORKER、
     * TP_USE_SYSTEM_THREAD、TP_USE_KERNEL_APC.
     */

    rc = ngx_transmit_packets(c->fd, vec.elts, (DWORD) vec.nelts, 0, ovlp, 0);

    err = ngx_socket_errno;

    if (rc != 0) {
        wev->ready = 0;
        return in;
    }

    if (err == ERROR_IO_PENDING) {
        ngx_log_debug0(NGX_LOG_DEBUG_EVENT, c->log, err,
                       "TransmitPackets() not ready");
        wev->ready = 0;
        return in;
    }

    ngx_connection_error(c, err, "TransmitPackets() failed");

    wev->error = 1;

    return NGX_CHAIN_ERROR;
}

#endif
