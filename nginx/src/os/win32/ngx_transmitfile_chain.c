
/*
 * Copyright (C) Ngwsx
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


ngx_chain_t *
ngx_transmitfile_chain(ngx_connection_t *c, ngx_chain_t *in, off_t limit)
{
    int                     rc, n;
    u_char                 *prev, *head, *tail, *func;
    off_t                   size, send, aligned, sent, fprev, file_pos;
    size_t                  file_size, head_size, tail_size;
    WSABUF                  bufs[2];
    ngx_fd_t                fd;
    ngx_err_t               err;
    ngx_buf_t              *file;
    ngx_event_t            *wev;
    ngx_chain_t            *cl;
    WSAOVERLAPPED          *ovlp;
    TRANSMIT_FILE_BUFFERS  *ptfb, tfb;

    if (!c->sendfile || !(ngx_event_flags & NGX_USE_IOCP_EVENT)) {
        return ngx_wsasend_chain(c, in, limit);
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

    /* create the header and coalesce the neighbouring bufs */

    head = NULL;
    head_size = 0;
    prev = NULL;

    for (cl = in; cl && send < limit; cl = cl->next) {

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

        if (head == NULL) {
            head = cl->buf->pos;
            head_size = (size_t) size;

        } else if (prev == cl->buf->pos) {
            head_size += (size_t) size;

        } else {
            break;
        }

        send += size;
        prev = cl->buf->pos + size;
    }

    /* coalesce the neighbouring file bufs */

    fd = NULL;
    file = NULL;
    file_size = 0;

    if (cl && cl->buf->in_file && send < limit) {

        file = cl->buf;

        /*
         * caching performance is improved by opening this handle
         * with FILE_FLAG_SEQUENTIAL_SCAN
         */

        fd = file->file->fd;

        do {
            size = cl->buf->file_last - cl->buf->file_pos;

            if (send + size > limit) {
                size = limit - send;

                aligned = ngx_align(cl->buf->file_pos + size,
                                    (off_t) ngx_pagesize);

                if (aligned <= cl->buf->file_last) {
                    size = aligned - cl->buf->file_pos;
                }
            }

            file_size += (size_t) size;
            send += size;
            fprev = cl->buf->file_pos + size;
            cl = cl->next;

        } while (cl && cl->buf->in_file && send < limit
                 && fd == cl->buf->file->fd && fprev == cl->buf->file_pos);
    }

    /* create the tailer and coalesce the neighbouring bufs */

    tail = NULL;
    tail_size = 0;
    prev = NULL;

    while (cl && send < limit) {

        if (ngx_buf_special(cl->buf)) {
            cl = cl->next;
            continue;
        }

        if (!ngx_buf_in_memory_only(cl->buf)) {
            break;
        }

        size = (off_t) (cl->buf->last - cl->buf->pos);

        if (send + size > limit) {
            size = limit - send;
        }

        if (tail == NULL) {
            tail = cl->buf->pos;
            tail_size = (size_t) size;

        } else if (prev == cl->buf->pos) {
            tail_size += (size_t) size;

        } else {
            break;
        }

        send += size;
        prev = cl->buf->pos + size;
        cl = cl->next;
    }

    wev->ovlp.event = wev;
    ovlp = (WSAOVERLAPPED *) &wev->ovlp;

    if (file) {

        ptfb = NULL;

        ngx_memzero(&tfb, sizeof(TRANSMIT_FILE_BUFFERS));

        if (head) {
            ptfb = &tfb;

            tfb.Head = head;
            tfb.HeadLength = (DWORD) head_size;
        }

        if (tail) {
            ptfb = &tfb;

            tfb.Tail = tail;
            tfb.TailLength = (DWORD) tail_size;
        }

        ngx_memzero(ovlp, sizeof(WSAOVERLAPPED));

        file_pos = file->file_pos;

        ovlp->Offset = (DWORD) ((int64_t) file_pos & 0xffffffff);
        ovlp->OffsetHigh = (DWORD) ((int64_t) file_pos >> 32);

        ngx_log_debug4(NGX_LOG_DEBUG_EVENT, c->log, 0,
                       "TransmitFile() h:%z t:%z f:%O-%z",
                       head_size, tail_size, file_pos, file_size);

        /*
         * nNumberOfBytesPerSend and dwFlags parameter of TransmitFile
         *
         * To select the default send size, set nNumberOfBytesPerSend to zero.
         * The nNumberOfBytesPerSend parameter is useful for message protocols
         * that have limitations on the size of individual send requests.
         *
         * dwFlags:
         * TF_DISCONNECT、TF_REUSE_SOCKET、TF_USE_DEFAULT_WORKER、
         * TF_USE_SYSTEM_THREAD、TF_USE_KERNEL_APC、TF_WRITE_BEHIND.
         */

        rc = ngx_transmitfile(c->fd, fd, (DWORD) file_size, 0, ovlp, ptfb, 0);

        err = ngx_socket_errno;

        if (rc != 0) {
            wev->ready = 0;
            return in;
        }

        func = (u_char *) "TransmitFile";

    } else {

        n = 0;

        if (head) {
            bufs[n].buf = (CHAR *) head;
            bufs[n].len = (u_long) head_size;
            n++;
        }

        if (tail) {
            bufs[n].buf = (CHAR *) tail;
            bufs[n].len = (u_long) tail_size;
            n++;
        }

        ngx_log_debug2(NGX_LOG_DEBUG_EVENT, c->log, 0,
                   "WSASend() fd:%d, size:%uz", c->fd, send);

        rc = WSASend(c->fd, bufs, n, NULL, 0, ovlp, NULL);

        err = ngx_socket_errno;

        if (rc == 0) {
            wev->ready = 0;
            return in;
        }

        func = (u_char *) "WSASend";
    }

    if (err == WSA_IO_PENDING || err == ERROR_IO_PENDING) {
        ngx_log_debug1(NGX_LOG_DEBUG_EVENT, c->log, err,
                       "%s() not ready", func);
        wev->ready = 0;
        return in;
    }

    ngx_connection_error(c, err, "TransmitFile() failed");

    wev->error = 1;

    return NGX_CHAIN_ERROR;
}
