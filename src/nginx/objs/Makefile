
CC =	cl
CFLAGS = -I../luajit-root/luajit/include/luajit-2.1  -O2  -W4 -nologo -MT -Zi -DFD_SETSIZE=32768 -DNDK_SET_VAR -DNDK_UPSTREAM_LIST -DNDK_SET_VAR -DNDK_SET_VAR -DNDK_SET_VAR -DNDK_SET_VAR -DNO_SYS_TYPES_H
CPP =	
LINK =	$(CC)


ALL_INCS = -I src/core \
	-I src/event \
	-I src/event/modules \
	-I src/os/win32 \
	-I ../ngx_devel_kit-0.3.0/objs \
	-I objs/addon/ndk \
	-I ../ngx_postgres-1.0/include \
	-I ../ngx_lua/src/api \
	-I objs/lib/pcre \
	-I objs/lib/openssl/openssl/include \
	-I objs/lib/zlib \
	-I objs \
	-I src/http \
	-I src/http/modules \
	-I src/http/v2 \
	-I ../ngx_devel_kit-0.3.0/src \
	-I ../ngx_devel_kit-0.3.0/src \
	-I ../ngx_devel_kit-0.3.0/objs \
	-I objs/addon/ndk \
	-I ../luajit-root/luajit/include/luajit-2.1 \
	-I src/mail \
	-I src/stream


CORE_DEPS = src/core/nginx.h \
	src/core/ngx_config.h \
	src/core/ngx_core.h \
	src/core/ngx_log.h \
	src/core/ngx_palloc.h \
	src/core/ngx_array.h \
	src/core/ngx_list.h \
	src/core/ngx_hash.h \
	src/core/ngx_buf.h \
	src/core/ngx_queue.h \
	src/core/ngx_string.h \
	src/core/ngx_parse.h \
	src/core/ngx_parse_time.h \
	src/core/ngx_inet.h \
	src/core/ngx_file.h \
	src/core/ngx_crc.h \
	src/core/ngx_crc32.h \
	src/core/ngx_murmurhash.h \
	src/core/ngx_md5.h \
	src/core/ngx_sha1.h \
	src/core/ngx_rbtree.h \
	src/core/ngx_radix_tree.h \
	src/core/ngx_rwlock.h \
	src/core/ngx_slab.h \
	src/core/ngx_times.h \
	src/core/ngx_shmtx.h \
	src/core/ngx_connection.h \
	src/core/ngx_cycle.h \
	src/core/ngx_conf_file.h \
	src/core/ngx_module.h \
	src/core/ngx_resolver.h \
	src/core/ngx_open_file_cache.h \
	src/core/ngx_crypt.h \
	src/core/ngx_proxy_protocol.h \
	src/core/ngx_syslog.h \
	src/event/ngx_event.h \
	src/event/ngx_event_timer.h \
	src/event/ngx_event_posted.h \
	src/event/ngx_event_connect.h \
	src/event/ngx_event_pipe.h \
	src/os/win32/ngx_win32_config.h \
	src/os/win32/ngx_time.h \
	src/os/win32/ngx_errno.h \
	src/os/win32/ngx_alloc.h \
	src/os/win32/ngx_files.h \
	src/os/win32/ngx_shmem.h \
	src/os/win32/ngx_process.h \
	src/os/win32/ngx_atomic.h \
	src/os/win32/ngx_thread.h \
	src/os/win32/ngx_socket.h \
	src/os/win32/ngx_os.h \
	src/os/win32/ngx_user.h \
	src/os/win32/ngx_dlopen.h \
	src/os/win32/ngx_process_cycle.h \
	src/event/ngx_event_openssl.h \
	src/core/ngx_regex.h \
	objs/lib/pcre/pcre.h \
	objs/lib/openssl/openssl/include/openssl/ssl.h \
	objs/ngx_auto_config.h


CORE_INCS = -I src/core \
	-I src/event \
	-I src/event/modules \
	-I src/os/win32 \
	-I ../ngx_devel_kit-0.3.0/objs \
	-I objs/addon/ndk \
	-I ../ngx_postgres-1.0/include \
	-I ../ngx_lua/src/api \
	-I objs/lib/pcre \
	-I objs/lib/openssl/openssl/include \
	-I objs/lib/zlib \
	-I objs


HTTP_DEPS = src/http/ngx_http.h \
	src/http/ngx_http_request.h \
	src/http/ngx_http_config.h \
	src/http/ngx_http_core_module.h \
	src/http/ngx_http_cache.h \
	src/http/ngx_http_variables.h \
	src/http/ngx_http_script.h \
	src/http/ngx_http_upstream.h \
	src/http/ngx_http_upstream_round_robin.h \
	src/http/modules/ngx_http_ssi_filter_module.h \
	src/http/v2/ngx_http_v2.h \
	src/http/v2/ngx_http_v2_module.h \
	src/http/modules/ngx_http_ssl_module.h


HTTP_INCS = -I src/http \
	-I src/http/modules \
	-I src/http/v2 \
	-I ../ngx_devel_kit-0.3.0/src \
	-I ../ngx_devel_kit-0.3.0/src \
	-I ../ngx_devel_kit-0.3.0/objs \
	-I objs/addon/ndk \
	-I ../luajit-root/luajit/include/luajit-2.1


MAIL_DEPS = src/mail/ngx_mail.h \
	src/mail/ngx_mail_ssl_module.h \
	src/mail/ngx_mail_pop3_module.h \
	src/mail/ngx_mail_imap_module.h \
	src/mail/ngx_mail_smtp_module.h


MAIL_INCS = -I src/mail


STREAM_DEPS = src/stream/ngx_stream.h \
	src/stream/ngx_stream_variables.h \
	src/stream/ngx_stream_script.h \
	src/stream/ngx_stream_upstream.h \
	src/stream/ngx_stream_upstream_round_robin.h \
	src/stream/ngx_stream_ssl_module.h


STREAM_INCS = -I src/stream


ADDON_DEPS = $(CORE_DEPS)  ../ngx_devel_kit-0.3.0/src/ndk.h                                                                          ../echo-nginx-module-0.61/src/ddebug.h                                                 ../echo-nginx-module-0.61/src/ngx_http_echo_module.h                                   ../echo-nginx-module-0.61/src/ngx_http_echo_handler.h                                  ../echo-nginx-module-0.61/src/ngx_http_echo_util.h                                     ../echo-nginx-module-0.61/src/ngx_http_echo_sleep.h                                    ../echo-nginx-module-0.61/src/ngx_http_echo_filter.h                                   ../echo-nginx-module-0.61/src/ngx_http_echo_var.h                                      ../echo-nginx-module-0.61/src/ngx_http_echo_location.h                                 ../echo-nginx-module-0.61/src/ngx_http_echo_echo.h                                     ../echo-nginx-module-0.61/src/ngx_http_echo_request_info.h                             ../echo-nginx-module-0.61/src/ngx_http_echo_subrequest.h                               ../echo-nginx-module-0.61/src/ngx_http_echo_foreach.h                                   ../ngx_coolkit-0.2rc3/src/ngx_coolkit_handlers.h ../ngx_coolkit-0.2rc3/src/ngx_coolkit_module.h ../ngx_coolkit-0.2rc3/src/ngx_coolkit_variables.h                                                                          ../set-misc-nginx-module-0.31/src/ddebug.h                                                 ../set-misc-nginx-module-0.31/src/ngx_http_set_default_value.h                             ../set-misc-nginx-module-0.31/src/ngx_http_set_hashed_upstream.h                           ../set-misc-nginx-module-0.31/src/ngx_http_set_quote_sql.h                                 ../set-misc-nginx-module-0.31/src/ngx_http_set_quote_json.h                                ../set-misc-nginx-module-0.31/src/ngx_http_set_unescape_uri.h                              ../set-misc-nginx-module-0.31/src/ngx_http_set_escape_uri.h                                ../set-misc-nginx-module-0.31/src/ngx_http_set_hash.h                                      ../set-misc-nginx-module-0.31/src/ngx_http_set_local_today.h                               ../set-misc-nginx-module-0.31/src/ngx_http_set_hex.h                                       ../set-misc-nginx-module-0.31/src/ngx_http_set_base64.h                                    ../set-misc-nginx-module-0.31/src/ngx_http_set_random.h                                    ../set-misc-nginx-module-0.31/src/ngx_http_set_rotate.h                                    ../set-misc-nginx-module-0.31/src/ngx_http_set_secure_random.h                             ../set-misc-nginx-module-0.31/src/ngx_http_set_misc_module.h                                ../set-misc-nginx-module-0.31/src/ngx_http_set_hmac.h ../ngx_postgres-1.0/src/ngx_postgres_escape.h ../ngx_postgres-1.0/src/ngx_postgres_handler.h ../ngx_postgres-1.0/src/ngx_postgres_keepalive.h ../ngx_postgres-1.0/src/ngx_postgres_module.h ../ngx_postgres-1.0/src/ngx_postgres_output.h ../ngx_postgres-1.0/src/ngx_postgres_processor.h ../ngx_postgres-1.0/src/ngx_postgres_rewrite.h ../ngx_postgres-1.0/src/ngx_postgres_upstream.h ../ngx_postgres-1.0/src/ngx_postgres_util.h ../ngx_postgres-1.0/src/ngx_postgres_variable.h ../ngx_postgres-1.0/src/ngx_postgres_ddebug.h ../ngx_postgres-1.0/src/resty_dbd_stream.h ../form-input-nginx-module-0.12/src/ddebug.h                                                                    ../encrypted-session-nginx-module-0.06/src/ddebug.h                                                 ../encrypted-session-nginx-module-0.06/src/ngx_http_encrypted_session_cipher.h                                    ../ngx_lua/src/ddebug.h             ../ngx_lua/src/ngx_http_lua_script.h             ../ngx_lua/src/ngx_http_lua_log.h             ../ngx_lua/src/ngx_http_lua_subrequest.h             ../ngx_lua/src/ngx_http_lua_ndk.h             ../ngx_lua/src/ngx_http_lua_control.h             ../ngx_lua/src/ngx_http_lua_time.h             ../ngx_lua/src/ngx_http_lua_string.h             ../ngx_lua/src/ngx_http_lua_misc.h             ../ngx_lua/src/ngx_http_lua_variable.h             ../ngx_lua/src/ngx_http_lua_output.h             ../ngx_lua/src/ngx_http_lua_headers.h             ../ngx_lua/src/ngx_http_lua_uri.h             ../ngx_lua/src/ngx_http_lua_req_body.h             ../ngx_lua/src/ngx_http_lua_args.h             ../ngx_lua/src/ngx_http_lua_ctx.h             ../ngx_lua/src/ngx_http_lua_regex.h             ../ngx_lua/src/ngx_http_lua_common.h             ../ngx_lua/src/ngx_http_lua_directive.h             ../ngx_lua/src/ngx_http_lua_headers_out.h             ../ngx_lua/src/ngx_http_lua_headers_in.h             ../ngx_lua/src/ngx_http_lua_consts.h             ../ngx_lua/src/ngx_http_lua_exception.h             ../ngx_lua/src/ngx_http_lua_util.h             ../ngx_lua/src/ngx_http_lua_cache.h             ../ngx_lua/src/ngx_http_lua_contentby.h             ../ngx_lua/src/ngx_http_lua_rewriteby.h             ../ngx_lua/src/ngx_http_lua_accessby.h             ../ngx_lua/src/ngx_http_lua_setby.h             ../ngx_lua/src/ngx_http_lua_capturefilter.h             ../ngx_lua/src/ngx_http_lua_clfactory.h             ../ngx_lua/src/ngx_http_lua_pcrefix.h             ../ngx_lua/src/ngx_http_lua_headerfilterby.h             ../ngx_lua/src/ngx_http_lua_shdict.h             ../ngx_lua/src/ngx_http_lua_socket_tcp.h             ../ngx_lua/src/api/ngx_http_lua_api.h             ../ngx_lua/src/ngx_http_lua_logby.h             ../ngx_lua/src/ngx_http_lua_sleep.h             ../ngx_lua/src/ngx_http_lua_semaphore.h            ../ngx_lua/src/ngx_http_lua_coroutine.h             ../ngx_lua/src/ngx_http_lua_bodyfilterby.h             ../ngx_lua/src/ngx_http_lua_initby.h             ../ngx_lua/src/ngx_http_lua_initworkerby.h             ../ngx_lua/src/ngx_http_lua_socket_udp.h             ../ngx_lua/src/ngx_http_lua_req_method.h             ../ngx_lua/src/ngx_http_lua_phase.h             ../ngx_lua/src/ngx_http_lua_probe.h             ../ngx_lua/src/ngx_http_lua_uthread.h             ../ngx_lua/src/ngx_http_lua_timer.h             ../ngx_lua/src/ngx_http_lua_config.h             ../ngx_lua/src/ngx_http_lua_worker.h             ../ngx_lua/src/ngx_http_lua_ssl_certby.h             ../ngx_lua/src/ngx_http_lua_lex.h             ../ngx_lua/src/ngx_http_lua_balancer.h             ../ngx_lua/src/ngx_http_lua_ssl_session_storeby.h             ../ngx_lua/src/ngx_http_lua_ssl_session_fetchby.h             ../ngx_lua/src/ngx_http_lua_ssl.h             ../ngx_lua/src/ngx_http_lua_log_ringbuf.h                                                                                       ../headers-more-nginx-module-0.32/src/ddebug.h                                                 ../headers-more-nginx-module-0.32/src/ngx_http_headers_more_filter_module.h                    ../headers-more-nginx-module-0.32/src/ngx_http_headers_more_headers_in.h                       ../headers-more-nginx-module-0.32/src/ngx_http_headers_more_headers_out.h                      ../headers-more-nginx-module-0.32/src/ngx_http_headers_more_headers_in.h                       ../headers-more-nginx-module-0.32/src/ngx_http_headers_more_util.h                                                                                                         ../array-var-nginx-module-0.05/src/ddebug.h                                                 ../array-var-nginx-module-0.05/src/ngx_http_array_var_util.h                                 ../rds-json-nginx-module-0.14/src/ddebug.h ../rds-json-nginx-module-0.14/src/resty_dbd_stream.h ../rds-json-nginx-module-0.14/src/ngx_http_rds_json_filter_module.h ../rds-json-nginx-module-0.14/src/ngx_http_rds_json_processor.h ../rds-json-nginx-module-0.14/src/ngx_http_rds_json_util.h ../rds-json-nginx-module-0.14/src/ngx_http_rds.h ../rds-json-nginx-module-0.14/src/resty_dbd_stream.h ../rds-json-nginx-module-0.14/src/ngx_http_rds_json_output.h ../rds-json-nginx-module-0.14/src/ngx_http_rds_utils.h ../rds-json-nginx-module-0.14/src/ngx_http_rds_json_handler.h                                                                            ../redis2-nginx-module-0.14/src/ddebug.h                                                 ../redis2-nginx-module-0.14/src/ngx_http_redis2_module.h                                 ../redis2-nginx-module-0.14/src/ngx_http_redis2_handler.h                                ../redis2-nginx-module-0.14/src/ngx_http_redis2_reply.h                                  ../redis2-nginx-module-0.14/src/ngx_http_redis2_util.h                                    $(HTTP_DEPS) $(MAIL_DEPS) $(STREAM_DEPS)


