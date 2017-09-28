## Nginx Openresty For Windows ##
[ languages: [中文](Readme.md), [English](Readme-en.md) ]

### lastest release ###
version:1.13.5.1001

32 bit: http://pan.baidu.com/s/1c1JvOli
        
64 bit: http://pan.baidu.com/s/1dFbAAnZ

>Publish Time: 2017-09-28

>Changelog:  
> Moules:
- upgrade echo-nginx-module to 0.61
- upgrade ngx_postgres to 1.0
- upgrade ngx_lua_upstream to 0.07
- upgrade ngx-lua-module to 0.10.10
- upgrade LuaJIT to 2.1-20170808

> Libs:
- upgrade lua-resty-core to 0.1.12
- upgrade lua-resty-dns to 0.19
- upgrade lua-resty-limit-traffic to 0.04
- upgrade lua-resty-lock to 0.07
- upgrade lua-resty-mysql to 0.20
- upgrade lua-resty-string to 0.10
- upgrade lua-resty-upstream-healthcheck to 0.05

- upgrade resty-cli to 0.19


> Nginx core:
- upgrade nginx core to 1.13.5




### IOCP version (develop) ###
version:1.11.5.1001

32 bit: http://pan.baidu.com/s/1kVdhEPh

64 bit: http://pan.baidu.com/s/1o7IcPVO

>Publish Time: 2016-10-24

>Changelog: 

>Nginx:

- add IOCP (support multi-thread) network event model for Windows



### about ###

OpenResty is a fast web app server by extending nginx.

**Nginx Openresty For Windows  (NOW)**  is Nginx in windows Version with Openresty.

it has some feature:

- high performance
- concurrent more than twenty thousand connections
- shared memory supported
- udp proxy supported
- multi process
- various bugs fixed compare with nginx orginal

it has been complie with these offical modules:

- http_realip_module
- http_addition_module
- http_sub_module
- http_dav_module
- http_stub_status_module
- http_flv_module
- http_mp4_module
- http_gunzip_module
- http_gzip_static_module
- http_auth_request_module
- http_random_index_module
- http_secure_link_module
- mail
- http_ssl_module
- mail_ssl_module
- http_v2_module

and these addon module:

- array-var-nginx-module
- ngx_devel_kit
- ngx-coolkit-module
- echo-nginx-module
- form-input-nginx-module
- encrypted-session-nginx-module
- set-misc-nginx-module
- ngx-postgres-module
- ngx-lua-module
- ngx_lua_upstream
- headers-more-nginx-module
- rds-json-nginx-module
- nginx-http-concat-module
- redis2-nginx-module

and these C module for Lua:

- lua-cjson
- lua-redis-parser
- lua-rds-parser


### resource ###

开源架构群:**167813458**

