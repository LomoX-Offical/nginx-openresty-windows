
#include <ngx_config.h>
#include <ngx_core.h>



extern ngx_module_t  ngx_core_module;
extern ngx_module_t  ngx_errlog_module;
extern ngx_module_t  ngx_conf_module;
extern ngx_module_t  ngx_openssl_module;
extern ngx_module_t  ngx_regex_module;
extern ngx_module_t  ngx_events_module;
extern ngx_module_t  ngx_event_core_module;
extern ngx_module_t  ngx_iocp_module;
extern ngx_module_t  ngx_select_module;
extern ngx_module_t  ngx_http_module;
extern ngx_module_t  ngx_http_core_module;
extern ngx_module_t  ngx_http_log_module;
extern ngx_module_t  ngx_http_upstream_module;
extern ngx_module_t  ngx_http_v2_module;
extern ngx_module_t  ngx_http_static_module;
extern ngx_module_t  ngx_http_gzip_static_module;
extern ngx_module_t  ngx_http_dav_module;
extern ngx_module_t  ngx_http_autoindex_module;
extern ngx_module_t  ngx_http_index_module;
extern ngx_module_t  ngx_http_random_index_module;
extern ngx_module_t  ngx_http_auth_request_module;
extern ngx_module_t  ngx_http_auth_basic_module;
extern ngx_module_t  ngx_http_access_module;
extern ngx_module_t  ngx_http_limit_conn_module;
extern ngx_module_t  ngx_http_limit_req_module;
extern ngx_module_t  ngx_http_realip_module;
extern ngx_module_t  ngx_http_geo_module;
extern ngx_module_t  ngx_http_map_module;
extern ngx_module_t  ngx_http_split_clients_module;
extern ngx_module_t  ngx_http_referer_module;
extern ngx_module_t  ngx_http_rewrite_module;
extern ngx_module_t  ngx_http_ssl_module;
extern ngx_module_t  ngx_http_proxy_module;
extern ngx_module_t  ngx_http_fastcgi_module;
extern ngx_module_t  ngx_http_uwsgi_module;
extern ngx_module_t  ngx_http_scgi_module;
extern ngx_module_t  ngx_http_memcached_module;
extern ngx_module_t  ngx_http_empty_gif_module;
extern ngx_module_t  ngx_http_browser_module;
extern ngx_module_t  ngx_http_secure_link_module;
extern ngx_module_t  ngx_http_flv_module;
extern ngx_module_t  ngx_http_mp4_module;
extern ngx_module_t  ngx_http_upstream_hash_module;
extern ngx_module_t  ngx_http_upstream_ip_hash_module;
extern ngx_module_t  ngx_http_upstream_least_conn_module;
extern ngx_module_t  ngx_http_upstream_keepalive_module;
extern ngx_module_t  ngx_http_upstream_zone_module;
extern ngx_module_t  ngx_http_stub_status_module;
extern ngx_module_t  ndk_http_module;
extern ngx_module_t  ngx_coolkit_module;
extern ngx_module_t  ngx_postgres_module;
extern ngx_module_t  ngx_http_lua_upstream_module;
extern ngx_module_t  ngx_http_concat_module;
extern ngx_module_t  ngx_http_redis2_module;
extern ngx_module_t  ngx_http_write_filter_module;
extern ngx_module_t  ngx_http_header_filter_module;
extern ngx_module_t  ngx_http_chunked_filter_module;
extern ngx_module_t  ngx_http_v2_filter_module;
extern ngx_module_t  ngx_http_range_header_filter_module;
extern ngx_module_t  ngx_http_gzip_filter_module;
extern ngx_module_t  ngx_http_postpone_filter_module;
extern ngx_module_t  ngx_http_ssi_filter_module;
extern ngx_module_t  ngx_http_charset_filter_module;
extern ngx_module_t  ngx_http_sub_filter_module;
extern ngx_module_t  ngx_http_addition_filter_module;
extern ngx_module_t  ngx_http_gunzip_filter_module;
extern ngx_module_t  ngx_http_userid_filter_module;
extern ngx_module_t  ngx_http_headers_filter_module;
extern ngx_module_t  ngx_http_echo_module;
extern ngx_module_t  ngx_http_set_misc_module;
extern ngx_module_t  ngx_http_form_input_module;
extern ngx_module_t  ngx_http_encrypted_session_module;
extern ngx_module_t  ngx_http_lua_module;
extern ngx_module_t  ngx_http_headers_more_filter_module;
extern ngx_module_t  ngx_http_array_var_module;
extern ngx_module_t  ngx_http_rds_json_filter_module;
extern ngx_module_t  ngx_http_copy_filter_module;
extern ngx_module_t  ngx_http_range_body_filter_module;
extern ngx_module_t  ngx_http_not_modified_filter_module;
extern ngx_module_t  ngx_http_slice_filter_module;
extern ngx_module_t  ngx_mail_module;
extern ngx_module_t  ngx_mail_core_module;
extern ngx_module_t  ngx_mail_ssl_module;
extern ngx_module_t  ngx_mail_pop3_module;
extern ngx_module_t  ngx_mail_imap_module;
extern ngx_module_t  ngx_mail_smtp_module;
extern ngx_module_t  ngx_mail_auth_http_module;
extern ngx_module_t  ngx_mail_proxy_module;
extern ngx_module_t  ngx_stream_module;
extern ngx_module_t  ngx_stream_core_module;
extern ngx_module_t  ngx_stream_proxy_module;
extern ngx_module_t  ngx_stream_upstream_module;
extern ngx_module_t  ngx_stream_ssl_module;
extern ngx_module_t  ngx_stream_limit_conn_module;
extern ngx_module_t  ngx_stream_access_module;
extern ngx_module_t  ngx_stream_upstream_hash_module;
extern ngx_module_t  ngx_stream_upstream_least_conn_module;
extern ngx_module_t  ngx_stream_upstream_zone_module;