build:	binary modules manpage

binary:	objs/nginx.exe

objs/nginx.exe:	objs/src/core/nginx.obj \
	objs/src/core/ngx_log.obj \
	objs/src/core/ngx_palloc.obj \
	objs/src/core/ngx_array.obj \
	objs/src/core/ngx_list.obj \
	objs/src/core/ngx_hash.obj \
	objs/src/core/ngx_buf.obj \
	objs/src/core/ngx_queue.obj \
	objs/src/core/ngx_output_chain.obj \
	objs/src/core/ngx_string.obj \
	objs/src/core/ngx_parse.obj \
	objs/src/core/ngx_parse_time.obj \
	objs/src/core/ngx_inet.obj \
	objs/src/core/ngx_file.obj \
	objs/src/core/ngx_crc32.obj \
	objs/src/core/ngx_murmurhash.obj \
	objs/src/core/ngx_md5.obj \
	objs/src/core/ngx_sha1.obj \
	objs/src/core/ngx_rbtree.obj \
	objs/src/core/ngx_radix_tree.obj \
	objs/src/core/ngx_slab.obj \
	objs/src/core/ngx_times.obj \
	objs/src/core/ngx_shmtx.obj \
	objs/src/core/ngx_connection.obj \
	objs/src/core/ngx_cycle.obj \
	objs/src/core/ngx_spinlock.obj \
	objs/src/core/ngx_rwlock.obj \
	objs/src/core/ngx_cpuinfo.obj \
	objs/src/core/ngx_conf_file.obj \
	objs/src/core/ngx_module.obj \
	objs/src/core/ngx_resolver.obj \
	objs/src/core/ngx_open_file_cache.obj \
	objs/src/core/ngx_crypt.obj \
	objs/src/core/ngx_proxy_protocol.obj \
	objs/src/core/ngx_syslog.obj \
	objs/src/event/ngx_event.obj \
	objs/src/event/ngx_event_timer.obj \
	objs/src/event/ngx_event_posted.obj \
	objs/src/event/ngx_event_accept.obj \
	objs/src/event/ngx_event_connect.obj \
	objs/src/event/ngx_event_pipe.obj \
	objs/src/os/win32/ngx_errno.obj \
	objs/src/os/win32/ngx_alloc.obj \
	objs/src/os/win32/ngx_files.obj \
	objs/src/os/win32/ngx_shmem.obj \
	objs/src/os/win32/ngx_time.obj \
	objs/src/os/win32/ngx_process.obj \
	objs/src/os/win32/ngx_thread.obj \
	objs/src/os/win32/ngx_socket.obj \
	objs/src/os/win32/ngx_wsarecv.obj \
	objs/src/os/win32/ngx_wsarecv_chain.obj \
	objs/src/os/win32/ngx_udp_wsarecv.obj \
	objs/src/os/win32/ngx_wsasend.obj \
	objs/src/os/win32/ngx_udp_wsasend.obj \
	objs/src/os/win32/ngx_wsasend_chain.obj \
	objs/src/os/win32/ngx_win32_init.obj \
	objs/src/os/win32/ngx_user.obj \
	objs/src/os/win32/ngx_dlopen.obj \
	objs/src/os/win32/ngx_event_log.obj \
	objs/src/os/win32/ngx_process_cycle.obj \
	objs/src/event/ngx_event_acceptex.obj \
	objs/src/event/modules/ngx_iocp_module.obj \
	objs/src/event/modules/ngx_win32_select_module.obj \
	objs/src/event/ngx_event_openssl.obj \
	objs/src/event/ngx_event_openssl_stapling.obj \
	objs/src/core/ngx_regex.obj \
	objs/src/http/ngx_http.obj \
	objs/src/http/ngx_http_core_module.obj \
	objs/src/http/ngx_http_special_response.obj \
	objs/src/http/ngx_http_request.obj \
	objs/src/http/ngx_http_parse.obj \
	objs/src/http/modules/ngx_http_log_module.obj \
	objs/src/http/ngx_http_request_body.obj \
	objs/src/http/ngx_http_variables.obj \
	objs/src/http/ngx_http_script.obj \
	objs/src/http/ngx_http_upstream.obj \
	objs/src/http/ngx_http_upstream_round_robin.obj \
	objs/src/http/ngx_http_file_cache.obj \
	objs/src/http/ngx_http_write_filter_module.obj \
	objs/src/http/ngx_http_header_filter_module.obj \
	objs/src/http/modules/ngx_http_chunked_filter_module.obj \
	objs/src/http/v2/ngx_http_v2_filter_module.obj \
	objs/src/http/modules/ngx_http_range_filter_module.obj \
	objs/src/http/modules/ngx_http_gzip_filter_module.obj \
	objs/src/http/ngx_http_postpone_filter_module.obj \
	objs/src/http/modules/ngx_http_ssi_filter_module.obj \
	objs/src/http/modules/ngx_http_charset_filter_module.obj \
	objs/src/http/modules/ngx_http_sub_filter_module.obj \
	objs/src/http/modules/ngx_http_addition_filter_module.obj \
	objs/src/http/modules/ngx_http_gunzip_filter_module.obj \
	objs/src/http/modules/ngx_http_userid_filter_module.obj \
	objs/src/http/modules/ngx_http_headers_filter_module.obj \
	objs/src/http/ngx_http_copy_filter_module.obj \
	objs/src/http/modules/ngx_http_not_modified_filter_module.obj \
	objs/src/http/modules/ngx_http_slice_filter_module.obj \
	objs/src/http/v2/ngx_http_v2.obj \
	objs/src/http/v2/ngx_http_v2_table.obj \
	objs/src/http/v2/ngx_http_v2_huff_decode.obj \
	objs/src/http/v2/ngx_http_v2_huff_encode.obj \
	objs/src/http/v2/ngx_http_v2_module.obj \
	objs/src/http/modules/ngx_http_static_module.obj \
	objs/src/http/modules/ngx_http_gzip_static_module.obj \
	objs/src/http/modules/ngx_http_dav_module.obj \
	objs/src/http/modules/ngx_http_autoindex_module.obj \
	objs/src/http/modules/ngx_http_index_module.obj \
	objs/src/http/modules/ngx_http_random_index_module.obj \
	objs/src/http/modules/ngx_http_mirror_module.obj \
	objs/src/http/modules/ngx_http_try_files_module.obj \
	objs/src/http/modules/ngx_http_auth_request_module.obj \
	objs/src/http/modules/ngx_http_auth_basic_module.obj \
	objs/src/http/modules/ngx_http_access_module.obj \
	objs/src/http/modules/ngx_http_limit_conn_module.obj \
	objs/src/http/modules/ngx_http_limit_req_module.obj \
	objs/src/http/modules/ngx_http_realip_module.obj \
	objs/src/http/modules/ngx_http_geo_module.obj \
	objs/src/http/modules/ngx_http_map_module.obj \
	objs/src/http/modules/ngx_http_split_clients_module.obj \
	objs/src/http/modules/ngx_http_referer_module.obj \
	objs/src/http/modules/ngx_http_rewrite_module.obj \
	objs/src/http/modules/ngx_http_ssl_module.obj \
	objs/src/http/modules/ngx_http_proxy_module.obj \
	objs/src/http/modules/ngx_http_fastcgi_module.obj \
	objs/src/http/modules/ngx_http_uwsgi_module.obj \
	objs/src/http/modules/ngx_http_scgi_module.obj \
	objs/src/http/modules/ngx_http_memcached_module.obj \
	objs/src/http/modules/ngx_http_empty_gif_module.obj \
	objs/src/http/modules/ngx_http_browser_module.obj \
	objs/src/http/modules/ngx_http_secure_link_module.obj \
	objs/src/http/modules/ngx_http_flv_module.obj \
	objs/src/http/modules/ngx_http_mp4_module.obj \
	objs/src/http/modules/ngx_http_upstream_hash_module.obj \
	objs/src/http/modules/ngx_http_upstream_ip_hash_module.obj \
	objs/src/http/modules/ngx_http_upstream_least_conn_module.obj \
	objs/src/http/modules/ngx_http_upstream_keepalive_module.obj \
	objs/src/http/modules/ngx_http_upstream_zone_module.obj \
	objs/src/http/modules/ngx_http_stub_status_module.obj \
	objs/src/mail/ngx_mail.obj \
	objs/src/mail/ngx_mail_core_module.obj \
	objs/src/mail/ngx_mail_handler.obj \
	objs/src/mail/ngx_mail_parse.obj \
	objs/src/mail/ngx_mail_ssl_module.obj \
	objs/src/mail/ngx_mail_pop3_module.obj \
	objs/src/mail/ngx_mail_pop3_handler.obj \
	objs/src/mail/ngx_mail_imap_module.obj \
	objs/src/mail/ngx_mail_imap_handler.obj \
	objs/src/mail/ngx_mail_smtp_module.obj \
	objs/src/mail/ngx_mail_smtp_handler.obj \
	objs/src/mail/ngx_mail_auth_http_module.obj \
	objs/src/mail/ngx_mail_proxy_module.obj \
	objs/src/stream/ngx_stream.obj \
	objs/src/stream/ngx_stream_variables.obj \
	objs/src/stream/ngx_stream_script.obj \
	objs/src/stream/ngx_stream_handler.obj \
	objs/src/stream/ngx_stream_core_module.obj \
	objs/src/stream/ngx_stream_log_module.obj \
	objs/src/stream/ngx_stream_proxy_module.obj \
	objs/src/stream/ngx_stream_upstream.obj \
	objs/src/stream/ngx_stream_upstream_round_robin.obj \
	objs/src/stream/ngx_stream_write_filter_module.obj \
	objs/src/stream/ngx_stream_ssl_module.obj \
	objs/src/stream/ngx_stream_limit_conn_module.obj \
	objs/src/stream/ngx_stream_access_module.obj \
	objs/src/stream/ngx_stream_geo_module.obj \
	objs/src/stream/ngx_stream_map_module.obj \
	objs/src/stream/ngx_stream_split_clients_module.obj \
	objs/src/stream/ngx_stream_return_module.obj \
	objs/src/stream/ngx_stream_upstream_hash_module.obj \
	objs/src/stream/ngx_stream_upstream_least_conn_module.obj \
	objs/src/stream/ngx_stream_upstream_zone_module.obj \
	objs/addon/src/ndk.obj \
	objs/addon/src/ngx_http_echo_module.obj \
	objs/addon/src/ngx_http_echo_util.obj \
	objs/addon/src/ngx_http_echo_timer.obj \
	objs/addon/src/ngx_http_echo_var.obj \
	objs/addon/src/ngx_http_echo_handler.obj \
	objs/addon/src/ngx_http_echo_filter.obj \
	objs/addon/src/ngx_http_echo_sleep.obj \
	objs/addon/src/ngx_http_echo_location.obj \
	objs/addon/src/ngx_http_echo_echo.obj \
	objs/addon/src/ngx_http_echo_request_info.obj \
	objs/addon/src/ngx_http_echo_subrequest.obj \
	objs/addon/src/ngx_http_echo_foreach.obj \
	objs/addon/src/ngx_coolkit_handlers.obj \
	objs/addon/src/ngx_coolkit_module.obj \
	objs/addon/src/ngx_coolkit_variables.obj \
	objs/addon/src/ngx_http_set_base32.obj \
	objs/addon/src/ngx_http_set_default_value.obj \
	objs/addon/src/ngx_http_set_hashed_upstream.obj \
	objs/addon/src/ngx_http_set_quote_sql.obj \
	objs/addon/src/ngx_http_set_quote_json.obj \
	objs/addon/src/ngx_http_set_unescape_uri.obj \
	objs/addon/src/ngx_http_set_misc_module.obj \
	objs/addon/src/ngx_http_set_escape_uri.obj \
	objs/addon/src/ngx_http_set_hash.obj \
	objs/addon/src/ngx_http_set_local_today.obj \
	objs/addon/src/ngx_http_set_hex.obj \
	objs/addon/src/ngx_http_set_base64.obj \
	objs/addon/src/ngx_http_set_random.obj \
	objs/addon/src/ngx_http_set_secure_random.obj \
	objs/addon/src/ngx_http_set_rotate.obj \
	objs/addon/src/ngx_http_set_hmac.obj \
	objs/addon/src/ngx_postgres_escape.obj \
	objs/addon/src/ngx_postgres_handler.obj \
	objs/addon/src/ngx_postgres_keepalive.obj \
	objs/addon/src/ngx_postgres_module.obj \
	objs/addon/src/ngx_postgres_output.obj \
	objs/addon/src/ngx_postgres_processor.obj \
	objs/addon/src/ngx_postgres_rewrite.obj \
	objs/addon/src/ngx_postgres_upstream.obj \
	objs/addon/src/ngx_postgres_util.obj \
	objs/addon/src/ngx_postgres_variable.obj \
	objs/addon/src/ngx_http_form_input_module.obj \
	objs/addon/src/ngx_http_encrypted_session_module.obj \
	objs/addon/src/ngx_http_encrypted_session_cipher.obj \
	objs/addon/src/ngx_http_lua_script.obj \
	objs/addon/src/ngx_http_lua_log.obj \
	objs/addon/src/ngx_http_lua_subrequest.obj \
	objs/addon/src/ngx_http_lua_ndk.obj \
	objs/addon/src/ngx_http_lua_control.obj \
	objs/addon/src/ngx_http_lua_time.obj \
	objs/addon/src/ngx_http_lua_misc.obj \
	objs/addon/src/ngx_http_lua_variable.obj \
	objs/addon/src/ngx_http_lua_string.obj \
	objs/addon/src/ngx_http_lua_output.obj \
	objs/addon/src/ngx_http_lua_headers.obj \
	objs/addon/src/ngx_http_lua_req_body.obj \
	objs/addon/src/ngx_http_lua_uri.obj \
	objs/addon/src/ngx_http_lua_args.obj \
	objs/addon/src/ngx_http_lua_ctx.obj \
	objs/addon/src/ngx_http_lua_regex.obj \
	objs/addon/src/ngx_http_lua_module.obj \
	objs/addon/src/ngx_http_lua_headers_out.obj \
	objs/addon/src/ngx_http_lua_headers_in.obj \
	objs/addon/src/ngx_http_lua_directive.obj \
	objs/addon/src/ngx_http_lua_consts.obj \
	objs/addon/src/ngx_http_lua_exception.obj \
	objs/addon/src/ngx_http_lua_util.obj \
	objs/addon/src/ngx_http_lua_cache.obj \
	objs/addon/src/ngx_http_lua_contentby.obj \
	objs/addon/src/ngx_http_lua_rewriteby.obj \
	objs/addon/src/ngx_http_lua_accessby.obj \
	objs/addon/src/ngx_http_lua_setby.obj \
	objs/addon/src/ngx_http_lua_capturefilter.obj \
	objs/addon/src/ngx_http_lua_clfactory.obj \
	objs/addon/src/ngx_http_lua_pcrefix.obj \
	objs/addon/src/ngx_http_lua_headerfilterby.obj \
	objs/addon/src/ngx_http_lua_shdict.obj \
	objs/addon/src/ngx_http_lua_socket_tcp.obj \
	objs/addon/src/ngx_http_lua_api.obj \
	objs/addon/src/ngx_http_lua_logby.obj \
	objs/addon/src/ngx_http_lua_sleep.obj \
	objs/addon/src/ngx_http_lua_semaphore.obj \
	objs/addon/src/ngx_http_lua_coroutine.obj \
	objs/addon/src/ngx_http_lua_bodyfilterby.obj \
	objs/addon/src/ngx_http_lua_initby.obj \
	objs/addon/src/ngx_http_lua_initworkerby.obj \
	objs/addon/src/ngx_http_lua_socket_udp.obj \
	objs/addon/src/ngx_http_lua_req_method.obj \
	objs/addon/src/ngx_http_lua_phase.obj \
	objs/addon/src/ngx_http_lua_uthread.obj \
	objs/addon/src/ngx_http_lua_timer.obj \
	objs/addon/src/ngx_http_lua_config.obj \
	objs/addon/src/ngx_http_lua_worker.obj \
	objs/addon/src/ngx_http_lua_ssl_certby.obj \
	objs/addon/src/ngx_http_lua_ssl_ocsp.obj \
	objs/addon/src/ngx_http_lua_lex.obj \
	objs/addon/src/ngx_http_lua_balancer.obj \
	objs/addon/src/ngx_http_lua_ssl_session_storeby.obj \
	objs/addon/src/ngx_http_lua_ssl_session_fetchby.obj \
	objs/addon/src/ngx_http_lua_ssl.obj \
	objs/addon/src/ngx_http_lua_log_ringbuf.obj \
	objs/addon/src/ngx_http_lua_upstream_module.obj \
	objs/addon/src/ngx_http_headers_more_filter_module.obj \
	objs/addon/src/ngx_http_headers_more_headers_out.obj \
	objs/addon/src/ngx_http_headers_more_headers_in.obj \
	objs/addon/src/ngx_http_headers_more_util.obj \
	objs/addon/src/ngx_http_array_var_module.obj \
	objs/addon/src/ngx_http_array_var_util.obj \
	objs/addon/nginx-http-concat-module/ngx_http_concat_module.obj \
	objs/addon/src/ngx_http_rds_json_filter_module.obj \
	objs/addon/src/ngx_http_rds_json_processor.obj \
	objs/addon/src/ngx_http_rds_json_util.obj \
	objs/addon/src/ngx_http_rds_json_output.obj \
	objs/addon/src/ngx_http_rds_json_handler.obj \
	objs/addon/src/ngx_http_redis2_module.obj \
	objs/addon/src/ngx_http_redis2_handler.obj \
	objs/addon/src/ngx_http_redis2_reply.obj \
	objs/addon/src/ngx_http_redis2_util.obj \
	objs/ngx_modules.obj \
	objs/nginx.res \
	objs/lib/pcre/pcre.lib \
	objs/lib/zlib/zlib.lib
	$(LINK) @<<
	-Feobjs/nginx
	objs/src/core/nginx.obj 
	objs/src/core/ngx_log.obj 
	objs/src/core/ngx_palloc.obj 
	objs/src/core/ngx_array.obj 
	objs/src/core/ngx_list.obj 
	objs/src/core/ngx_hash.obj 
	objs/src/core/ngx_buf.obj 
	objs/src/core/ngx_queue.obj 
	objs/src/core/ngx_output_chain.obj 
	objs/src/core/ngx_string.obj 
	objs/src/core/ngx_parse.obj 
	objs/src/core/ngx_parse_time.obj 
	objs/src/core/ngx_inet.obj 
	objs/src/core/ngx_file.obj 
	objs/src/core/ngx_crc32.obj 
	objs/src/core/ngx_murmurhash.obj 
	objs/src/core/ngx_md5.obj 
	objs/src/core/ngx_sha1.obj 
	objs/src/core/ngx_rbtree.obj 
	objs/src/core/ngx_radix_tree.obj 
	objs/src/core/ngx_slab.obj 
	objs/src/core/ngx_times.obj 
	objs/src/core/ngx_shmtx.obj 
	objs/src/core/ngx_connection.obj 
	objs/src/core/ngx_cycle.obj 
	objs/src/core/ngx_spinlock.obj 
	objs/src/core/ngx_rwlock.obj 
	objs/src/core/ngx_cpuinfo.obj 
	objs/src/core/ngx_conf_file.obj 
	objs/src/core/ngx_module.obj 
	objs/src/core/ngx_resolver.obj 
	objs/src/core/ngx_open_file_cache.obj 
	objs/src/core/ngx_crypt.obj 
	objs/src/core/ngx_proxy_protocol.obj 
	objs/src/core/ngx_syslog.obj 
	objs/src/event/ngx_event.obj 
	objs/src/event/ngx_event_timer.obj 
	objs/src/event/ngx_event_posted.obj 
	objs/src/event/ngx_event_accept.obj 
	objs/src/event/ngx_event_connect.obj 
	objs/src/event/ngx_event_pipe.obj 
	objs/src/os/win32/ngx_errno.obj 
	objs/src/os/win32/ngx_alloc.obj 
	objs/src/os/win32/ngx_files.obj 
	objs/src/os/win32/ngx_shmem.obj 
	objs/src/os/win32/ngx_time.obj 
	objs/src/os/win32/ngx_process.obj 
	objs/src/os/win32/ngx_thread.obj 
	objs/src/os/win32/ngx_socket.obj 
	objs/src/os/win32/ngx_wsarecv.obj 
	objs/src/os/win32/ngx_wsarecv_chain.obj 
	objs/src/os/win32/ngx_udp_wsarecv.obj 
	objs/src/os/win32/ngx_wsasend.obj 
	objs/src/os/win32/ngx_udp_wsasend.obj 
	objs/src/os/win32/ngx_wsasend_chain.obj 
	objs/src/os/win32/ngx_win32_init.obj 
	objs/src/os/win32/ngx_user.obj 
	objs/src/os/win32/ngx_dlopen.obj 
	objs/src/os/win32/ngx_event_log.obj 
	objs/src/os/win32/ngx_process_cycle.obj 
	objs/src/event/ngx_event_acceptex.obj 
	objs/src/event/modules/ngx_iocp_module.obj 
	objs/src/event/modules/ngx_win32_select_module.obj 
	objs/src/event/ngx_event_openssl.obj 
	objs/src/event/ngx_event_openssl_stapling.obj 
	objs/src/core/ngx_regex.obj 
	objs/src/http/ngx_http.obj 
	objs/src/http/ngx_http_core_module.obj 
	objs/src/http/ngx_http_special_response.obj 
	objs/src/http/ngx_http_request.obj 
	objs/src/http/ngx_http_parse.obj 
	objs/src/http/modules/ngx_http_log_module.obj 
	objs/src/http/ngx_http_request_body.obj 
	objs/src/http/ngx_http_variables.obj 
	objs/src/http/ngx_http_script.obj 
	objs/src/http/ngx_http_upstream.obj 
	objs/src/http/ngx_http_upstream_round_robin.obj 
	objs/src/http/ngx_http_file_cache.obj 
	objs/src/http/ngx_http_write_filter_module.obj 
	objs/src/http/ngx_http_header_filter_module.obj 
	objs/src/http/modules/ngx_http_chunked_filter_module.obj 
	objs/src/http/v2/ngx_http_v2_filter_module.obj 
	objs/src/http/modules/ngx_http_range_filter_module.obj 
	objs/src/http/modules/ngx_http_gzip_filter_module.obj 
	objs/src/http/ngx_http_postpone_filter_module.obj 
	objs/src/http/modules/ngx_http_ssi_filter_module.obj 
	objs/src/http/modules/ngx_http_charset_filter_module.obj 
	objs/src/http/modules/ngx_http_sub_filter_module.obj 
	objs/src/http/modules/ngx_http_addition_filter_module.obj 
	objs/src/http/modules/ngx_http_gunzip_filter_module.obj 
	objs/src/http/modules/ngx_http_userid_filter_module.obj 
	objs/src/http/modules/ngx_http_headers_filter_module.obj 
	objs/src/http/ngx_http_copy_filter_module.obj 
	objs/src/http/modules/ngx_http_not_modified_filter_module.obj 
	objs/src/http/modules/ngx_http_slice_filter_module.obj 
	objs/src/http/v2/ngx_http_v2.obj 
	objs/src/http/v2/ngx_http_v2_table.obj 
	objs/src/http/v2/ngx_http_v2_huff_decode.obj 
	objs/src/http/v2/ngx_http_v2_huff_encode.obj 
	objs/src/http/v2/ngx_http_v2_module.obj 
	objs/src/http/modules/ngx_http_static_module.obj 
	objs/src/http/modules/ngx_http_gzip_static_module.obj 
	objs/src/http/modules/ngx_http_dav_module.obj 
	objs/src/http/modules/ngx_http_autoindex_module.obj 
	objs/src/http/modules/ngx_http_index_module.obj 
	objs/src/http/modules/ngx_http_random_index_module.obj 
	objs/src/http/modules/ngx_http_mirror_module.obj 
	objs/src/http/modules/ngx_http_try_files_module.obj 
	objs/src/http/modules/ngx_http_auth_request_module.obj 
	objs/src/http/modules/ngx_http_auth_basic_module.obj 
	objs/src/http/modules/ngx_http_access_module.obj 
	objs/src/http/modules/ngx_http_limit_conn_module.obj 
	objs/src/http/modules/ngx_http_limit_req_module.obj 
	objs/src/http/modules/ngx_http_realip_module.obj 
	objs/src/http/modules/ngx_http_geo_module.obj 
	objs/src/http/modules/ngx_http_map_module.obj 
	objs/src/http/modules/ngx_http_split_clients_module.obj 
	objs/src/http/modules/ngx_http_referer_module.obj 
	objs/src/http/modules/ngx_http_rewrite_module.obj 
	objs/src/http/modules/ngx_http_ssl_module.obj 
	objs/src/http/modules/ngx_http_proxy_module.obj 
	objs/src/http/modules/ngx_http_fastcgi_module.obj 
	objs/src/http/modules/ngx_http_uwsgi_module.obj 
	objs/src/http/modules/ngx_http_scgi_module.obj 
	objs/src/http/modules/ngx_http_memcached_module.obj 
	objs/src/http/modules/ngx_http_empty_gif_module.obj 
	objs/src/http/modules/ngx_http_browser_module.obj 
	objs/src/http/modules/ngx_http_secure_link_module.obj 
	objs/src/http/modules/ngx_http_flv_module.obj 
	objs/src/http/modules/ngx_http_mp4_module.obj 
	objs/src/http/modules/ngx_http_upstream_hash_module.obj 
	objs/src/http/modules/ngx_http_upstream_ip_hash_module.obj 
	objs/src/http/modules/ngx_http_upstream_least_conn_module.obj 
	objs/src/http/modules/ngx_http_upstream_keepalive_module.obj 
	objs/src/http/modules/ngx_http_upstream_zone_module.obj 
	objs/src/http/modules/ngx_http_stub_status_module.obj 
	objs/src/mail/ngx_mail.obj 
	objs/src/mail/ngx_mail_core_module.obj 
	objs/src/mail/ngx_mail_handler.obj 
	objs/src/mail/ngx_mail_parse.obj 
	objs/src/mail/ngx_mail_ssl_module.obj 
	objs/src/mail/ngx_mail_pop3_module.obj 
	objs/src/mail/ngx_mail_pop3_handler.obj 
	objs/src/mail/ngx_mail_imap_module.obj 
	objs/src/mail/ngx_mail_imap_handler.obj 
	objs/src/mail/ngx_mail_smtp_module.obj 
	objs/src/mail/ngx_mail_smtp_handler.obj 
	objs/src/mail/ngx_mail_auth_http_module.obj 
	objs/src/mail/ngx_mail_proxy_module.obj 
	objs/src/stream/ngx_stream.obj 
	objs/src/stream/ngx_stream_variables.obj 
	objs/src/stream/ngx_stream_script.obj 
	objs/src/stream/ngx_stream_handler.obj 
	objs/src/stream/ngx_stream_core_module.obj 
	objs/src/stream/ngx_stream_log_module.obj 
	objs/src/stream/ngx_stream_proxy_module.obj 
	objs/src/stream/ngx_stream_upstream.obj 
	objs/src/stream/ngx_stream_upstream_round_robin.obj 
	objs/src/stream/ngx_stream_write_filter_module.obj 
	objs/src/stream/ngx_stream_ssl_module.obj 
	objs/src/stream/ngx_stream_limit_conn_module.obj 
	objs/src/stream/ngx_stream_access_module.obj 
	objs/src/stream/ngx_stream_geo_module.obj 
	objs/src/stream/ngx_stream_map_module.obj 
	objs/src/stream/ngx_stream_split_clients_module.obj 
	objs/src/stream/ngx_stream_return_module.obj 
	objs/src/stream/ngx_stream_upstream_hash_module.obj 
	objs/src/stream/ngx_stream_upstream_least_conn_module.obj 
	objs/src/stream/ngx_stream_upstream_zone_module.obj 
	objs/addon/src/ndk.obj 
	objs/addon/src/ngx_http_echo_module.obj 
	objs/addon/src/ngx_http_echo_util.obj 
	objs/addon/src/ngx_http_echo_timer.obj 
	objs/addon/src/ngx_http_echo_var.obj 
	objs/addon/src/ngx_http_echo_handler.obj 
	objs/addon/src/ngx_http_echo_filter.obj 
	objs/addon/src/ngx_http_echo_sleep.obj 
	objs/addon/src/ngx_http_echo_location.obj 
	objs/addon/src/ngx_http_echo_echo.obj 
	objs/addon/src/ngx_http_echo_request_info.obj 
	objs/addon/src/ngx_http_echo_subrequest.obj 
	objs/addon/src/ngx_http_echo_foreach.obj 
	objs/addon/src/ngx_coolkit_handlers.obj 
	objs/addon/src/ngx_coolkit_module.obj 
	objs/addon/src/ngx_coolkit_variables.obj 
	objs/addon/src/ngx_http_set_base32.obj 
	objs/addon/src/ngx_http_set_default_value.obj 
	objs/addon/src/ngx_http_set_hashed_upstream.obj 
	objs/addon/src/ngx_http_set_quote_sql.obj 
	objs/addon/src/ngx_http_set_quote_json.obj 
	objs/addon/src/ngx_http_set_unescape_uri.obj 
	objs/addon/src/ngx_http_set_misc_module.obj 
	objs/addon/src/ngx_http_set_escape_uri.obj 
	objs/addon/src/ngx_http_set_hash.obj 
	objs/addon/src/ngx_http_set_local_today.obj 
	objs/addon/src/ngx_http_set_hex.obj 
	objs/addon/src/ngx_http_set_base64.obj 
	objs/addon/src/ngx_http_set_random.obj 
	objs/addon/src/ngx_http_set_secure_random.obj 
	objs/addon/src/ngx_http_set_rotate.obj 
	objs/addon/src/ngx_http_set_hmac.obj 
	objs/addon/src/ngx_postgres_escape.obj 
	objs/addon/src/ngx_postgres_handler.obj 
	objs/addon/src/ngx_postgres_keepalive.obj 
	objs/addon/src/ngx_postgres_module.obj 
	objs/addon/src/ngx_postgres_output.obj 
	objs/addon/src/ngx_postgres_processor.obj 
	objs/addon/src/ngx_postgres_rewrite.obj 
	objs/addon/src/ngx_postgres_upstream.obj 
	objs/addon/src/ngx_postgres_util.obj 
	objs/addon/src/ngx_postgres_variable.obj 
	objs/addon/src/ngx_http_form_input_module.obj 
	objs/addon/src/ngx_http_encrypted_session_module.obj 
	objs/addon/src/ngx_http_encrypted_session_cipher.obj 
	objs/addon/src/ngx_http_lua_script.obj 
	objs/addon/src/ngx_http_lua_log.obj 
	objs/addon/src/ngx_http_lua_subrequest.obj 
	objs/addon/src/ngx_http_lua_ndk.obj 
	objs/addon/src/ngx_http_lua_control.obj 
	objs/addon/src/ngx_http_lua_time.obj 
	objs/addon/src/ngx_http_lua_misc.obj 
	objs/addon/src/ngx_http_lua_variable.obj 
	objs/addon/src/ngx_http_lua_string.obj 
	objs/addon/src/ngx_http_lua_output.obj 
	objs/addon/src/ngx_http_lua_headers.obj 
	objs/addon/src/ngx_http_lua_req_body.obj 
	objs/addon/src/ngx_http_lua_uri.obj 
	objs/addon/src/ngx_http_lua_args.obj 
	objs/addon/src/ngx_http_lua_ctx.obj 
	objs/addon/src/ngx_http_lua_regex.obj 
	objs/addon/src/ngx_http_lua_module.obj 
	objs/addon/src/ngx_http_lua_headers_out.obj 
	objs/addon/src/ngx_http_lua_headers_in.obj 
	objs/addon/src/ngx_http_lua_directive.obj 
	objs/addon/src/ngx_http_lua_consts.obj 
	objs/addon/src/ngx_http_lua_exception.obj 
	objs/addon/src/ngx_http_lua_util.obj 
	objs/addon/src/ngx_http_lua_cache.obj 
	objs/addon/src/ngx_http_lua_contentby.obj 
	objs/addon/src/ngx_http_lua_rewriteby.obj 
	objs/addon/src/ngx_http_lua_accessby.obj 
	objs/addon/src/ngx_http_lua_setby.obj 
	objs/addon/src/ngx_http_lua_capturefilter.obj 
	objs/addon/src/ngx_http_lua_clfactory.obj 
	objs/addon/src/ngx_http_lua_pcrefix.obj 
	objs/addon/src/ngx_http_lua_headerfilterby.obj 
	objs/addon/src/ngx_http_lua_shdict.obj 
	objs/addon/src/ngx_http_lua_socket_tcp.obj 
	objs/addon/src/ngx_http_lua_api.obj 
	objs/addon/src/ngx_http_lua_logby.obj 
	objs/addon/src/ngx_http_lua_sleep.obj 
	objs/addon/src/ngx_http_lua_semaphore.obj 
	objs/addon/src/ngx_http_lua_coroutine.obj 
	objs/addon/src/ngx_http_lua_bodyfilterby.obj 
	objs/addon/src/ngx_http_lua_initby.obj 
	objs/addon/src/ngx_http_lua_initworkerby.obj 
	objs/addon/src/ngx_http_lua_socket_udp.obj 
	objs/addon/src/ngx_http_lua_req_method.obj 
	objs/addon/src/ngx_http_lua_phase.obj 
	objs/addon/src/ngx_http_lua_uthread.obj 
	objs/addon/src/ngx_http_lua_timer.obj 
	objs/addon/src/ngx_http_lua_config.obj 
	objs/addon/src/ngx_http_lua_worker.obj 
	objs/addon/src/ngx_http_lua_ssl_certby.obj 
	objs/addon/src/ngx_http_lua_ssl_ocsp.obj 
	objs/addon/src/ngx_http_lua_lex.obj 
	objs/addon/src/ngx_http_lua_balancer.obj 
	objs/addon/src/ngx_http_lua_ssl_session_storeby.obj 
	objs/addon/src/ngx_http_lua_ssl_session_fetchby.obj 
	objs/addon/src/ngx_http_lua_ssl.obj 
	objs/addon/src/ngx_http_lua_log_ringbuf.obj 
	objs/addon/src/ngx_http_lua_upstream_module.obj 
	objs/addon/src/ngx_http_headers_more_filter_module.obj 
	objs/addon/src/ngx_http_headers_more_headers_out.obj 
	objs/addon/src/ngx_http_headers_more_headers_in.obj 
	objs/addon/src/ngx_http_headers_more_util.obj 
	objs/addon/src/ngx_http_array_var_module.obj 
	objs/addon/src/ngx_http_array_var_util.obj 
	objs/addon/nginx-http-concat-module/ngx_http_concat_module.obj 
	objs/addon/src/ngx_http_rds_json_filter_module.obj 
	objs/addon/src/ngx_http_rds_json_processor.obj 
	objs/addon/src/ngx_http_rds_json_util.obj 
	objs/addon/src/ngx_http_rds_json_output.obj 
	objs/addon/src/ngx_http_rds_json_handler.obj 
	objs/addon/src/ngx_http_redis2_module.obj 
	objs/addon/src/ngx_http_redis2_handler.obj 
	objs/addon/src/ngx_http_redis2_reply.obj 
	objs/addon/src/ngx_http_redis2_util.obj 
	objs/ngx_modules.obj 
	-L../luajit-root/luajit/lib kernel32.lib user32.lib advapi32.lib ws2_32.lib ../ngx_postgres-1.0/lib/libpq.lib -L../luajit-root/luajit/lib ../luajit-root/luajit/lib/lua51.lib objs/lib/pcre/pcre.lib objs/lib/openssl/openssl/lib/ssleay32.lib objs/lib/openssl/openssl/lib/libeay32.lib gdi32.lib crypt32.lib objs/lib/zlib/zlib.lib 
	objs/nginx.res -link -verbose:lib -def:nginx.def -debug
	
