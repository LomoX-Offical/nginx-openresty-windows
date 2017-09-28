## Nginx Openresty For Windows ##
[ 语言: [English](Readme-en.md), [中文](Readme.md)]

### 最新版本 ###
版本号:1.13.5.1001

32 位下载地址: http://pan.baidu.com/s/1c1JvOli
        
64 位下载地址: http://pan.baidu.com/s/1dFbAAnZ

> 发布时间: 2017-09-28

> 修改日志:  
> 模块:
- 更新 echo-nginx-module 到 0.61
- 更新 ngx_postgres 到 1.0
- 更新 ngx_lua_upstream 到 0.07
- 更新 ngx-lua-module 到 0.10.10
- 更新 LuaJIT 到 2.1-20170808

> 库:
- 更新 lua-resty-core 到 0.1.12
- 更新 lua-resty-dns 到 0.19
- 更新 lua-resty-limit-traffic 到 0.04
- 更新 lua-resty-lock 到 0.07
- 更新 lua-resty-mysql 到 0.20
- 更新 lua-resty-string 到 0.10
- 更新 lua-resty-upstream-healthcheck 到 0.05

> Nginx 核心:
- 更新 nginx core 到 1.13.5



### IOCP版本(开发版本) ###
版本号:1.11.5.1001

32 位下载地址: http://pan.baidu.com/s/1kVdhEPh

64 位下载地址: http://pan.baidu.com/s/1o7IcPVO

>发布时间: 2016-10-24

>修改日志: 

>Nginx:

