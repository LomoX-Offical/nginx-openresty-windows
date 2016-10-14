SET ORG_DIR=%cd%
SET nginxpath=%~dp0

cd /d %~dp0
cd /d .\objs\lib_x64\openssl\

del /S /Q *.obj

cmd /c perl Configure VC-WIN64A no-asm --prefix=openssl
cmd /c ms\do_win64a

cmd /c nmake -f ms\ntdll.mak
cmd /c nmake -f ms\ntdll.mak install


copy /Y .\out32dll\libeay32.dll  %nginxpath%\objs\
copy /Y .\out32dll\libeay32.pdb  %nginxpath%\objs\
copy /Y .\out32dll\ssleay32.dll  %nginxpath%\objs\
copy /Y .\out32dll\ssleay32.pdb  %nginxpath%\objs\

cmd /c mt -manifest %nginxpath%\objs\nocrt.xml -outputresource:%nginxpath%\objs\libeay32.dll;2
cmd /c mt -manifest %nginxpath%\objs\nocrt.xml -outputresource:%nginxpath%\objs\ssleay32.dll;2

cd /d %ORG_DIR%