<<


	mt -manifest objs/crt.xml -outputresource:$@;1

modules:

objs/ngx_modules.obj:	$(CORE_DEPS) \
	objs/ngx_modules.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/ngx_modules.obj \
		objs/ngx_modules.c


objs/src/core/nginx.obj:	$(CORE_DEPS) \
	src/core/nginx.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/nginx.obj \
		src/core/nginx.c


objs/src/core/ngx_log.obj:	$(CORE_DEPS) \
	src/core/ngx_log.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_log.obj \
		src/core/ngx_log.c


objs/src/core/ngx_palloc.obj:	$(CORE_DEPS) \
	src/core/ngx_palloc.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_palloc.obj \
		src/core/ngx_palloc.c


objs/src/core/ngx_array.obj:	$(CORE_DEPS) \
	src/core/ngx_array.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_array.obj \
		src/core/ngx_array.c


objs/src/core/ngx_list.obj:	$(CORE_DEPS) \
	src/core/ngx_list.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_list.obj \
		src/core/ngx_list.c


objs/src/core/ngx_hash.obj:	$(CORE_DEPS) \
	src/core/ngx_hash.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_hash.obj \
		src/core/ngx_hash.c


objs/src/core/ngx_buf.obj:	$(CORE_DEPS) \
	src/core/ngx_buf.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_buf.obj \
		src/core/ngx_buf.c


