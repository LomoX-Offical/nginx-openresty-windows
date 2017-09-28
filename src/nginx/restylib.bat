SET ORG_DIR=%cd%
set LUA_LIB_DIR=objs\lua
set CORE_LIB=..\lua-resty-core-0.1.12\
set DNS_LIB=..\lua-resty-dns-0.19\
set LIMIT_TRAFFIC_LIB=..\lua-resty-limit-traffic-0.04\
set LOCK_LIB=..\lua-resty-lock-0.07\
set LRUCACHE_LIB=..\lua-resty-lrucache-0.06\
set MEMCACHED_LIB=..\lua-resty-memcached-0.14\
set MYSQL_LIB=..\lua-resty-mysql-0.20\
set REDIS_LIB=..\lua-resty-redis-0.26\
set STRING_LIB=..\lua-resty-string-0.10\
set UPLOAD_LIB=..\lua-resty-upload-0.10\
set UPSTREAM_HEALTHCHECK_LIB=..\lua-resty-upstream-healthcheck-0.05\
set WEBSOCKET_LIB=..\lua-resty-websocket-0.06\

cd /d %~dp0
echo rd /S /Q %LUA_LIB_DIR%
rd /S /Q %LUA_LIB_DIR%
md %LUA_LIB_DIR%

xcopy /S /Y %CORE_LIB%\lib\*                 %LUA_LIB_DIR%
xcopy /S /Y %DNS_LIB%\lib\*                  %LUA_LIB_DIR%
xcopy /S /Y %LIMIT_TRAFFIC_LIB%\lib\*        %LUA_LIB_DIR%
xcopy /S /Y %LOCK_LIB%\lib\*                 %LUA_LIB_DIR%
xcopy /S /Y %LRUCACHE_LIB%\lib\*             %LUA_LIB_DIR%
xcopy /S /Y %MEMCACHED_LIB%\lib\*            %LUA_LIB_DIR%
xcopy /S /Y %MYSQL_LIB%\lib\*                %LUA_LIB_DIR%
xcopy /S /Y %REDIS_LIB%\lib\*                %LUA_LIB_DIR%
xcopy /S /Y %STRING_LIB%\lib\*               %LUA_LIB_DIR%
xcopy /S /Y %UPLOAD_LIB%\lib\*               %LUA_LIB_DIR%
xcopy /S /Y %UPSTREAM_HEALTHCHECK_LIB%\lib\* %LUA_LIB_DIR%
xcopy /S /Y %WEBSOCKET_LIB%\lib\*            %LUA_LIB_DIR%

echo success
cd /d %ORG_DIR%