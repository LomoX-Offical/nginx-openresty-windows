SET sourcepath=%CD%
SET nginxpath=%~dp0

setlocal EnableDelayedExpansion

cd /d %~dp0
cd /d ..\LuaJIT-2.1-20160517\src\

SET objspath=!cd!

cd /d ..\..\luajit-root\luajit\
SET rootpath=!cd!

cd /d %objspath%
cmd /c msvcbuild.bat debug

copy /Y %objspath%\lua51.dll  %nginxpath%\objs\
copy /Y %objspath%\lua51.pdb  %nginxpath%\objs\

mt -manifest %nginxpath%\objs\nocrt.xml -outputresource:%nginxpath%\objs\lua51.dll;2

copy /Y %objspath%\lua51.dll  %rootpath%\bin\
copy /Y %objspath%\lua51.pdb  %rootpath%\bin\
copy /Y %objspath%\luajit.exe %rootpath%\bin\
copy /Y %objspath%\luajit.pdb %rootpath%\bin\

copy /Y %objspath%\lua51.lib  %rootpath%\lib\

copy /Y %objspath%\lauxlib.h  %rootpath%\include\luajit-2.1\
copy /Y %objspath%\lua.h      %rootpath%\include\luajit-2.1\
copy /Y %objspath%\lua.hpp    %rootpath%\include\luajit-2.1\
copy /Y %objspath%\luaconf.h  %rootpath%\include\luajit-2.1\
copy /Y %objspath%\luajit.h   %rootpath%\include\luajit-2.1\
copy /Y %objspath%\lualib.h   %rootpath%\include\luajit-2.1\

cd %sourcepath%
