SET ORG_DIR=%cd%
cd /d %~dp0

devenv ..\lua-cjson-2.1.0.4\cjson.vcproj /REBUILD "Release|x64"
copy /Y ..\lua-cjson-2.1.0.4\x64\Release\cjson.dll objs\