ngx_module_t *ngx_modules[] = {
    &ngx_core_module,
    &ngx_errlog_module,
    &ngx_conf_module,
    &ngx_openssl_module,
    &ngx_regex_module,
    &ngx_events_module,
    &ngx_event_core_module,
    &ngx_iocp_module,
    &ngx_select_module,
    &ngx_http_module,
    &ngx_http_core_module,
    &ngx_http_log_module,
    &ngx_http_upstream_module,
    &ngx_http_v2_module,
    &ngx_http_static_module,
    &ngx_http_gzip_static_module,
    &ngx_http_dav_module,
    &ngx_http_autoindex_module,
    &ngx_http_index_module,
    &ngx_http_random_index_module,
    &ngx_http_auth_request_module,
    &ngx_http_auth_basic_module,
    &ngx_http_access_module,
    &ngx_http_limit_conn_module,
    &ngx_http_limit_req_module,
    &ngx_http_realip_module,
    &ngx_http_geo_module,
    &ngx_http_map_module,
    &ngx_http_split_clients_module,
    &ngx_http_referer_module,
    &ngx_http_rewrite_module,
    &ngx_http_ssl_module,
    &ngx_http_proxy_module,
    &ngx_http_fastcgi_module,
    &ngx_http_uwsgi_module,
    &ngx_http_scgi_module,
    &ngx_http_memcached_module,
    &ngx_http_empty_gif_module,
    &ngx_http_browser_module,
    &ngx_http_secure_link_module,
    &ngx_http_flv_module,
    &ngx_http_mp4_module,
    &ngx_http_upstream_hash_module,
    &ngx_http_upstream_ip_hash_module,
    &ngx_http_upstream_least_conn_module,
    &ngx_http_upstream_keepalive_module,
    &ngx_http_upstream_zone_module,
    &ngx_http_stub_status_module,
    &ndk_http_module,
    &ngx_coolkit_module,
    &ngx_postgres_module,
    &ngx_http_lua_upstream_module,
    &ngx_http_concat_module,
    &ngx_http_redis2_module,
    &ngx_http_write_filter_module,
    &ngx_http_header_filter_module,
    &ngx_http_chunked_filter_module,
    &ngx_http_v2_filter_module,
    &ngx_http_range_header_filter_module,
    &ngx_http_gzip_filter_module,
    &ngx_http_postpone_filter_module,
    &ngx_http_ssi_filter_module,
    &ngx_http_charset_filter_module,
    &ngx_http_sub_filter_module,
    &ngx_http_addition_filter_module,
    &ngx_http_gunzip_filter_module,
    &ngx_http_userid_filter_module,
    &ngx_http_headers_filter_module,
    &ngx_http_echo_module,
    &ngx_http_set_misc_module,
    &ngx_http_form_input_module,
    &ngx_http_encrypted_session_module,
    &ngx_http_lua_module,
    &ngx_http_headers_more_filter_module,
    &ngx_http_array_var_module,
    &ngx_http_rds_json_filter_module,
    &ngx_http_copy_filter_module,
    &ngx_http_range_body_filter_module,
    &ngx_http_not_modified_filter_module,
    &ngx_http_slice_filter_module,
    &ngx_mail_module,
    &ngx_mail_core_module,
    &ngx_mail_ssl_module,
    &ngx_mail_pop3_module,
    &ngx_mail_imap_module,
    &ngx_mail_smtp_module,
    &ngx_mail_auth_http_module,
    &ngx_mail_proxy_module,
    &ngx_stream_module,
    &ngx_stream_core_module,
    &ngx_stream_proxy_module,
    &ngx_stream_upstream_module,
    &ngx_stream_ssl_module,
    &ngx_stream_limit_conn_module,
    &ngx_stream_access_module,
    &ngx_stream_upstream_hash_module,
    &ngx_stream_upstream_least_conn_module,
    &ngx_stream_upstream_zone_module,
    NULL
};