Documentation of Nginx at [http://www.nginx.org](http://www.nginx.org)

Documentation of Openresty at [http://www.openresty.org](http://www.openresty.org)


### history ###

Version:1.7.10.2  ([http://pan.baidu.com/s/1i3ITTFv](http://pan.baidu.com/s/1i3ITTFv))

>Release time: 2015-8-7
  
>Changelog: update openresty to version:1.7.10.2

Version:1.7.10.2001

32 bit: http://pan.baidu.com/s/1pJ5l1s3

64 bit: http://pan.baidu.com/s/1kTxmfmJ

>Release time: 2015-8-20

>Changelog:  
* add concat module to 32 & 64 bit respectively   
* add redis2 module to 32 & 64 bit respectively  
* add cjson  module to 32 & 64 bit respectively  
* add lua51.dll runtime for luajit for 32 & 64 bit respectively 

Version:1.7.10.2002

32 bit: http://pan.baidu.com/s/1pJ5l1s3

64 bit: http://pan.baidu.com/s/1dDAVQq1

>Release time: 2015-8-25

>changelog：  
*  fix the incompatible lua_shared_dict directive of ngx_lua module, cause the error below:  
```nginx
nginx: [emerg] invalid lua shared dict size "10m"
```    
    	
Version:1.9.3.1001

32 bit: http://pan.baidu.com/s/1jGiwonk

64 bit: http://pan.baidu.com/s/1jGIUbI2

>Release time: 2015-09-06

>changelog： 
* upgrade the modules of Openresty to version 1.9.3.1  
actually, only ngx_postgres_module has upgraded from  
ngx_postgres-1.0rc6 to ngx_postgres-1.0rc7  
* pdb file include in the binary cab

Version:1.9.4.1001

32 bit: http://pan.baidu.com/s/1o6Kike2

64 bit: http://pan.baidu.com/s/1mgzn1Qo

>Release time: 2015-09-12

>Changelog: 

>big update :  
-  update nginx core to 1.9.4  
-  update openssl to 1.0.2d  
-  update pcre to 8.37  

>build with new configures:
- ipv6
- mail
- stream

>build with these modules below:
- nginx offical module:
- http_realip_module
- http_addition_module
- http_sub_module
- http_dav_module
- http_stub_status_module
- http_flv_module
- http_mp4_module
- http_gunzip_module
- http_gzip_static_module
- http_auth_request_module
- http_random_index_module
- http_secure_link_module
- http_ssl_module
- mail_ssl_module
- http_spdy_module

>addon module:
- ngx_devel_kit-0.2.19
- echo-nginx-module-0.58
- ngx_coolkit-0.2rc3
- set-misc-nginx-module-0.29
- ngx_postgres-1.0rc7
- form-input-nginx-module-0.11
- encrypted-session-nginx-module-0.04
- ngx_lua
- ngx_lua_upstream-0.03
- headers-more-nginx-module-0.26
- array-var-nginx-module-0.04
- nginx-http-concat-module
- rds-json-nginx-module-0.14
- redis2-nginx-module-0.12


Version:1.9.4.1002

32 bit: http://pan.baidu.com/s/1mg1V5Ny

64 bit: http://pan.baidu.com/s/1i393jVJ

>Release time: 2015-09-15

>Changelog:   
*  when compile nginx export all the functions that resty needed,   
now in total 49 functions have been exported:  
 *   ngx_http_lua_ffi_encode_base64 @1
 *   ngx_http_lua_ffi_decode_base64 @2
 *   ngx_http_lua_ffi_get_ctx_ref @3
 *   ngx_http_lua_ffi_set_ctx_ref @4
 *   ngx_http_lua_ffi_exit @5
 *   ngx_http_lua_ffi_md5_bin @6
 *   ngx_http_lua_ffi_md5 @7
 *   ngx_http_lua_ffi_sha1_bin @8
 *   ngx_http_lua_ffi_get_resp_status @9
 *   ngx_http_lua_ffi_set_resp_status @10
 *   ngx_http_lua_ffi_is_subrequest @11
 *   ngx_http_lua_ffi_headers_sent @12
 *   ngx_http_lua_ffi_compile_regex @13
 *   ngx_http_lua_ffi_exec_regex @14
 *   ngx_http_lua_ffi_destroy_regex @15
 *   ngx_http_lua_ffi_compile_replace_template @16
 *   ngx_http_lua_ffi_create_script_engine @17
 *   ngx_http_lua_ffi_init_script_engine @18
 *   ngx_http_lua_ffi_destroy_script_engine @19
 *   ngx_http_lua_ffi_script_eval_len @20
 *   ngx_http_lua_ffi_script_eval_data @21
 *   ngx_http_lua_ffi_max_regex_cache_size @22
 *   ngx_http_lua_ffi_req_get_headers_count @23
 *   ngx_http_lua_ffi_req_get_headers @24
 *   ngx_http_lua_ffi_req_get_uri_args_count @25
 *   ngx_http_lua_ffi_req_get_querystring_len @26
 *   ngx_http_lua_ffi_req_get_uri_args @27
 *   ngx_http_lua_ffi_req_start_time @28
 *   ngx_http_lua_ffi_req_get_method @29
 *   ngx_http_lua_ffi_req_get_method_name @30
 *   ngx_http_lua_ffi_req_set_method @31
 *   ngx_http_lua_ffi_req_header_set_single_value @32
 *   ngx_http_lua_ffi_set_resp_header @33
 *   ngx_http_lua_ffi_get_resp_header @34
 *   ngx_http_lua_ffi_shdict_get @35
 *   ngx_http_lua_ffi_shdict_incr @36
 *   ngx_http_lua_ffi_shdict_store @37
 *   ngx_http_lua_ffi_shdict_flush_all @38
 *   ngx_http_lua_ffi_now @39
 *   ngx_http_lua_ffi_time @40
 *   ngx_http_lua_ffi_uri_escaped_length @41
 *   ngx_http_lua_ffi_escape_uri @42
 *   ngx_http_lua_ffi_unescape_uri @43
 *   ngx_http_lua_ffi_var_get @44
 *   ngx_http_lua_ffi_var_set @45
 *   ngx_http_lua_ffi_worker_pid @46
 *   ngx_http_lua_ffi_worker_exiting @47
 *   ngx_hex_dump @48
 *   ngx_atoi @49
 
Version:1.9.4.1003

32 bit: http://pan.baidu.com/s/1sjn8K9n

64 bit: http://pan.baidu.com/s/1gdHFtXx

>Release time: 2015-09-24

>Changelog:  

- lua_redis_parser and lua_rds_parser module added  
- bugfix - when * occured in include directive nginx crashed  



Version:1.9.5.1001

32 bit: http://pan.baidu.com/s/1kT1tydx

64 bit: http://pan.baidu.com/s/1ntlasC5

>Release time: 2015-10-10

>Changelog:  

- update nginx to 1.9.5 version.
- The ngx_http_v2_module module (1.9.5) provides support for HTTP/2 and supersedes the ngx_http_spdy_module module.



Version:1.9.7.1001

32 bit: http://pan.baidu.com/s/1o68bOEI

64 bit: http://pan.baidu.com/s/1kTzu1oz

>Release time: 2015-11-19

>Changelog:  

- update nginx to 1.9.7 version.
- The ngx_http_v2_module module (1.9.7) provides support for HTTP/2 and supersedes the ngx_http_spdy_module module.


Version:1.9.7.1002

32 bit: http://pan.baidu.com/s/1mgXobxe

64 bit: http://pan.baidu.com/s/1pKjtk3T

>Release time: 2015-12-04

>Changelog:  

- update ngx_lua module to 0.9.19
- update headers-more-nginx-module to 0.28
- update ngx_lua_upstream module to 0.04
- update rds-csv-nginx-module to 0.07
- update lua-cjson module to 2.1.0.3
- update lua-rds-parser module to 0.06
- update lua-redis-parser module to 0.12
- update LuaJIT to 2.1.0 beta1

version:1.9.9.1001

32 bit: http://pan.baidu.com/s/1kUekvMv

64 bit: http://pan.baidu.com/s/1mgPpprU

>Changelog:  

- update nginx core to 1.9.9
- update ngx_lua module to 0.9.20
- update LuaJIT to 2.1-20151219
- update headers-more-nginx-module to 0.29
- update rds-csv-nginx-module to 0.07
- update lua-resty-redis to 0.22
- update lua-resty-core to 0.1.3


version:1.9.10.1001

32 bit: http://pan.baidu.com/s/1jHlhiXw

64 bit: http://pan.baidu.com/s/1eQUuqoq

>Changelog:  

- update nginx core to 1.9.10
- update openssl to 1.0.2f
- update LuaJIT to 2.1-20160108
- update ngx_lua to 0.10.00
- update lua-resty-core to 0.1.4



version:1.9.12.1001

32 bit: http://pan.baidu.com/s/1eR1bR9o

64 bit: http://pan.baidu.com/s/1hqPeoJy

>Changelog:  

- nginx core update to 1.9.12
- update openssl to 1.0.2g
- update ngx_lua_module to 0.10.1rc0


version:1.9.14.1001

32 bit: http://pan.baidu.com/s/1kUYTLkj
        
64 bit: http://pan.baidu.com/s/1qXZz82S

>Changelog:  

- upgraded nginx core to 1.9.14
- upgraded Lua Nginx Module to 0.10.2.
- upgraded Set Misc Nginx Module to 0.30.
- upgraded Array Var Nginx Module to 0.05.
- upgraded Lua Resty Core Library to 0.1.5.
- upgraded Lua Resty Upstream Healthcheck Library to 0.04.
- upgraded Lua Resty DNS Library to 0.15.


version:1.9.15.1001

32 bit: http://pan.baidu.com/s/1hsxxfxy
        
64 bit: http://pan.baidu.com/s/1qXM8ZBQ

>Changelog:  

- upgraded nginx core to 1.9.15
- upgraded cjson dll
- support for the function ngx.worker.id in ngx_lua_module


version:1.9.15.1002

32 bit: http://pan.baidu.com/s/1bpsjbAJ
        
64 bit: http://pan.baidu.com/s/1slw0ppN

>Publish Time: 2016-05-26

>Changelog:  

- ngx_stream_proxy_module support udp(Thanks to lihui0213）
- upgrade openssl to 1.0.2h


version:1.11.2.1001

32 bit: http://pan.baidu.com/s/1cIBUbW
        
64 bit: http://pan.baidu.com/s/1miETFQw

>Publish Time: 2016-07-11

>Changelog:  

- update nginx core to 1.11.2
- update pcre to 8.39
- update LuaJIT to 2.1-20160517
- support so_keepalive parameter in listen directive


version:1.11.3.1001

32 bit: http://pan.baidu.com/s/1skNscCt
        
64 bit: http://pan.baidu.com/s/1nuP2ixj

>Publish Time: 2016-08-03

>Changelog:  

- update nginx core to 1.11.3


version:1.11.4.1001

32 bit: http://pan.baidu.com/s/1o7ZBGz4
        
64 bit: http://pan.baidu.com/s/1mig1zcs

>Publish Time: 2016-09-14

>Changelog:  

>Nginx:
- upgrade nginx core to 1.11.4

>Modules:
- upgrade echo-nginx-module to 0.60
- upgrade encrypted-session-nginx-module to 0.06
- upgrade headers-more-nginx-module to 0.31
- upgrade ngx_lua_upstream to 0.06
- upgrade ngx_lua_module to 0.10.6
- upgrade set-misc-nginx-module to 0.31 

>Libs:
- upgrade lua-resty-core to 0.1.8
- upgrade lua-resty-dns to 0.17
- upgrade lua-resty-redis to 0.25

>Tools:
- upgrade resty-cli to 0.13


version:1.11.5.1001

32 bit: http://pan.baidu.com/s/1nvMysvn
        
64 bit: http://pan.baidu.com/s/1nv1z993

>Publish Time: 2016-10-14

>Changelog:  

>Nginx:
- upgrade nginx core to 1.11.5

>Libs:
- upgrade openssl to 1.0.2j


version:1.11.6.1001

32 bit: http://pan.baidu.com/s/1dELfLKX
        
64 bit: http://pan.baidu.com/s/1eRU7dL4

>Publish Time: 2016-12-13

>Changelog:  

>Nginx core:
- upgrade nginx core to 1.11.6

>Luajit lib:
- upgraded LuaJIT to v2.1-20161104: https://github.com/openresty/luajit2/tags

>Modules:
- upgrade headers-more-nginx-module to 0.32
- upgrade ngx-lua-module to 0.10.7

>Libs:
- upgrade lua-resty-core to 0.1.9
- upgrade lua-resty-dns to 0.18
- upgrade lua-resty-limit-traffic to 0.01
- upgrade lua-resty-mysql to 0.17
- upgrade lua-resty-redis to 0.26
- upgrade lua-resty-upload to 0.10
- upgrade lua-resty-websocket to 0.06
- upgrade resty-cli to 0.16


version:1.11.7.1001

32 bit: http://pan.baidu.com/s/1bpvHYf9
        
64 bit: http://pan.baidu.com/s/1dEHcwiH

>Publish Time: 2016-12-19

>Changelog:  

>Nginx core:
- upgrade nginx core to 1.11.7


version:1.11.7.1002

32 bit: http://pan.baidu.com/s/1qYhLRFA
        
64 bit: http://pan.baidu.com/s/1bVxnPk

>Publish Time: 2017-01-18

>Changelog:  

>Nginx core:
- add more export functions, now 82 functions exported in total


version:1.11.9.1001

32 bit: http://pan.baidu.com/s/1pLczj3H
        
64 bit: http://pan.baidu.com/s/1ciVqkY

>Publish Time: 2017-02-06

>Changelog:  

>Nginx core:
- update nginx core to 1.11.9
- update pcre to 8.40
- update zlib to version 1.2.11



version:1.13.0.1001

32 bit: http://pan.baidu.com/s/1qYNk6h2
        
64 bit: http://pan.baidu.com/s/1gf89Mr5

>Publish Time: 2017-05-31

>Changelog:  
> Moules:
- upgrade lua-cjson to 2.1.0.5
- upgrade lua-redis-parser to 0.13
- upgrade redis2-nginx-module to 0.14
- upgrade drizzle-nginx-module to 0.1.10
- upgrade ngx-lua-module 0.10.9rc5
- upgrade memc-nginx-module to 0.18
- upgrade LuaJIT to 2.1-20170405

> Libs:
- upgrade lua-resty-core to 0.1.11
- upgrade lua-resty-limit-traffic to 0.03
- upgrade lua-resty-mysql to 0.19
- upgrade lua-resty-lock to 0.06
- upgrade lua-resty-lrucache to 0.06

- upgrade resty-cli to 0.17

> Nginx core:
- upgrade nginx core to 1.13.0



version:1.13.4.1001

32 bit: http://pan.baidu.com/s/1c27yqA0
        
64 bit: http://pan.baidu.com/s/1pLwS3Wn

>Publish Time: 2017-08-16

>Changelog:  
> Libs:
- upgrade openssl to 1.0.2l
- upgrade pcre lib to 8.41

> Nginx core:
- upgrade nginx core to 1.13.4