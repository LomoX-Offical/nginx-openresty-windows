SET nginxpath=%~dp0

setlocal EnableDelayedExpansion

cd /d %~dp0\objs\lib_x64\pcre

nmake -f makefile.msvc clean
nmake -f makefile.msvc 

cd %nginxpath%