char *ngx_module_names[] = {
    "ngx_core_module",
    "ngx_errlog_module",
    "ngx_conf_module",
    "ngx_openssl_module",
    "ngx_regex_module",
    "ngx_events_module",
    "ngx_event_core_module",
    "ngx_iocp_module",
    "ngx_select_module",
    "ngx_http_module",
    "ngx_http_core_module",
    "ngx_http_log_module",
    "ngx_http_upstream_module",
    "ngx_http_v2_module",
    "ngx_http_static_module",
    "ngx_http_gzip_static_module",
    "ngx_http_dav_module",
    "ngx_http_autoindex_module",
    "ngx_http_index_module",
    "ngx_http_random_index_module",
    "ngx_http_auth_request_module",
    "ngx_http_auth_basic_module",
    "ngx_http_access_module",
    "ngx_http_limit_conn_module",
    "ngx_http_limit_req_module",
    "ngx_http_realip_module",
    "ngx_http_geo_module",
    "ngx_http_map_module",
    "ngx_http_split_clients_module",
    "ngx_http_referer_module",
    "ngx_http_rewrite_module",
    "ngx_http_ssl_module",
    "ngx_http_proxy_module",
    "ngx_http_fastcgi_module",
    "ngx_http_uwsgi_module",
    "ngx_http_scgi_module",
    "ngx_http_memcached_module",
    "ngx_http_empty_gif_module",
    "ngx_http_browser_module",
    "ngx_http_secure_link_module",
    "ngx_http_flv_module",
    "ngx_http_mp4_module",
    "ngx_http_upstream_hash_module",
    "ngx_http_upstream_ip_hash_module",
    "ngx_http_upstream_least_conn_module",
    "ngx_http_upstream_keepalive_module",
    "ngx_http_upstream_zone_module",
    "ngx_http_stub_status_module",
    "ndk_http_module",
    "ngx_coolkit_module",
    "ngx_postgres_module",
    "ngx_http_lua_upstream_module",
    "ngx_http_concat_module",
    "ngx_http_redis2_module",
    "ngx_http_write_filter_module",
    "ngx_http_header_filter_module",
    "ngx_http_chunked_filter_module",
    "ngx_http_v2_filter_module",
    "ngx_http_range_header_filter_module",
    "ngx_http_gzip_filter_module",
    "ngx_http_postpone_filter_module",
    "ngx_http_ssi_filter_module",
    "ngx_http_charset_filter_module",
    "ngx_http_sub_filter_module",
    "ngx_http_addition_filter_module",
    "ngx_http_gunzip_filter_module",
    "ngx_http_userid_filter_module",
    "ngx_http_headers_filter_module",
    "ngx_http_echo_module",
    "ngx_http_set_misc_module",
    "ngx_http_form_input_module",
    "ngx_http_encrypted_session_module",
    "ngx_http_lua_module",
    "ngx_http_headers_more_filter_module",
    "ngx_http_array_var_module",
    "ngx_http_rds_json_filter_module",
    "ngx_http_copy_filter_module",
    "ngx_http_range_body_filter_module",
    "ngx_http_not_modified_filter_module",
    "ngx_http_slice_filter_module",
    "ngx_mail_module",
    "ngx_mail_core_module",
    "ngx_mail_ssl_module",
    "ngx_mail_pop3_module",
    "ngx_mail_imap_module",
    "ngx_mail_smtp_module",
    "ngx_mail_auth_http_module",
    "ngx_mail_proxy_module",
    "ngx_stream_module",
    "ngx_stream_core_module",
    "ngx_stream_proxy_module",
    "ngx_stream_upstream_module",
    "ngx_stream_ssl_module",
    "ngx_stream_limit_conn_module",
    "ngx_stream_access_module",
    "ngx_stream_upstream_hash_module",
    "ngx_stream_upstream_least_conn_module",
    "ngx_stream_upstream_zone_module",
    NULL
};