objs/src/core/ngx_queue.obj:	$(CORE_DEPS) \
	src/core/ngx_queue.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_queue.obj \
		src/core/ngx_queue.c


objs/src/core/ngx_output_chain.obj:	$(CORE_DEPS) \
	src/core/ngx_output_chain.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_output_chain.obj \
		src/core/ngx_output_chain.c


objs/src/core/ngx_string.obj:	$(CORE_DEPS) \
	src/core/ngx_string.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_string.obj \
		src/core/ngx_string.c


objs/src/core/ngx_parse.obj:	$(CORE_DEPS) \
	src/core/ngx_parse.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_parse.obj \
		src/core/ngx_parse.c


objs/src/core/ngx_parse_time.obj:	$(CORE_DEPS) \
	src/core/ngx_parse_time.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_parse_time.obj \
		src/core/ngx_parse_time.c


objs/src/core/ngx_inet.obj:	$(CORE_DEPS) \
	src/core/ngx_inet.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_inet.obj \
		src/core/ngx_inet.c


objs/src/core/ngx_file.obj:	$(CORE_DEPS) \
	src/core/ngx_file.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_file.obj \
		src/core/ngx_file.c


objs/src/core/ngx_crc32.obj:	$(CORE_DEPS) \
	src/core/ngx_crc32.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_crc32.obj \
		src/core/ngx_crc32.c


