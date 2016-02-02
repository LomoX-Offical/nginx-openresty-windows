#define NGX_CONFIGURE " --with-cc=cl --builddir=objs --prefix= --conf-path=conf/nginx.conf --pid-path=logs/nginx.pid --http-log-path=logs/access.log --error-log-path=logs/error.log --sbin-path=nginx.exe --http-client-body-temp-path=temp/client_body_temp --http-proxy-temp-path=temp/proxy_temp --http-fastcgi-temp-path=temp/fastcgi_temp --http-scgi-temp-path=temp/scgi_temp --http-uwsgi-temp-path=temp/uwsgi_temp --with-cc-opt=-DFD_SETSIZE=32768 --with-pcre=objs/lib/pcre --with-zlib=objs/lib/zlib --with-openssl=objs/lib/openssl --with-select_module --with-http_realip_module --with-http_addition_module --with-http_sub_module --with-http_dav_module --with-http_stub_status_module --with-http_flv_module --with-http_mp4_module --with-http_gunzip_module --with-http_gzip_static_module --with-http_auth_request_module --with-http_random_index_module --with-http_secure_link_module --with-mail --with-stream --with-http_ssl_module --with-mail_ssl_module --with-stream_ssl_module --with-http_v2_module --with-ipv6 --add-module=../ngx_devel_kit-0.2.19 --add-module=../echo-nginx-module-0.58 --add-module=../ngx_coolkit-0.2rc3 --add-module=../set-misc-nginx-module-0.29 --add-module=../ngx_postgres-1.0rc7 --add-module=../form-input-nginx-module-0.11 --add-module=../encrypted-session-nginx-module-0.04 --add-module=../ngx_lua --add-module=../ngx_lua_upstream-0.04 --add-module=../headers-more-nginx-module-0.29 --add-module=../array-var-nginx-module-0.04 --add-module=../nginx-http-concat-module --add-module=../rds-json-nginx-module-0.14 --add-module=../redis2-nginx-module-0.12"

#ifndef NGX_HAVE_INET6
#define NGX_HAVE_INET6  1
#endif


#ifndef NGX_HAVE_IOCP
#define NGX_HAVE_IOCP  1
#endif


#ifndef NGX_HAVE_NONALIGNED
#define NGX_HAVE_NONALIGNED  1
#endif


#ifndef NGX_CPU_CACHE_LINE
#define NGX_CPU_CACHE_LINE  32
#endif


#ifndef NGX_HAVE_SELECT
#define NGX_HAVE_SELECT  1
#endif


#ifndef NGX_HTTP_CACHE
#define NGX_HTTP_CACHE  1
#endif


#ifndef NGX_HTTP_GZIP
#define NGX_HTTP_GZIP  1
#endif


#ifndef NGX_HTTP_SSI
#define NGX_HTTP_SSI  1
#endif


#ifndef NGX_HTTP_GZIP
#define NGX_HTTP_GZIP  1
#endif


#ifndef NGX_HTTP_V2
#define NGX_HTTP_V2  1
#endif


#ifndef NGX_HTTP_GZIP
#define NGX_HTTP_GZIP  1
#endif


#ifndef NGX_HTTP_DAV
#define NGX_HTTP_DAV  1
#endif


#ifndef NGX_CRYPT
#define NGX_CRYPT  1
#endif


#ifndef NGX_HTTP_REALIP
#define NGX_HTTP_REALIP  1
#endif


#ifndef NGX_HTTP_X_FORWARDED_FOR
#define NGX_HTTP_X_FORWARDED_FOR  1
#endif


#ifndef NGX_HTTP_X_FORWARDED_FOR
#define NGX_HTTP_X_FORWARDED_FOR  1
#endif


#ifndef NGX_HTTP_SSL
#define NGX_HTTP_SSL  1
#endif


#ifndef NGX_HTTP_X_FORWARDED_FOR
#define NGX_HTTP_X_FORWARDED_FOR  1
#endif


#ifndef NGX_HTTP_UPSTREAM_ZONE
#define NGX_HTTP_UPSTREAM_ZONE  1
#endif


#ifndef NGX_STAT_STUB
#define NGX_STAT_STUB  1
#endif


#ifndef NDK
#define NDK  1
#endif


#ifndef NGX_COOLKIT_MODULE
#define NGX_COOLKIT_MODULE  1
#endif


#ifndef NGX_POSTGRES_LIBRARY_VERSION
#define NGX_POSTGRES_LIBRARY_VERSION  90104
#endif


#ifndef NGX_POSTGRES_MODULE
#define NGX_POSTGRES_MODULE  1
#endif

