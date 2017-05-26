SET ORG_DIR=%cd%
cd /d %~dp0

devenv ..\lua-cjson-2.1.0.5\cjson.vcproj /REBUILD "Release|x64"
copy /Y ..\lua-cjson-2.1.0.5\x64\Release\cjson.dll objs\
copy /Y ..\lua-cjson-2.1.0.5\x64\Release\cjson.pdb objs\