objs/src/core/ngx_murmurhash.obj:	$(CORE_DEPS) \
	src/core/ngx_murmurhash.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_murmurhash.obj \
		src/core/ngx_murmurhash.c


objs/src/core/ngx_md5.obj:	$(CORE_DEPS) \
	src/core/ngx_md5.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_md5.obj \
		src/core/ngx_md5.c


objs/src/core/ngx_sha1.obj:	$(CORE_DEPS) \
	src/core/ngx_sha1.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_sha1.obj \
		src/core/ngx_sha1.c


objs/src/core/ngx_rbtree.obj:	$(CORE_DEPS) \
	src/core/ngx_rbtree.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_rbtree.obj \
		src/core/ngx_rbtree.c


objs/src/core/ngx_radix_tree.obj:	$(CORE_DEPS) \
	src/core/ngx_radix_tree.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_radix_tree.obj \
		src/core/ngx_radix_tree.c


objs/src/core/ngx_slab.obj:	$(CORE_DEPS) \
	src/core/ngx_slab.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_slab.obj \
		src/core/ngx_slab.c


objs/src/core/ngx_times.obj:	$(CORE_DEPS) \
	src/core/ngx_times.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_times.obj \
		src/core/ngx_times.c


objs/src/core/ngx_shmtx.obj:	$(CORE_DEPS) \
	src/core/ngx_shmtx.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_shmtx.obj \
		src/core/ngx_shmtx.c


objs/src/core/ngx_connection.obj:	$(CORE_DEPS) \
	src/core/ngx_connection.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_connection.obj \
		src/core/ngx_connection.c


objs/src/core/ngx_cycle.obj:	$(CORE_DEPS) \
	src/core/ngx_cycle.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_cycle.obj \
		src/core/ngx_cycle.c


objs/src/core/ngx_spinlock.obj:	$(CORE_DEPS) \
	src/core/ngx_spinlock.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_spinlock.obj \
		src/core/ngx_spinlock.c


objs/src/core/ngx_rwlock.obj:	$(CORE_DEPS) \
	src/core/ngx_rwlock.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_rwlock.obj \
		src/core/ngx_rwlock.c


objs/src/core/ngx_cpuinfo.obj:	$(CORE_DEPS) \
	src/core/ngx_cpuinfo.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_cpuinfo.obj \
		src/core/ngx_cpuinfo.c


objs/src/core/ngx_conf_file.obj:	$(CORE_DEPS) \
	src/core/ngx_conf_file.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_conf_file.obj \
		src/core/ngx_conf_file.c


objs/src/core/ngx_module.obj:	$(CORE_DEPS) \
	src/core/ngx_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_module.obj \
		src/core/ngx_module.c


objs/src/core/ngx_resolver.obj:	$(CORE_DEPS) \
	src/core/ngx_resolver.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_resolver.obj \
		src/core/ngx_resolver.c


objs/src/core/ngx_open_file_cache.obj:	$(CORE_DEPS) \
	src/core/ngx_open_file_cache.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_open_file_cache.obj \
		src/core/ngx_open_file_cache.c


objs/src/core/ngx_crypt.obj:	$(CORE_DEPS) \
	src/core/ngx_crypt.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_crypt.obj \
		src/core/ngx_crypt.c


objs/src/core/ngx_proxy_protocol.obj:	$(CORE_DEPS) \
	src/core/ngx_proxy_protocol.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_proxy_protocol.obj \
		src/core/ngx_proxy_protocol.c


objs/src/core/ngx_syslog.obj:	$(CORE_DEPS) \
	src/core/ngx_syslog.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_syslog.obj \
		src/core/ngx_syslog.c


objs/src/event/ngx_event.obj:	$(CORE_DEPS) \
	src/event/ngx_event.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event.obj \
		src/event/ngx_event.c


objs/src/event/ngx_event_timer.obj:	$(CORE_DEPS) \
	src/event/ngx_event_timer.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event_timer.obj \
		src/event/ngx_event_timer.c


objs/src/event/ngx_event_posted.obj:	$(CORE_DEPS) \
	src/event/ngx_event_posted.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event_posted.obj \
		src/event/ngx_event_posted.c


objs/src/event/ngx_event_accept.obj:	$(CORE_DEPS) \
	src/event/ngx_event_accept.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event_accept.obj \
		src/event/ngx_event_accept.c


objs/src/event/ngx_event_connect.obj:	$(CORE_DEPS) \
	src/event/ngx_event_connect.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event_connect.obj \
		src/event/ngx_event_connect.c


objs/src/event/ngx_event_pipe.obj:	$(CORE_DEPS) \
	src/event/ngx_event_pipe.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event_pipe.obj \
		src/event/ngx_event_pipe.c


objs/src/os/win32/ngx_errno.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_errno.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_errno.obj \
		src/os/win32/ngx_errno.c


objs/src/os/win32/ngx_alloc.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_alloc.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_alloc.obj \
		src/os/win32/ngx_alloc.c


objs/src/os/win32/ngx_files.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_files.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_files.obj \
		src/os/win32/ngx_files.c


objs/src/os/win32/ngx_shmem.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_shmem.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_shmem.obj \
		src/os/win32/ngx_shmem.c


objs/src/os/win32/ngx_time.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_time.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_time.obj \
		src/os/win32/ngx_time.c


objs/src/os/win32/ngx_process.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_process.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_process.obj \
		src/os/win32/ngx_process.c


objs/src/os/win32/ngx_thread.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_thread.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_thread.obj \
		src/os/win32/ngx_thread.c


objs/src/os/win32/ngx_socket.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_socket.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_socket.obj \
		src/os/win32/ngx_socket.c


objs/src/os/win32/ngx_wsarecv.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_wsarecv.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_wsarecv.obj \
		src/os/win32/ngx_wsarecv.c


objs/src/os/win32/ngx_wsarecv_chain.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_wsarecv_chain.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_wsarecv_chain.obj \
		src/os/win32/ngx_wsarecv_chain.c


objs/src/os/win32/ngx_udp_wsarecv.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_udp_wsarecv.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_udp_wsarecv.obj \
		src/os/win32/ngx_udp_wsarecv.c


objs/src/os/win32/ngx_wsasend.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_wsasend.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_wsasend.obj \
		src/os/win32/ngx_wsasend.c


objs/src/os/win32/ngx_udp_wsasend.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_udp_wsasend.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_udp_wsasend.obj \
		src/os/win32/ngx_udp_wsasend.c


objs/src/os/win32/ngx_wsasend_chain.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_wsasend_chain.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_wsasend_chain.obj \
		src/os/win32/ngx_wsasend_chain.c


objs/src/os/win32/ngx_win32_init.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_win32_init.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_win32_init.obj \
		src/os/win32/ngx_win32_init.c


objs/src/os/win32/ngx_user.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_user.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_user.obj \
		src/os/win32/ngx_user.c


objs/src/os/win32/ngx_dlopen.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_dlopen.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_dlopen.obj \
		src/os/win32/ngx_dlopen.c


objs/src/os/win32/ngx_event_log.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_event_log.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_event_log.obj \
		src/os/win32/ngx_event_log.c


objs/src/os/win32/ngx_process_cycle.obj:	$(CORE_DEPS) \
	src/os/win32/ngx_process_cycle.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/os/win32/ngx_process_cycle.obj \
		src/os/win32/ngx_process_cycle.c


objs/src/event/ngx_event_acceptex.obj:	$(CORE_DEPS) \
	src/event/ngx_event_acceptex.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event_acceptex.obj \
		src/event/ngx_event_acceptex.c


objs/src/event/modules/ngx_iocp_module.obj:	$(CORE_DEPS) \
	src/event/modules/ngx_iocp_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/modules/ngx_iocp_module.obj \
		src/event/modules/ngx_iocp_module.c


objs/src/event/modules/ngx_win32_select_module.obj:	$(CORE_DEPS) \
	src/event/modules/ngx_win32_select_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/modules/ngx_win32_select_module.obj \
		src/event/modules/ngx_win32_select_module.c


objs/src/event/ngx_event_openssl.obj:	$(CORE_DEPS) \
	src/event/ngx_event_openssl.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event_openssl.obj \
		src/event/ngx_event_openssl.c


objs/src/event/ngx_event_openssl_stapling.obj:	$(CORE_DEPS) \
	src/event/ngx_event_openssl_stapling.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/event/ngx_event_openssl_stapling.obj \
		src/event/ngx_event_openssl_stapling.c


objs/src/core/ngx_regex.obj:	$(CORE_DEPS) \
	src/core/ngx_regex.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) \
		-Foobjs/src/core/ngx_regex.obj \
		src/core/ngx_regex.c


objs/src/http/ngx_http.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http.obj \
		src/http/ngx_http.c


objs/src/http/ngx_http_core_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_core_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_core_module.obj \
		src/http/ngx_http_core_module.c


objs/src/http/ngx_http_special_response.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_special_response.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_special_response.obj \
		src/http/ngx_http_special_response.c


objs/src/http/ngx_http_request.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_request.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_request.obj \
		src/http/ngx_http_request.c


objs/src/http/ngx_http_parse.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_parse.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_parse.obj \
		src/http/ngx_http_parse.c


objs/src/http/modules/ngx_http_log_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_log_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_log_module.obj \
		src/http/modules/ngx_http_log_module.c


objs/src/http/ngx_http_request_body.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_request_body.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_request_body.obj \
		src/http/ngx_http_request_body.c


objs/src/http/ngx_http_variables.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_variables.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_variables.obj \
		src/http/ngx_http_variables.c


objs/src/http/ngx_http_script.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_script.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_script.obj \
		src/http/ngx_http_script.c


objs/src/http/ngx_http_upstream.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_upstream.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_upstream.obj \
		src/http/ngx_http_upstream.c


objs/src/http/ngx_http_upstream_round_robin.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_upstream_round_robin.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_upstream_round_robin.obj \
		src/http/ngx_http_upstream_round_robin.c


objs/src/http/ngx_http_file_cache.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_file_cache.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_file_cache.obj \
		src/http/ngx_http_file_cache.c


objs/src/http/ngx_http_write_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_write_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_write_filter_module.obj \
		src/http/ngx_http_write_filter_module.c


objs/src/http/ngx_http_header_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_header_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_header_filter_module.obj \
		src/http/ngx_http_header_filter_module.c


objs/src/http/modules/ngx_http_chunked_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_chunked_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_chunked_filter_module.obj \
		src/http/modules/ngx_http_chunked_filter_module.c


