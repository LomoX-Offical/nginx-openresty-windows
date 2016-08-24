SET ORG_DIR=%cd%
cd /d %~dp0

cmd /c build_luajit_x64.bat
cmd /c build_pcre_x64.bat
cmd /c build_cjson_x64.bat
cmd /c build_redis_parser_x64.bat
cmd /c build_nginx_x64.bat
cmd /c restylib.bat

cd /d %ORG_DIR%
