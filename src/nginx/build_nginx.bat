SET ORG_DIR=%cd%
cd /d %~dp0

del /S /Q objs\*.obj

cd /d %ORG_DIR%
nmake