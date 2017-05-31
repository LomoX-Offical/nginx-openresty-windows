SET ORG_DIR=%cd%
cd /d %~dp0

devenv ..\lua-redis-parser-0.13\redis-parser.vcproj /REBUILD "Release|x64"
copy /Y ..\lua-redis-parser-0.13\x64\Release\redis_parser.dll objs\
copy /Y ..\lua-redis-parser-0.13\x64\Release\redis_parser.pdb objs\