objs/src/http/v2/ngx_http_v2_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/v2/ngx_http_v2_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/v2/ngx_http_v2_filter_module.obj \
		src/http/v2/ngx_http_v2_filter_module.c


objs/src/http/modules/ngx_http_range_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_range_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_range_filter_module.obj \
		src/http/modules/ngx_http_range_filter_module.c


objs/src/http/modules/ngx_http_gzip_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_gzip_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_gzip_filter_module.obj \
		src/http/modules/ngx_http_gzip_filter_module.c


objs/src/http/ngx_http_postpone_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_postpone_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_postpone_filter_module.obj \
		src/http/ngx_http_postpone_filter_module.c


objs/src/http/modules/ngx_http_ssi_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_ssi_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_ssi_filter_module.obj \
		src/http/modules/ngx_http_ssi_filter_module.c


objs/src/http/modules/ngx_http_charset_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_charset_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_charset_filter_module.obj \
		src/http/modules/ngx_http_charset_filter_module.c


objs/src/http/modules/ngx_http_sub_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_sub_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_sub_filter_module.obj \
		src/http/modules/ngx_http_sub_filter_module.c


objs/src/http/modules/ngx_http_addition_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_addition_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_addition_filter_module.obj \
		src/http/modules/ngx_http_addition_filter_module.c


objs/src/http/modules/ngx_http_gunzip_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_gunzip_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_gunzip_filter_module.obj \
		src/http/modules/ngx_http_gunzip_filter_module.c


objs/src/http/modules/ngx_http_userid_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_userid_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_userid_filter_module.obj \
		src/http/modules/ngx_http_userid_filter_module.c


objs/src/http/modules/ngx_http_headers_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_headers_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_headers_filter_module.obj \
		src/http/modules/ngx_http_headers_filter_module.c


objs/src/http/ngx_http_copy_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/ngx_http_copy_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/ngx_http_copy_filter_module.obj \
		src/http/ngx_http_copy_filter_module.c


objs/src/http/modules/ngx_http_not_modified_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_not_modified_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_not_modified_filter_module.obj \
		src/http/modules/ngx_http_not_modified_filter_module.c


objs/src/http/modules/ngx_http_slice_filter_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_slice_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_slice_filter_module.obj \
		src/http/modules/ngx_http_slice_filter_module.c


objs/src/http/v2/ngx_http_v2.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/v2/ngx_http_v2.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/v2/ngx_http_v2.obj \
		src/http/v2/ngx_http_v2.c


objs/src/http/v2/ngx_http_v2_table.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/v2/ngx_http_v2_table.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/v2/ngx_http_v2_table.obj \
		src/http/v2/ngx_http_v2_table.c


objs/src/http/v2/ngx_http_v2_huff_decode.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/v2/ngx_http_v2_huff_decode.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/v2/ngx_http_v2_huff_decode.obj \
		src/http/v2/ngx_http_v2_huff_decode.c


objs/src/http/v2/ngx_http_v2_huff_encode.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/v2/ngx_http_v2_huff_encode.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/v2/ngx_http_v2_huff_encode.obj \
		src/http/v2/ngx_http_v2_huff_encode.c


objs/src/http/v2/ngx_http_v2_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/v2/ngx_http_v2_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/v2/ngx_http_v2_module.obj \
		src/http/v2/ngx_http_v2_module.c


objs/src/http/modules/ngx_http_static_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_static_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_static_module.obj \
		src/http/modules/ngx_http_static_module.c


objs/src/http/modules/ngx_http_gzip_static_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_gzip_static_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_gzip_static_module.obj \
		src/http/modules/ngx_http_gzip_static_module.c


objs/src/http/modules/ngx_http_dav_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_dav_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_dav_module.obj \
		src/http/modules/ngx_http_dav_module.c


objs/src/http/modules/ngx_http_autoindex_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_autoindex_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_autoindex_module.obj \
		src/http/modules/ngx_http_autoindex_module.c


objs/src/http/modules/ngx_http_index_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_index_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_index_module.obj \
		src/http/modules/ngx_http_index_module.c


objs/src/http/modules/ngx_http_random_index_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_random_index_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_random_index_module.obj \
		src/http/modules/ngx_http_random_index_module.c


objs/src/http/modules/ngx_http_mirror_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_mirror_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_mirror_module.obj \
		src/http/modules/ngx_http_mirror_module.c


objs/src/http/modules/ngx_http_try_files_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_try_files_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_try_files_module.obj \
		src/http/modules/ngx_http_try_files_module.c


objs/src/http/modules/ngx_http_auth_request_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_auth_request_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_auth_request_module.obj \
		src/http/modules/ngx_http_auth_request_module.c


objs/src/http/modules/ngx_http_auth_basic_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_auth_basic_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_auth_basic_module.obj \
		src/http/modules/ngx_http_auth_basic_module.c


objs/src/http/modules/ngx_http_access_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_access_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_access_module.obj \
		src/http/modules/ngx_http_access_module.c


objs/src/http/modules/ngx_http_limit_conn_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_limit_conn_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_limit_conn_module.obj \
		src/http/modules/ngx_http_limit_conn_module.c


objs/src/http/modules/ngx_http_limit_req_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_limit_req_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_limit_req_module.obj \
		src/http/modules/ngx_http_limit_req_module.c


objs/src/http/modules/ngx_http_realip_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_realip_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_realip_module.obj \
		src/http/modules/ngx_http_realip_module.c


objs/src/http/modules/ngx_http_geo_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_geo_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_geo_module.obj \
		src/http/modules/ngx_http_geo_module.c


objs/src/http/modules/ngx_http_map_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_map_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_map_module.obj \
		src/http/modules/ngx_http_map_module.c


objs/src/http/modules/ngx_http_split_clients_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_split_clients_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_split_clients_module.obj \
		src/http/modules/ngx_http_split_clients_module.c


objs/src/http/modules/ngx_http_referer_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_referer_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_referer_module.obj \
		src/http/modules/ngx_http_referer_module.c


objs/src/http/modules/ngx_http_rewrite_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_rewrite_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_rewrite_module.obj \
		src/http/modules/ngx_http_rewrite_module.c


objs/src/http/modules/ngx_http_ssl_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_ssl_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_ssl_module.obj \
		src/http/modules/ngx_http_ssl_module.c


objs/src/http/modules/ngx_http_proxy_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_proxy_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_proxy_module.obj \
		src/http/modules/ngx_http_proxy_module.c


objs/src/http/modules/ngx_http_fastcgi_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_fastcgi_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_fastcgi_module.obj \
		src/http/modules/ngx_http_fastcgi_module.c


objs/src/http/modules/ngx_http_uwsgi_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_uwsgi_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_uwsgi_module.obj \
		src/http/modules/ngx_http_uwsgi_module.c


objs/src/http/modules/ngx_http_scgi_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_scgi_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_scgi_module.obj \
		src/http/modules/ngx_http_scgi_module.c


objs/src/http/modules/ngx_http_memcached_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_memcached_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_memcached_module.obj \
		src/http/modules/ngx_http_memcached_module.c


objs/src/http/modules/ngx_http_empty_gif_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_empty_gif_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_empty_gif_module.obj \
		src/http/modules/ngx_http_empty_gif_module.c


objs/src/http/modules/ngx_http_browser_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_browser_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_browser_module.obj \
		src/http/modules/ngx_http_browser_module.c


objs/src/http/modules/ngx_http_secure_link_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_secure_link_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_secure_link_module.obj \
		src/http/modules/ngx_http_secure_link_module.c


objs/src/http/modules/ngx_http_flv_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_flv_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_flv_module.obj \
		src/http/modules/ngx_http_flv_module.c


objs/src/http/modules/ngx_http_mp4_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_mp4_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_mp4_module.obj \
		src/http/modules/ngx_http_mp4_module.c


objs/src/http/modules/ngx_http_upstream_hash_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_upstream_hash_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_upstream_hash_module.obj \
		src/http/modules/ngx_http_upstream_hash_module.c


objs/src/http/modules/ngx_http_upstream_ip_hash_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_upstream_ip_hash_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_upstream_ip_hash_module.obj \
		src/http/modules/ngx_http_upstream_ip_hash_module.c


objs/src/http/modules/ngx_http_upstream_least_conn_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_upstream_least_conn_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_upstream_least_conn_module.obj \
		src/http/modules/ngx_http_upstream_least_conn_module.c


objs/src/http/modules/ngx_http_upstream_keepalive_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_upstream_keepalive_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_upstream_keepalive_module.obj \
		src/http/modules/ngx_http_upstream_keepalive_module.c


objs/src/http/modules/ngx_http_upstream_zone_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_upstream_zone_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_upstream_zone_module.obj \
		src/http/modules/ngx_http_upstream_zone_module.c


objs/src/http/modules/ngx_http_stub_status_module.obj:	$(CORE_DEPS) $(HTTP_DEPS) \
	src/http/modules/ngx_http_stub_status_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(HTTP_INCS) \
		-Foobjs/src/http/modules/ngx_http_stub_status_module.obj \
		src/http/modules/ngx_http_stub_status_module.c


objs/src/mail/ngx_mail.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail.obj \
		src/mail/ngx_mail.c


objs/src/mail/ngx_mail_core_module.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_core_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_core_module.obj \
		src/mail/ngx_mail_core_module.c


objs/src/mail/ngx_mail_handler.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_handler.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_handler.obj \
		src/mail/ngx_mail_handler.c


objs/src/mail/ngx_mail_parse.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_parse.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_parse.obj \
		src/mail/ngx_mail_parse.c


objs/src/mail/ngx_mail_ssl_module.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_ssl_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_ssl_module.obj \
		src/mail/ngx_mail_ssl_module.c


objs/src/mail/ngx_mail_pop3_module.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_pop3_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_pop3_module.obj \
		src/mail/ngx_mail_pop3_module.c


objs/src/mail/ngx_mail_pop3_handler.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_pop3_handler.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_pop3_handler.obj \
		src/mail/ngx_mail_pop3_handler.c


objs/src/mail/ngx_mail_imap_module.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_imap_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_imap_module.obj \
		src/mail/ngx_mail_imap_module.c


objs/src/mail/ngx_mail_imap_handler.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_imap_handler.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_imap_handler.obj \
		src/mail/ngx_mail_imap_handler.c


objs/src/mail/ngx_mail_smtp_module.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_smtp_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_smtp_module.obj \
		src/mail/ngx_mail_smtp_module.c


objs/src/mail/ngx_mail_smtp_handler.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_smtp_handler.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_smtp_handler.obj \
		src/mail/ngx_mail_smtp_handler.c


objs/src/mail/ngx_mail_auth_http_module.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_auth_http_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_auth_http_module.obj \
		src/mail/ngx_mail_auth_http_module.c


objs/src/mail/ngx_mail_proxy_module.obj:	$(CORE_DEPS) $(MAIL_DEPS) \
	src/mail/ngx_mail_proxy_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(MAIL_INCS) \
		-Foobjs/src/mail/ngx_mail_proxy_module.obj \
		src/mail/ngx_mail_proxy_module.c


objs/src/stream/ngx_stream.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream.obj \
		src/stream/ngx_stream.c


objs/src/stream/ngx_stream_variables.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_variables.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_variables.obj \
		src/stream/ngx_stream_variables.c


objs/src/stream/ngx_stream_script.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_script.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_script.obj \
		src/stream/ngx_stream_script.c


objs/src/stream/ngx_stream_handler.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_handler.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_handler.obj \
		src/stream/ngx_stream_handler.c


objs/src/stream/ngx_stream_core_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_core_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_core_module.obj \
		src/stream/ngx_stream_core_module.c


objs/src/stream/ngx_stream_log_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_log_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_log_module.obj \
		src/stream/ngx_stream_log_module.c


objs/src/stream/ngx_stream_proxy_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_proxy_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_proxy_module.obj \
		src/stream/ngx_stream_proxy_module.c


objs/src/stream/ngx_stream_upstream.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_upstream.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_upstream.obj \
		src/stream/ngx_stream_upstream.c


objs/src/stream/ngx_stream_upstream_round_robin.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_upstream_round_robin.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_upstream_round_robin.obj \
		src/stream/ngx_stream_upstream_round_robin.c


objs/src/stream/ngx_stream_write_filter_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_write_filter_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_write_filter_module.obj \
		src/stream/ngx_stream_write_filter_module.c


objs/src/stream/ngx_stream_ssl_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_ssl_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_ssl_module.obj \
		src/stream/ngx_stream_ssl_module.c


objs/src/stream/ngx_stream_limit_conn_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_limit_conn_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_limit_conn_module.obj \
		src/stream/ngx_stream_limit_conn_module.c


objs/src/stream/ngx_stream_access_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_access_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_access_module.obj \
		src/stream/ngx_stream_access_module.c


objs/src/stream/ngx_stream_geo_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_geo_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_geo_module.obj \
		src/stream/ngx_stream_geo_module.c


objs/src/stream/ngx_stream_map_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_map_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_map_module.obj \
		src/stream/ngx_stream_map_module.c


