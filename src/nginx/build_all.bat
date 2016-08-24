SET ORG_DIR=%cd%
cd /d %~dp0

cmd /c build_luajit.bat
cmd /c build_pcre.bat
cmd /c build_cjson.bat
cmd /c build_redis_parser.bat
cmd /c build_nginx.bat
cmd /c restylib.bat

cd /d %ORG_DIR%
