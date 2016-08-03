SET ORG_DIR=%cd%
cd /d %~dp0

del /S /Q objs\*.obj
nmake -f makefileW64

cd /d %ORG_DIR%
