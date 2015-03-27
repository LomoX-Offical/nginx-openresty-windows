#ifndef NGX_HTTP_SET_MISC_MODULE_H
#define NGX_HTTP_SET_MISC_MODULE_H


typedef struct {
    ngx_flag_t          base32_padding;
    ngx_int_t           current;  /* for set_rotate */
} ngx_http_set_misc_loc_conf_t;


extern ngx_module_t  ngx_http_set_misc_module;


#endif /* NGX_HTTP_SET_MISC_MODULE_H */