objs/src/stream/ngx_stream_split_clients_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_split_clients_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_split_clients_module.obj \
		src/stream/ngx_stream_split_clients_module.c


objs/src/stream/ngx_stream_return_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_return_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_return_module.obj \
		src/stream/ngx_stream_return_module.c


objs/src/stream/ngx_stream_upstream_hash_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_upstream_hash_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_upstream_hash_module.obj \
		src/stream/ngx_stream_upstream_hash_module.c


objs/src/stream/ngx_stream_upstream_least_conn_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_upstream_least_conn_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_upstream_least_conn_module.obj \
		src/stream/ngx_stream_upstream_least_conn_module.c


objs/src/stream/ngx_stream_upstream_zone_module.obj:	$(CORE_DEPS) $(STREAM_DEPS) \
	src/stream/ngx_stream_upstream_zone_module.c
	$(CC) -c $(CFLAGS) $(CORE_INCS) $(STREAM_INCS) \
		-Foobjs/src/stream/ngx_stream_upstream_zone_module.obj \
		src/stream/ngx_stream_upstream_zone_module.c


objs/addon/src/ndk.obj:	$(ADDON_DEPS) \
	../ngx_devel_kit-0.3.0/src/ndk.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ndk.obj \
		../ngx_devel_kit-0.3.0/src/ndk.c


objs/addon/src/ngx_http_echo_module.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_module.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_module.c


objs/addon/src/ngx_http_echo_util.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_util.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_util.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_util.c


objs/addon/src/ngx_http_echo_timer.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_timer.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_timer.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_timer.c


objs/addon/src/ngx_http_echo_var.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_var.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_var.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_var.c


objs/addon/src/ngx_http_echo_handler.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_handler.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_handler.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_handler.c


objs/addon/src/ngx_http_echo_filter.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_filter.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_filter.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_filter.c


objs/addon/src/ngx_http_echo_sleep.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_sleep.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_sleep.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_sleep.c


objs/addon/src/ngx_http_echo_location.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_location.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_location.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_location.c


objs/addon/src/ngx_http_echo_echo.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_echo.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_echo.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_echo.c


objs/addon/src/ngx_http_echo_request_info.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_request_info.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_request_info.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_request_info.c


objs/addon/src/ngx_http_echo_subrequest.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_subrequest.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_subrequest.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_subrequest.c


objs/addon/src/ngx_http_echo_foreach.obj:	$(ADDON_DEPS) \
	../echo-nginx-module-0.61/src/ngx_http_echo_foreach.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_echo_foreach.obj \
		../echo-nginx-module-0.61/src/ngx_http_echo_foreach.c


objs/addon/src/ngx_coolkit_handlers.obj:	$(ADDON_DEPS) \
	../ngx_coolkit-0.2rc3/src/ngx_coolkit_handlers.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_coolkit_handlers.obj \
		../ngx_coolkit-0.2rc3/src/ngx_coolkit_handlers.c


objs/addon/src/ngx_coolkit_module.obj:	$(ADDON_DEPS) \
	../ngx_coolkit-0.2rc3/src/ngx_coolkit_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_coolkit_module.obj \
		../ngx_coolkit-0.2rc3/src/ngx_coolkit_module.c


objs/addon/src/ngx_coolkit_variables.obj:	$(ADDON_DEPS) \
	../ngx_coolkit-0.2rc3/src/ngx_coolkit_variables.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_coolkit_variables.obj \
		../ngx_coolkit-0.2rc3/src/ngx_coolkit_variables.c


objs/addon/src/ngx_http_set_base32.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_base32.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_base32.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_base32.c


objs/addon/src/ngx_http_set_default_value.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_default_value.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_default_value.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_default_value.c


objs/addon/src/ngx_http_set_hashed_upstream.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_hashed_upstream.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_hashed_upstream.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_hashed_upstream.c


objs/addon/src/ngx_http_set_quote_sql.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_quote_sql.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_quote_sql.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_quote_sql.c


objs/addon/src/ngx_http_set_quote_json.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_quote_json.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_quote_json.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_quote_json.c


objs/addon/src/ngx_http_set_unescape_uri.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_unescape_uri.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_unescape_uri.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_unescape_uri.c


objs/addon/src/ngx_http_set_misc_module.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_misc_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_misc_module.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_misc_module.c


objs/addon/src/ngx_http_set_escape_uri.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_escape_uri.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_escape_uri.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_escape_uri.c


objs/addon/src/ngx_http_set_hash.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_hash.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_hash.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_hash.c


objs/addon/src/ngx_http_set_local_today.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_local_today.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_local_today.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_local_today.c


objs/addon/src/ngx_http_set_hex.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_hex.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_hex.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_hex.c


objs/addon/src/ngx_http_set_base64.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_base64.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_base64.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_base64.c


objs/addon/src/ngx_http_set_random.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_random.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_random.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_random.c


objs/addon/src/ngx_http_set_secure_random.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_secure_random.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_secure_random.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_secure_random.c


objs/addon/src/ngx_http_set_rotate.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_rotate.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_rotate.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_rotate.c


objs/addon/src/ngx_http_set_hmac.obj:	$(ADDON_DEPS) \
	../set-misc-nginx-module-0.31/src/ngx_http_set_hmac.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_set_hmac.obj \
		../set-misc-nginx-module-0.31/src/ngx_http_set_hmac.c


objs/addon/src/ngx_postgres_escape.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_escape.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_escape.obj \
		../ngx_postgres-1.0/src/ngx_postgres_escape.c


objs/addon/src/ngx_postgres_handler.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_handler.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_handler.obj \
		../ngx_postgres-1.0/src/ngx_postgres_handler.c


objs/addon/src/ngx_postgres_keepalive.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_keepalive.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_keepalive.obj \
		../ngx_postgres-1.0/src/ngx_postgres_keepalive.c


objs/addon/src/ngx_postgres_module.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_module.obj \
		../ngx_postgres-1.0/src/ngx_postgres_module.c


objs/addon/src/ngx_postgres_output.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_output.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_output.obj \
		../ngx_postgres-1.0/src/ngx_postgres_output.c


objs/addon/src/ngx_postgres_processor.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_processor.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_processor.obj \
		../ngx_postgres-1.0/src/ngx_postgres_processor.c


objs/addon/src/ngx_postgres_rewrite.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_rewrite.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_rewrite.obj \
		../ngx_postgres-1.0/src/ngx_postgres_rewrite.c


objs/addon/src/ngx_postgres_upstream.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_upstream.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_upstream.obj \
		../ngx_postgres-1.0/src/ngx_postgres_upstream.c


objs/addon/src/ngx_postgres_util.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_util.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_util.obj \
		../ngx_postgres-1.0/src/ngx_postgres_util.c


objs/addon/src/ngx_postgres_variable.obj:	$(ADDON_DEPS) \
	../ngx_postgres-1.0/src/ngx_postgres_variable.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_postgres_variable.obj \
		../ngx_postgres-1.0/src/ngx_postgres_variable.c


objs/addon/src/ngx_http_form_input_module.obj:	$(ADDON_DEPS) \
	../form-input-nginx-module-0.12/src/ngx_http_form_input_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_form_input_module.obj \
		../form-input-nginx-module-0.12/src/ngx_http_form_input_module.c


objs/addon/src/ngx_http_encrypted_session_module.obj:	$(ADDON_DEPS) \
	../encrypted-session-nginx-module-0.06/src/ngx_http_encrypted_session_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_encrypted_session_module.obj \
		../encrypted-session-nginx-module-0.06/src/ngx_http_encrypted_session_module.c


objs/addon/src/ngx_http_encrypted_session_cipher.obj:	$(ADDON_DEPS) \
	../encrypted-session-nginx-module-0.06/src/ngx_http_encrypted_session_cipher.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_encrypted_session_cipher.obj \
		../encrypted-session-nginx-module-0.06/src/ngx_http_encrypted_session_cipher.c


objs/addon/src/ngx_http_lua_script.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_script.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_script.obj \
		../ngx_lua/src/ngx_http_lua_script.c


objs/addon/src/ngx_http_lua_log.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_log.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_log.obj \
		../ngx_lua/src/ngx_http_lua_log.c


objs/addon/src/ngx_http_lua_subrequest.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_subrequest.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_subrequest.obj \
		../ngx_lua/src/ngx_http_lua_subrequest.c


objs/addon/src/ngx_http_lua_ndk.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_ndk.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_ndk.obj \
		../ngx_lua/src/ngx_http_lua_ndk.c


objs/addon/src/ngx_http_lua_control.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_control.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_control.obj \
		../ngx_lua/src/ngx_http_lua_control.c


objs/addon/src/ngx_http_lua_time.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_time.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_time.obj \
		../ngx_lua/src/ngx_http_lua_time.c


objs/addon/src/ngx_http_lua_misc.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_misc.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_misc.obj \
		../ngx_lua/src/ngx_http_lua_misc.c


objs/addon/src/ngx_http_lua_variable.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_variable.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_variable.obj \
		../ngx_lua/src/ngx_http_lua_variable.c


objs/addon/src/ngx_http_lua_string.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_string.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_string.obj \
		../ngx_lua/src/ngx_http_lua_string.c


objs/addon/src/ngx_http_lua_output.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_output.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_output.obj \
		../ngx_lua/src/ngx_http_lua_output.c


objs/addon/src/ngx_http_lua_headers.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_headers.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_headers.obj \
		../ngx_lua/src/ngx_http_lua_headers.c


objs/addon/src/ngx_http_lua_req_body.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_req_body.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_req_body.obj \
		../ngx_lua/src/ngx_http_lua_req_body.c


objs/addon/src/ngx_http_lua_uri.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_uri.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_uri.obj \
		../ngx_lua/src/ngx_http_lua_uri.c


objs/addon/src/ngx_http_lua_args.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_args.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_args.obj \
		../ngx_lua/src/ngx_http_lua_args.c


objs/addon/src/ngx_http_lua_ctx.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_ctx.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_ctx.obj \
		../ngx_lua/src/ngx_http_lua_ctx.c


objs/addon/src/ngx_http_lua_regex.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_regex.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_regex.obj \
		../ngx_lua/src/ngx_http_lua_regex.c


objs/addon/src/ngx_http_lua_module.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_module.obj \
		../ngx_lua/src/ngx_http_lua_module.c


objs/addon/src/ngx_http_lua_headers_out.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_headers_out.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_headers_out.obj \
		../ngx_lua/src/ngx_http_lua_headers_out.c


objs/addon/src/ngx_http_lua_headers_in.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_headers_in.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_headers_in.obj \
		../ngx_lua/src/ngx_http_lua_headers_in.c


objs/addon/src/ngx_http_lua_directive.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_directive.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_directive.obj \
		../ngx_lua/src/ngx_http_lua_directive.c


objs/addon/src/ngx_http_lua_consts.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_consts.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_consts.obj \
		../ngx_lua/src/ngx_http_lua_consts.c


objs/addon/src/ngx_http_lua_exception.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_exception.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_exception.obj \
		../ngx_lua/src/ngx_http_lua_exception.c


objs/addon/src/ngx_http_lua_util.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_util.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_util.obj \
		../ngx_lua/src/ngx_http_lua_util.c


objs/addon/src/ngx_http_lua_cache.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_cache.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_cache.obj \
		../ngx_lua/src/ngx_http_lua_cache.c


objs/addon/src/ngx_http_lua_contentby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_contentby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_contentby.obj \
		../ngx_lua/src/ngx_http_lua_contentby.c


objs/addon/src/ngx_http_lua_rewriteby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_rewriteby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_rewriteby.obj \
		../ngx_lua/src/ngx_http_lua_rewriteby.c


objs/addon/src/ngx_http_lua_accessby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_accessby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_accessby.obj \
		../ngx_lua/src/ngx_http_lua_accessby.c


objs/addon/src/ngx_http_lua_setby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_setby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_setby.obj \
		../ngx_lua/src/ngx_http_lua_setby.c


objs/addon/src/ngx_http_lua_capturefilter.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_capturefilter.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_capturefilter.obj \
		../ngx_lua/src/ngx_http_lua_capturefilter.c


objs/addon/src/ngx_http_lua_clfactory.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_clfactory.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_clfactory.obj \
		../ngx_lua/src/ngx_http_lua_clfactory.c


objs/addon/src/ngx_http_lua_pcrefix.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_pcrefix.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_pcrefix.obj \
		../ngx_lua/src/ngx_http_lua_pcrefix.c


objs/addon/src/ngx_http_lua_headerfilterby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_headerfilterby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_headerfilterby.obj \
		../ngx_lua/src/ngx_http_lua_headerfilterby.c


objs/addon/src/ngx_http_lua_shdict.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_shdict.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_shdict.obj \
		../ngx_lua/src/ngx_http_lua_shdict.c


objs/addon/src/ngx_http_lua_socket_tcp.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_socket_tcp.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_socket_tcp.obj \
		../ngx_lua/src/ngx_http_lua_socket_tcp.c


