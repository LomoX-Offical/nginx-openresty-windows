SET ORG_DIR=%cd%
cd /d %~dp0

del /S /Q objs\*.obj
nmake

cd /d %ORG_DIR%
