SET ORG_DIR=%cd%
cd /d %~dp0

devenv ..\lua-rds-parser-0.06\rds-parser.vcproj /REBUILD "Release|Win32"
copy /Y ..\lua-rds-parser-0.06\Release\rds_parser.dll objs\
copy /Y ..\lua-rds-parser-0.06\Release\rds_parser.pdb objs\
