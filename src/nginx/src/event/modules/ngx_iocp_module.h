
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_IOCP_MODULE_H_INCLUDED_
#define _NGX_IOCP_MODULE_H_INCLUDED_


typedef struct {
    ngx_uint_t    threads;
    ngx_uint_t    events;
    ngx_uint_t    post_acceptex;
    ngx_uint_t    acceptex_read;
    ngx_uint_t    post_udp_recv;
} ngx_iocp_conf_t;

typedef struct {
    ngx_connection_handler_pt   handler;
} ngx_iocp_connection_t;

ngx_int_t ngx_iocp_add_file(ngx_file_t *file);
ngx_int_t ngx_iocp_shutdown(ngx_connection_t *c);

extern ngx_module_t  ngx_iocp_module;
extern ngx_addr_t    ngx_iocp_local_addr_v4;
extern ngx_addr_t    ngx_iocp_local_addr_v6;
extern HANDLE        iocp;

#endif /* _NGX_IOCP_MODULE_H_INCLUDED_ */
