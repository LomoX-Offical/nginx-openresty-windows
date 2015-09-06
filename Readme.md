## Nginx Openresty For Windows ##

### lastest release ###
Version:1.9.3.1001

32 bit: http://pan.baidu.com/s/1jGiwonk

64 bit: http://pan.baidu.com/s/1jGIUbI2

    Release time: 2015-09-06

    changelog：

    * upgrade the modules of openresty_for_windows to version 1.9.3.1
		actually, only ngx_postgres_module has upgraded from ngx_postgres-1.0rc6 to ngx_postgres-1.0rc7
	
	* pdb file include in the binary cab
	       



### about ###

OpenResty is a fast web app server by extending nginx.

**Nginx Openresty For Windows** is Nginx in windows Version with Openresty.

it has some feature:

- high performance
- concurrent more than twenty thousand connections
- multi process
- various bugs fixed compare with nginx orginal

it has been complie with these addon modules:

- ngx-coolkit-module
- echo-nginx-module
- set-misc-nginx-module
- ngx-postgres-module
- ngx-lua-module
- headers-more-nginx-module
- rds-json-nginx-module
- nginx-http-concat-module
- redis2-nginx-module
- lua-cjson

### resource ###

开源架构群:**167813458**

Documentation of Nginx at [http://www.nginx.org](http://www.nginx.org)

Documentation of Openresty at [http://www.openresty.org](http://www.openresty.org)


### history ###

Version:1.7.10.2  ([http://pan.baidu.com/s/1i3ITTFv](http://pan.baidu.com/s/1i3ITTFv))

    Release time: 2015-8-7
    Changelog: update openresty to version:1.7.10.2

Version:1.7.10.2001

32 bit: http://pan.baidu.com/s/1pJ5l1s3

64 bit: http://pan.baidu.com/s/1kTxmfmJ

    Release time: 2015-8-20

    Changelog: 
    1、add concat module to 32 & 64 bit respectively
    2、add redis2 module to 32 & 64 bit respectively
    3、add cjson  module to 32 & 64 bit respectively
    4、add lua51.dll runtime for luajit for 32 & 64 bit respectively
	
Version:1.7.10.2002

32 bit: http://pan.baidu.com/s/1pJ5l1s3

64 bit: http://pan.baidu.com/s/1dDAVQq1

    Release time: 2015-8-25

    changelog：

    *  fix the incompatible lua_shared_dict directive of ngx_lua module, cause the error below:

        nginx: [emerg] invalid lua shared dict size "10m"