objs/addon/src/ngx_http_lua_api.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_api.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_api.obj \
		../ngx_lua/src/ngx_http_lua_api.c


objs/addon/src/ngx_http_lua_logby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_logby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_logby.obj \
		../ngx_lua/src/ngx_http_lua_logby.c


objs/addon/src/ngx_http_lua_sleep.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_sleep.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_sleep.obj \
		../ngx_lua/src/ngx_http_lua_sleep.c


objs/addon/src/ngx_http_lua_semaphore.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_semaphore.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_semaphore.obj \
		../ngx_lua/src/ngx_http_lua_semaphore.c


objs/addon/src/ngx_http_lua_coroutine.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_coroutine.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_coroutine.obj \
		../ngx_lua/src/ngx_http_lua_coroutine.c


objs/addon/src/ngx_http_lua_bodyfilterby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_bodyfilterby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_bodyfilterby.obj \
		../ngx_lua/src/ngx_http_lua_bodyfilterby.c


objs/addon/src/ngx_http_lua_initby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_initby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_initby.obj \
		../ngx_lua/src/ngx_http_lua_initby.c


objs/addon/src/ngx_http_lua_initworkerby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_initworkerby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_initworkerby.obj \
		../ngx_lua/src/ngx_http_lua_initworkerby.c


objs/addon/src/ngx_http_lua_socket_udp.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_socket_udp.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_socket_udp.obj \
		../ngx_lua/src/ngx_http_lua_socket_udp.c


objs/addon/src/ngx_http_lua_req_method.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_req_method.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_req_method.obj \
		../ngx_lua/src/ngx_http_lua_req_method.c


objs/addon/src/ngx_http_lua_phase.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_phase.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_phase.obj \
		../ngx_lua/src/ngx_http_lua_phase.c


objs/addon/src/ngx_http_lua_uthread.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_uthread.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_uthread.obj \
		../ngx_lua/src/ngx_http_lua_uthread.c


objs/addon/src/ngx_http_lua_timer.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_timer.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_timer.obj \
		../ngx_lua/src/ngx_http_lua_timer.c


objs/addon/src/ngx_http_lua_config.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_config.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_config.obj \
		../ngx_lua/src/ngx_http_lua_config.c


objs/addon/src/ngx_http_lua_worker.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_worker.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_worker.obj \
		../ngx_lua/src/ngx_http_lua_worker.c


objs/addon/src/ngx_http_lua_ssl_certby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_ssl_certby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_ssl_certby.obj \
		../ngx_lua/src/ngx_http_lua_ssl_certby.c


objs/addon/src/ngx_http_lua_ssl_ocsp.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_ssl_ocsp.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_ssl_ocsp.obj \
		../ngx_lua/src/ngx_http_lua_ssl_ocsp.c


objs/addon/src/ngx_http_lua_lex.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_lex.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_lex.obj \
		../ngx_lua/src/ngx_http_lua_lex.c


objs/addon/src/ngx_http_lua_balancer.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_balancer.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_balancer.obj \
		../ngx_lua/src/ngx_http_lua_balancer.c


objs/addon/src/ngx_http_lua_ssl_session_storeby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_ssl_session_storeby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_ssl_session_storeby.obj \
		../ngx_lua/src/ngx_http_lua_ssl_session_storeby.c


objs/addon/src/ngx_http_lua_ssl_session_fetchby.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_ssl_session_fetchby.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_ssl_session_fetchby.obj \
		../ngx_lua/src/ngx_http_lua_ssl_session_fetchby.c


objs/addon/src/ngx_http_lua_ssl.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_ssl.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_ssl.obj \
		../ngx_lua/src/ngx_http_lua_ssl.c


objs/addon/src/ngx_http_lua_log_ringbuf.obj:	$(ADDON_DEPS) \
	../ngx_lua/src/ngx_http_lua_log_ringbuf.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_log_ringbuf.obj \
		../ngx_lua/src/ngx_http_lua_log_ringbuf.c


objs/addon/src/ngx_http_lua_upstream_module.obj:	$(ADDON_DEPS) \
	../ngx_lua_upstream-0.07/src/ngx_http_lua_upstream_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_lua_upstream_module.obj \
		../ngx_lua_upstream-0.07/src/ngx_http_lua_upstream_module.c


objs/addon/src/ngx_http_headers_more_filter_module.obj:	$(ADDON_DEPS) \
	../headers-more-nginx-module-0.32/src/ngx_http_headers_more_filter_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_headers_more_filter_module.obj \
		../headers-more-nginx-module-0.32/src/ngx_http_headers_more_filter_module.c


objs/addon/src/ngx_http_headers_more_headers_out.obj:	$(ADDON_DEPS) \
	../headers-more-nginx-module-0.32/src/ngx_http_headers_more_headers_out.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_headers_more_headers_out.obj \
		../headers-more-nginx-module-0.32/src/ngx_http_headers_more_headers_out.c


objs/addon/src/ngx_http_headers_more_headers_in.obj:	$(ADDON_DEPS) \
	../headers-more-nginx-module-0.32/src/ngx_http_headers_more_headers_in.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_headers_more_headers_in.obj \
		../headers-more-nginx-module-0.32/src/ngx_http_headers_more_headers_in.c


objs/addon/src/ngx_http_headers_more_util.obj:	$(ADDON_DEPS) \
	../headers-more-nginx-module-0.32/src/ngx_http_headers_more_util.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_headers_more_util.obj \
		../headers-more-nginx-module-0.32/src/ngx_http_headers_more_util.c


objs/addon/src/ngx_http_array_var_module.obj:	$(ADDON_DEPS) \
	../array-var-nginx-module-0.05/src/ngx_http_array_var_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_array_var_module.obj \
		../array-var-nginx-module-0.05/src/ngx_http_array_var_module.c


objs/addon/src/ngx_http_array_var_util.obj:	$(ADDON_DEPS) \
	../array-var-nginx-module-0.05/src/ngx_http_array_var_util.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_array_var_util.obj \
		../array-var-nginx-module-0.05/src/ngx_http_array_var_util.c


objs/addon/nginx-http-concat-module/ngx_http_concat_module.obj:	$(ADDON_DEPS) \
	../nginx-http-concat-module/ngx_http_concat_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/nginx-http-concat-module/ngx_http_concat_module.obj \
		../nginx-http-concat-module/ngx_http_concat_module.c


objs/addon/src/ngx_http_rds_json_filter_module.obj:	$(ADDON_DEPS) \
	../rds-json-nginx-module-0.14/src/ngx_http_rds_json_filter_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_rds_json_filter_module.obj \
		../rds-json-nginx-module-0.14/src/ngx_http_rds_json_filter_module.c


objs/addon/src/ngx_http_rds_json_processor.obj:	$(ADDON_DEPS) \
	../rds-json-nginx-module-0.14/src/ngx_http_rds_json_processor.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_rds_json_processor.obj \
		../rds-json-nginx-module-0.14/src/ngx_http_rds_json_processor.c


objs/addon/src/ngx_http_rds_json_util.obj:	$(ADDON_DEPS) \
	../rds-json-nginx-module-0.14/src/ngx_http_rds_json_util.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_rds_json_util.obj \
		../rds-json-nginx-module-0.14/src/ngx_http_rds_json_util.c


objs/addon/src/ngx_http_rds_json_output.obj:	$(ADDON_DEPS) \
	../rds-json-nginx-module-0.14/src/ngx_http_rds_json_output.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_rds_json_output.obj \
		../rds-json-nginx-module-0.14/src/ngx_http_rds_json_output.c


objs/addon/src/ngx_http_rds_json_handler.obj:	$(ADDON_DEPS) \
	../rds-json-nginx-module-0.14/src/ngx_http_rds_json_handler.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_rds_json_handler.obj \
		../rds-json-nginx-module-0.14/src/ngx_http_rds_json_handler.c


objs/addon/src/ngx_http_redis2_module.obj:	$(ADDON_DEPS) \
	../redis2-nginx-module-0.14/src/ngx_http_redis2_module.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_redis2_module.obj \
		../redis2-nginx-module-0.14/src/ngx_http_redis2_module.c


objs/addon/src/ngx_http_redis2_handler.obj:	$(ADDON_DEPS) \
	../redis2-nginx-module-0.14/src/ngx_http_redis2_handler.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_redis2_handler.obj \
		../redis2-nginx-module-0.14/src/ngx_http_redis2_handler.c


objs/addon/src/ngx_http_redis2_reply.obj:	$(ADDON_DEPS) \
	../redis2-nginx-module-0.14/src/ngx_http_redis2_reply.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_redis2_reply.obj \
		../redis2-nginx-module-0.14/src/ngx_http_redis2_reply.c


objs/addon/src/ngx_http_redis2_util.obj:	$(ADDON_DEPS) \
	../redis2-nginx-module-0.14/src/ngx_http_redis2_util.c
	$(CC) -c $(CFLAGS)  $(ALL_INCS) \
		-Foobjs/addon/src/ngx_http_redis2_util.obj \
		../redis2-nginx-module-0.14/src/ngx_http_redis2_util.c


objs/nginx.res:	 src/os/win32/nginx.ico
	rc -foobjs/nginx.res $(CORE_INCS) src/os/win32/nginx.rc


objs/lib/pcre/pcre.lib:	objs/lib/pcre/pcre.h objs/Makefile
	$(MAKE) -f auto/lib/pcre/makefile.msvc PCRE="objs/lib/pcre" CPU_OPT="" LIBC=-MT

objs/lib/pcre/pcre.h:
	$(MAKE) -f auto/lib/pcre/makefile.msvc PCRE="objs/lib/pcre" pcre.h


objs/lib/openssl/openssl/include/openssl/ssl.h:	objs/Makefile
	$(MAKE) -f auto/lib/openssl/makefile.msvc					OPENSSL="objs/lib/openssl" OPENSSL_OPT=""


objs/lib/zlib/zlib.lib:	objs/Makefile
	$(MAKE) -f auto/lib/zlib/makefile.msvc CPU_OPT="" LIBC=-MT ZLIB="objs/lib/zlib"


manpage:	objs/nginx.8

objs/nginx.8:	man/nginx.8 objs/ngx_auto_config.h
	sed -e "s|%%PREFIX%%||" \
		-e "s|%%PID_PATH%%|/logs/nginx.pid|" \
		-e "s|%%CONF_PATH%%|/conf/nginx.conf|" \
		-e "s|%%ERROR_LOG_PATH%%|/logs/error.log|" \
		< man/nginx.8 > $@

install:	build 
	test -d '$(DESTDIR)' || mkdir -p '$(DESTDIR)'

	test -d '$(DESTDIR)/' \
		|| mkdir -p '$(DESTDIR)/'
	test ! -f '$(DESTDIR)/nginx.exe' \
		|| mv '$(DESTDIR)/nginx.exe' \
			'$(DESTDIR)/nginx.exe.old'
	cp objs/nginx '$(DESTDIR)/nginx.exe'

	test -d '$(DESTDIR)/conf' \
		|| mkdir -p '$(DESTDIR)/conf'

	cp conf/koi-win '$(DESTDIR)/conf'
	cp conf/koi-utf '$(DESTDIR)/conf'
	cp conf/win-utf '$(DESTDIR)/conf'

	test -f '$(DESTDIR)/conf/mime.types' \
		|| cp conf/mime.types '$(DESTDIR)/conf'
	cp conf/mime.types '$(DESTDIR)/conf/mime.types.default'

	test -f '$(DESTDIR)/conf/fastcgi_params' \
		|| cp conf/fastcgi_params '$(DESTDIR)/conf'
	cp conf/fastcgi_params \
		'$(DESTDIR)/conf/fastcgi_params.default'

	test -f '$(DESTDIR)/conf/fastcgi.conf' \
		|| cp conf/fastcgi.conf '$(DESTDIR)/conf'
	cp conf/fastcgi.conf '$(DESTDIR)/conf/fastcgi.conf.default'

	test -f '$(DESTDIR)/conf/uwsgi_params' \
		|| cp conf/uwsgi_params '$(DESTDIR)/conf'
	cp conf/uwsgi_params \
		'$(DESTDIR)/conf/uwsgi_params.default'

	test -f '$(DESTDIR)/conf/scgi_params' \
		|| cp conf/scgi_params '$(DESTDIR)/conf'
	cp conf/scgi_params \
		'$(DESTDIR)/conf/scgi_params.default'

	test -f '$(DESTDIR)/conf/nginx.conf' \
		|| cp conf/nginx.conf '$(DESTDIR)/conf/nginx.conf'
	cp conf/nginx.conf '$(DESTDIR)/conf/nginx.conf.default'

	test -d '$(DESTDIR)/logs' \
		|| mkdir -p '$(DESTDIR)/logs'

	test -d '$(DESTDIR)/logs' \
		|| mkdir -p '$(DESTDIR)/logs'

	test -d '$(DESTDIR)/html' \
		|| cp -R html '$(DESTDIR)'

	test -d '$(DESTDIR)/logs' \
		|| mkdir -p '$(DESTDIR)/logs'
