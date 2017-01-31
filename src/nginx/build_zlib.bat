SET ORG_DIR=%cd%
SET nginxpath=%~dp0

cd /d %~dp0
cd /d .\objs\lib\zlib\

del /S /Q *.obj

cmd /c nmake -f win32\Makefile.msc


copy /Y .\out32dll\zlib.dll  %nginxpath%\objs\
copy /Y .\out32dll\zlib.pdb  %nginxpath%\objs\

cmd /c mt -manifest %nginxpath%\objs\nocrt.xml -outputresource:%nginxpath%\objs\zlib.dll;2

cd /d %ORG_DIR%
