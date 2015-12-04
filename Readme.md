## Nginx Openresty For Windows ##

### lastest release ###

Version:1.9.7.1002

32 bit: http://pan.baidu.com/s/1mgXobxe

64 bit: http://pan.baidu.com/s/1pKjtk3T

>Release time: 2015-11-04

>Changelog:  

- update ngx_lua module to 0.9.19
- update headers-more-nginx-module to 0.28
- update ngx_lua_upstream module to 0.04
- update rds-csv-nginx-module to 0.07

- update lua-cjson module to 2.1.0.3
- update lua-rds-parser module to 0.06
- update lua-redis-parser module to 0.12

- update LuaJIT to 2.1.0 beta1



### about ###

OpenResty is a fast web app server by extending nginx.

**Nginx Openresty For Windows  (NOW)**  is Nginx in windows Version with Openresty.

it has some feature:

- high performance
- concurrent more than twenty thousand connections
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