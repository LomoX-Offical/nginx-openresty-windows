## Nginx Openresty For Windows ##

### lastest release ###

Version:1.9.4.1001

32 bit: http://pan.baidu.com/s/1o6Kike2

64 bit: http://pan.baidu.com/s/1mgzn1Qo

Release time: 2015-09-12

Changelog: 
big update :
update nginx core to 1.9.4
update openssl to 1.0.2d
update pcre to 8.37

now openresty for windows support these modules below:
ipv6 mail stream

nginx offical module:
http_realip_module
http_addition_module
http_sub_module
http_dav_module
http_stub_status_module
http_flv_module
http_mp4_module
http_gunzip_module
http_gzip_static_module
http_auth_request_module
http_random_index_module
http_secure_link_module
mail
http_ssl_module
mail_ssl_module
http_spdy_module

addon module:
ngx_devel_kit-0.2.19
echo-nginx-module-0.58
ngx_coolkit-0.2rc3
set-misc-nginx-module-0.29
ngx_postgres-1.0rc7
form-input-nginx-module-0.11
encrypted-session-nginx-module-0.04
ngx_lua
ngx_lua_upstream-0.03
headers-more-nginx-module-0.26
array-var-nginx-module-0.04
nginx-http-concat-module
rds-json-nginx-module-0.14
redis2-nginx-module-0.12
        

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
		
		
Version:1.9.3.1001

32 bit: http://pan.baidu.com/s/1jGiwonk

64 bit: http://pan.baidu.com/s/1jGIUbI2

Release time: 2015-09-06

changelog：

* upgrade the modules of openresty_for_windows to version 1.9.3.1
    actually, only ngx_postgres_module has upgraded from ngx_postgres-1.0rc6 to ngx_postgres-1.0rc7

* pdb file include in the binary cab

