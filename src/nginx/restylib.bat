export LUA_LIB_DIR=objs
export CORE_LIB=../lua-resty-core-0.1.6/
export DNS_LIB=../lua-resty-dns-0.16/
export LOCK_LIB=../lua-resty-lock-0.04/
export LRUCACHE_LIB=../lua-resty-lrucache-0.04/
export MEMCACHED_LIB=../lua-resty-memcached-0.14/
export MYSQL_LIB=../lua-resty-mysql-0.16/
export REDIS_LIB=../lua-resty-redis-0.24/
export STRING_LIB=../lua-resty-string-0.09/
export UPLOAD_LIB=../lua-resty-upload-0.09/
export UPSTREAM_HEALTHCHECK_LIB=../lua-resty-upstream-healthcheck-0.04/
export WEBSOCKET_LIB=../lua-resty-websocket-0.05/

rm -r ${LUA_LIB_DIR}/resty/
rm -r ${LUA_LIB_DIR}/ngx/
mkdir -p ${LUA_LIB_DIR}/resty/

mkdir -p ${LUA_LIB_DIR}/resty/core/
mkdir -p ${LUA_LIB_DIR}/ngx/
cp ${CORE_LIB}/lib/resty/core/*.lua ${LUA_LIB_DIR}/resty/core/
cp ${CORE_LIB}/lib/resty/*.lua ${LUA_LIB_DIR}/resty/
cp ${CORE_LIB}/lib/ngx/*.lua ${LUA_LIB_DIR}/ngx/

mkdir -p ${LUA_LIB_DIR}/resty/dns/
cp ${DNS_LIB}/lib/resty/dns/*.lua ${LUA_LIB_DIR}/resty/dns/

cp ${LOCK_LIB}/lib/resty/*.lua ${LUA_LIB_DIR}/resty/

mkdir -p ${LUA_LIB_DIR}/resty/lrucache/
cp ${LRUCACHE_LIB}/lib/resty/lrucache/*.lua ${LUA_LIB_DIR}/resty/lrucache/
cp ${LRUCACHE_LIB}/lib/resty/*.lua ${LUA_LIB_DIR}/resty/

cp ${MEMCACHED_LIB}/lib/resty/*.lua ${LUA_LIB_DIR}/resty

cp ${MYSQL_LIB}/lib/resty/*.lua ${LUA_LIB_DIR}/resty

cp ${REDIS_LIB}/lib/resty/*.lua ${LUA_LIB_DIR}/resty

cp ${STRING_LIB}/lib/resty/*.lua ${LUA_LIB_DIR}/resty

cp ${UPLOAD_LIB}/lib/resty/*.lua ${LUA_LIB_DIR}/resty

mkdir -p ${LUA_LIB_DIR}/resty/upstream/
cp ${UPSTREAM_HEALTHCHECK_LIB}/lib/resty/upstream/*.lua ${LUA_LIB_DIR}/resty/upstream/

mkdir -p ${LUA_LIB_DIR}/resty/websocket/
cp ${WEBSOCKET_LIB}/lib/resty/websocket/*.lua ${LUA_LIB_DIR}/resty/websocket/

echo success