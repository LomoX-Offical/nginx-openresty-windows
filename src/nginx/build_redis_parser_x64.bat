SET ORG_DIR=%cd%
cd /d %~dp0

devenv ..\lua-redis-parser-0.12\redis-parser.vcproj /REBUILD "Release|x64"
copy /Y ..\lua-redis-parser-0.12\x64\Release\redis_parser.dll objs\
copy /Y ..\lua-redis-parser-0.12\x64\Release\redis_parser.pdb objs\
