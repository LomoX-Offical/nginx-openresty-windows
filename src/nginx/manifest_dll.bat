SET ORG_DIR=%cd%
cd /d %~dp0
mt -manifest objs/nocrt.xml -outputresource:"%1";2

echo success
cd /d %ORG_DIR%