- 为 windows 版本添加了IOCP(支持多进程）网络事件模型



### 关于 ###

OpenResty is a fast web app server by extending nginx.

**Nginx Openresty For Windows  (NOW)**  is Nginx in windows Version with Openresty.

it has some feature:

- high performance
- concurrent more than twenty thousand connections
- multi process
- shared memory supported
- udp proxy supported
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

版本号:1.9.7.1002

32 位下载地址: http://pan.baidu.com/s/1mgXobxe

64 位下载地址: http://pan.baidu.com/s/1pKjtk3T

>发布时间: 2015-12-04

>修改日志:  

- 更新 ngx_lua module 版本到 0.9.19
- 更新 headers-more-nginx-module 版本到 0.28
- 更新 ngx_lua_upstream module 版本到 0.04
- 更新 rds-csv-nginx-module 版本到 0.07
- 更新 lua-cjson module 版本到 2.1.0.3
- 更新 lua-rds-parser module 版本到 0.06
- 更新 lua-redis-parser module 版本到 0.12
- 更新 LuaJIT 版本到 2.1.0 beta1

版本号:1.9.9.1001

32 位下载地址: http://pan.baidu.com/s/1kUekvMv

64 位下载地址: http://pan.baidu.com/s/1mgPpprU

>发布时间: 2016-01-11

>修改日志:  
- 更新 nginx 版本到 1.9.9
- 更新 headers-more-nginx-module模块 版本到 0.29
- 更新 LuaJIT 版本到 2.1-20151219
- 更新 ngx_lua版本到 0.9.20
- 更新 lua-resty-core 版本到 0.1.3
- 更新 lua-resty-redis 版本到 0.22


版本号:1.9.10.1001

32 位下载地址: http://pan.baidu.com/s/1jHlhiXw

64 位下载地址: http://pan.baidu.com/s/1eQUuqoq

>发布时间: 2016-02-02

>修改日志:  
- 更新 nginx 版本到 1.9.10
- 更新 openssl 版本到 1.0.2f
- 更新 LuaJIT 版本到 2.1-20160108
- 更新 ngx_lua版本到 0.10.00
- 更新 lua-resty-core 版本到 0.1.4



版本号:1.9.12.1001

32 位下载地址: http://pan.baidu.com/s/1eR1bR9o

64 位下载地址: http://pan.baidu.com/s/1hqPeoJy

>发布时间: 2016-03-07

>修改日志:  
- 更新 nginx 版本到 1.9.12
- 更新 openssl 版本到 1.0.2g
- 更新ngx_lua 版本到 0.10.1rc0


版本号:1.9.14.1001

32 位下载地址: http://pan.baidu.com/s/1kUYTLkj

64 位下载地址: http://pan.baidu.com/s/1qXZz82S

>发布时间: 2016-04-13

>修改日志:  
- 更新 nginx 版本到 1.9.14
- 更新 Lua Nginx Module 到 0.10.2.
- 更新 Set Misc Nginx Module 到 0.30.
- 更新 Array Var Nginx Module 到 0.05.
- 更新 Lua Resty Core Library 到 0.1.5.
- 更新 Lua Resty Upstream Healthcheck Library 到 0.04.
- 更新 Lua Resty DNS Library 到 0.15.


版本号:1.9.15.1001

32 位下载地址: http://pan.baidu.com/s/1hsxxfxy

64 位下载地址: http://pan.baidu.com/s/1qXM8ZBQ

>发布时间: 2016-04-27

>修改日志:  
- 更新 nginx 版本到 1.9.15
- 更新 cjson dll
- 适配ngx_lua_module的ngx.worker.id函数，现在windows上ngx_lua模块也可以使用这个函数了


版本号:1.9.15.1002

32 位下载地址: http://pan.baidu.com/s/1bpsjbAJ

64 位下载地址: http://pan.baidu.com/s/1slw0ppN

>发布时间: 2016-05-26

>修改日志:  
- ngx_stream_proxy_module模块支持udp(感谢 lihui0213 贡献的代码）
- openssl更新到1.0.2h


版本号:1.11.2.1001

32 位下载地址: http://pan.baidu.com/s/1cIBUbW

64 位下载地址: http://pan.baidu.com/s/1miETFQw

>发布时间: 2016-07-11

>修改日志:
- 更新nginx core 到1.11.2
- 更新pcre到8.39
- 更新LuaJIT 2.1-20160517
- 在listen指令中支持so_keepalive参数


版本号:1.11.3.1001

32 位下载地址: http://pan.baidu.com/s/1skNscCt

64 位下载地址: http://pan.baidu.com/s/1nuP2ixj

>发布时间: 2016-08-03

>修改日志:
- 更新nginx core 到1.11.3


版本号:1.11.4.1001

32 位下载地址: http://pan.baidu.com/s/1o7ZBGz4

64 位下载地址: http://pan.baidu.com/s/1mig1zcs

>发布时间: 2016-09-14

>修改日志:
>Nginx:
- 更新 nginx core 到 1.11.4

>Modules:
- 更新 echo-nginx-module 到 0.60
- 更新 encrypted-session-nginx-module 到 0.06
- 更新 headers-more-nginx-module 到 0.31
- 更新 ngx_lua_upstream 到 0.06
- 更新 ngx_lua_module 到 0.10.6
- 更新 set-misc-nginx-module 到 0.31 

>Libs:
- 更新 lua-resty-core 到 0.1.8
- 更新 lua-resty-dns 到 0.17
- 更新 lua-resty-redis 到 0.25

>Tools:
- 更新 resty-cli 到 0.13


版本号:1.11.5.1001

32 位下载地址: http://pan.baidu.com/s/1nvMysvn

64 位下载地址: http://pan.baidu.com/s/1nv1z993

>发布时间: 2016-10-14

>修改日志:

>Nginx:
- 更新 nginx core 到 1.11.5

>Libs:
- 更新 openssl 到 1.0.2j



版本号:1.11.6.1001

32 位下载地址: http://pan.baidu.com/s/1dELfLKX

64 位下载地址: http://pan.baidu.com/s/1eRU7dL4

>发布时间: 2016-12-13

>修改日志:  

>Nginx:
- 更新 nginx 到版本 1.11.6

>Luajit lib:
- 更新 LuaJIT 到版本 v2.1-20161104: https://github.com/openresty/luajit2/tags

>Modules:
- 更新 headers-more-nginx-module 模块到 0.32
- 更新 ngx-lua-module 模块到 0.10.7

>Libs:
- 更新 lua-resty-core 库到 0.1.9
- 更新 lua-resty-dns 库到 0.18
- 更新 lua-resty-limit-traffic 库到 0.01
- 更新 lua-resty-mysql 库到 0.17
- 更新 lua-resty-redis 库到 0.26
- 更新 lua-resty-upload 库到 0.10
- 更新 lua-resty-websocket 库到 0.06
- 更新 resty-cli 库到 0.16



版本号:1.11.7.1001

32 位下载地址: http://pan.baidu.com/s/1bpvHYf9

64 位下载地址: http://pan.baidu.com/s/1dEHcwiH

>发布时间: 2016-12-19

>修改日志:  

>Nginx:
- 更新 nginx 到版本 1.11.7



版本号:1.11.7.1002

32 位下载地址: http://pan.baidu.com/s/1qYhLRFA

64 位下载地址: http://pan.baidu.com/s/1bVxnPk

>发布时间: 2016-01-18

>修改日志:  

>Nginx:
- 添加更多的导出函数，使ngx目录下面的库文件可以正确引用，目前一共有82个函数被导出


版本号:1.11.9.1001

32 位下载地址: http://pan.baidu.com/s/1pLczj3H

64 位下载地址: http://pan.baidu.com/s/1ciVqkY

>发布时间: 2017-02-06

>修改日志:  

>Nginx:
- 更新 nginx core 到版本 1.11.9
- 更新 pcre 到版本 8.40
- 更新 zlib 到版本 1.2.11


版本号:1.13.0.1001

32 位下载地址: http://pan.baidu.com/s/1qYNk6h2
        
64 位下载地址: http://pan.baidu.com/s/1gf89Mr5

> 发布时间: 2017-05-31

> 修改日志:  
> 模块:
- 更新 lua-cjson 到 2.1.0.5
- 更新 lua-redis-parser 到 0.13
- 更新 redis2-nginx-module 到 0.14
- 更新 drizzle-nginx-module 到 0.1.10
- 更新 ngx-lua-module 到 0.10.9rc5
- 更新 memc-nginx-module 到 0.18
- 更新 LuaJIT 到 2.1-20170405

> 库:
- 更新 lua-resty-core 到 0.1.11
- 更新 lua-resty-limit-traffic 到 0.03
- 更新 lua-resty-mysql 到 0.19
- 更新 lua-resty-lock 到 0.06
- 更新 lua-resty-lrucache 到 0.06

- 更新 resty-cli 到 0.17

> Nginx 核心:
- 更新 nginx core 到 1.13.0


版本号:1.13.4.1001

32 位下载地址: http://pan.baidu.com/s/1c27yqA0
        
64 位下载地址: http://pan.baidu.com/s/1pLwS3Wn

> 发布时间: 2017-08-16

> 修改日志:  
> 库:
- 更新 openssl 到 1.0.2l
- 更新 pcre 到 8.41

> Nginx 核心:
- 更新 nginx core 到 1.13.4

