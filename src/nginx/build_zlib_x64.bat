SET ORG_DIR=%cd%
SET nginxpath=%~dp0

cd /d %~dp0
cd /d .\objs\lib_x64\zlib\

del /S /Q *.obj
del /S /Q *.manifest
del /S /Q *.res
del /S /Q *.exe
del /S /Q *.dll
del /S /Q *.lib

cmd /c nmake -f win32\Makefile.msc

copy /Y .\zlib1.dll  %nginxpath%\objs\zlib.dll
copy /Y .\zlib1.pdb  %nginxpath%\objs\zlib.pdb

cmd /c mt -manifest %nginxpath%\objs\nocrt.xml -outputresource:%nginxpath%\objs\zlib.dll;2

cd /d %ORG_DIR%
