# vi:ft= et ts=4 sw=4

use lib 't/lib';
use Test::Resty;

plan tests => blocks() * 3;

run_tests();

__DATA__

=== TEST 1: bad --nginx value
--- opts: --nginx=/tmp/no/such/file
--- src
print("arg 0: ", arg[0])
print("arg 1: ", arg[1])
print("arg 2: ", arg[2])
print("arg 3: ", arg[3])

--- out
--- err_like chop
(?:Can't exec|valgrind:) "?/tmp/no/such/file"?: No such file or directory
--- ret: 2



=== TEST 2: -V
--- opts: -V
--- out
--- err_like eval
qr/^resty \d+.\d{2}
nginx version: /s
--- ret: 0



=== TEST 3: -h
--- opts: -h
--- out
resty [options] [lua-file [args]]

Options:
    -c NUM              Set maximal connection count (default: 64).
    -e PROG             Run the inlined Lua code in "prog".
    --gdb               Use GDB to run the underlying C process.
    --help              Print this help.

    --errlog-level LEVEL
                        Set nginx error_log level.
                        Can be debug, info, notice, warn, error, crit, alert, or emerg.

    --http-conf CONF    Specifies nginx.conf snippet inserted into the http {}
                        configuration block (multiple instances are supported).

    --http-include PATH Include the specified file in the nginx http configuration block
                        (multiple instances are supported).

    -I DIR              Add dir to the search paths for Lua libraries.

    --main-include PATH Include the specified file in the nginx main configuration block
                        (multiple instances are supported).

    --ns IP             Specify a custom name server (multiple instances are supported).

    --resolve-ipv6      Make the nginx resolver lookup both IPv4 and IPv6 addresses.

    --rr                Use Mozilla rr to record the execution of the underlying C process.

    --shdict 'NAME SIZE'
                        Create the specified lua shared dicts in the http
                        configuration block (multiple instances are supported).

    --nginx             Specify the nginx path (this option might be removed in the future).
    -V                  Print version numbers and nginx configurations.
    --valgrind          Use valgrind to run nginx.
    --valgrind-opts     Pass extra options to valgrind.

For bug reporting instructions, please see:

    <https://openresty.org/en/community.html>

Copyright (C) Yichun Zhang (agentzh). All rights reserved.
--- err
--- ret: 0



=== TEST 4: bad --http-include value
--- opts: --http-include=/tmp/no/such/file
--- src
--- out
--- err_like chop
Could not find http include '/tmp/no/such/file'
--- ret: 2



=== TEST 5: bad --main-include value
--- opts: --main-include=/tmp/no/such/file
--- src
--- out
--- err_like chop
Could not find main include '/tmp/no/such/file'
--- ret: 2



=== TEST 6: bad --main-include file content
--- opts: --main-include=/tmp/a.conf
--- user_files
>>> /tmp/a.conf
lua_shared_dict dogs 1m;
--- src
local dogs = ngx.shared.dogs
dogs:set("Tom", 32)
print(dogs:get("Tom"))
--- out
--- err
nginx: [emerg] "lua_shared_dict" directive is not allowed here in /tmp/a.conf:1
--- ret: 1



=== TEST 7: good --http-include file content
--- opts: --http-include=/tmp/a.conf
--- user_files
>>> /tmp/a.conf
lua_shared_dict dogs 1m;
--- src
local dogs = ngx.shared.dogs
dogs:set("Tom", 32)
print(dogs:get("Tom"))
--- out
32
--- err



=== TEST 8: multiple --http-include options
--- opts: --http-include=/tmp/a.conf --http-include=/tmp/b.conf
--- user_files
>>> /tmp/a.conf
lua_shared_dict dogs 1m;
>>> /tmp/b.conf
lua_shared_dict cats 1m;
--- src
local dogs = ngx.shared.dogs
local cats = ngx.shared.cats
dogs:set("Tom", 32)
cats:set("Tom", 12)
print("dog: ", dogs:get("Tom"))
print("cat: ", cats:get("Tom"))
--- out
dog: 32
cat: 12
--- err



=== TEST 9: multiple --main-include options
--- opts: --main-include=/tmp/a.conf --main-include=/tmp/b.conf
--- user_files
>>> /tmp/a.conf
env foo=32;
>>> /tmp/b.conf
env bar=56;
--- src
print("foo: ", os.getenv("foo"))
print("bar: ", os.getenv("bar"))
--- out
foo: 32
bar: 56
--- err



=== TEST 10: good --http-include file content (relative path)
--- opts: --http-include=t/tmp/a.conf
--- user_files
>>> a.conf
lua_shared_dict dogs 1m;
--- src
local dogs = ngx.shared.dogs
dogs:set("Tom", 32)
print(dogs:get("Tom"))
--- out
32
--- err



=== TEST 11: --http-include + -e
--- opts: --http-include=t/tmp/a.conf -e 'local dogs = ngx.shared.dogs dogs:set("Tom", 32) print(dogs:get("Tom"))'
--- user_files
>>> a.conf
lua_shared_dict dogs 1m;
--- out
32
--- err



=== TEST 12: good --main-include option value (relative path)
--- opts: --main-include=/tmp/a.conf --main-include=/tmp/b.conf
--- user_files
>>> /tmp/a.conf
env foo=32;
>>> /tmp/b.conf
env bar=56;
--- src
print("foo: ", os.getenv("foo"))
print("bar: ", os.getenv("bar"))
--- out
foo: 32
bar: 56
--- err



=== TEST 13: --shdict option
--- opts: '--shdict=dogs 12k'
--- src
local dogs = ngx.shared.dogs
dogs:set("Tom", 32)
print(dogs:get("Tom"))
--- out
32
--- err



=== TEST 14: multiple --shdict option
--- opts: '--shdict=dogs 1m' '--shdict=cats 1m'
--- src
local dogs = ngx.shared.dogs
dogs:set("Tom", 32)
print(dogs:get("Tom"))

local cats = ngx.shared.cats
dogs:set("Max", 64)
print(dogs:get("Max"))
--- out
32
64
--- err



=== TEST 15: --shdict option missing size
--- opts: '--shdict=dogs'
--- out
--- err
Invalid value for --shdict option. Expected: NAME SIZE
--- ret: 255



=== TEST 16: --shdict option case-insensitive size (1/2)
--- opts: '--shdict=dogs 1m'
--- src
local dogs = ngx.shared.dogs
dogs:set("Tom", 32)
print(dogs:get("Tom"))
--- out
32
--- err



=== TEST 17: --shdict option case-insensitive size (2/2)
--- opts: '--shdict=dogs 1M'
--- src
local dogs = ngx.shared.dogs
dogs:set("Tom", 32)
print(dogs:get("Tom"))
--- out
32
--- err



=== TEST 18: --shdict option permissive format
--- opts: '--shdict=cats_dogs   20000'
--- src
local dict = ngx.shared.cats_dogs
dict:set("Tom", 32)
print(dict:get("Tom"))
--- out
32
--- err



=== TEST 19: multiple -e options
--- opts: -e 'print(1)' -e 'print(2)'
--- out
1
2
--- err



=== TEST 20: multiple -e options with file
--- opts: -e 'print(1)' -e 'print(2)'
--- src
print(3)
--- out
1
2
3
--- err



=== TEST 21: multiple -e options with single quotes
--- opts: -e "print('1')" -e 'print(2)'
--- out
1
2
--- err



=== TEST 22: resolver has ipv6=off by default
--- src
local conf = ngx.config.prefix() .. "conf/nginx.conf"
local file = assert(io.open(conf, "r"))
print(file:read "*a")
file:close()
--- out_like
resolver [\s\S]* ipv6=off;
--- err



=== TEST 23: --resolve-ipv6 flag enables ipv6 resolution
--- opts: --resolve-ipv6
--- src
local conf = ngx.config.prefix() .. "conf/nginx.conf"
local file = assert(io.open(conf, "r"))
print(file:read "*a")
file:close()
--- out_not_like
resolver [\s\S]* ipv6=off;
--- err



=== TEST 24: specified name server overrides system name servers
--- opts: --ns 127.0.0.1
--- src
local conf = ngx.config.prefix() .. "conf/nginx.conf"
local file = assert(io.open(conf, "r"))
print(file:read "*a")
file:close()
--- out_like
resolver 127.0.0.1 ipv6=off;
--- err



=== TEST 25: multiple ns flags can be specified
--- opts: --ns 127.0.0.1 --ns 127.0.0.2
--- src
local conf = ngx.config.prefix() .. "conf/nginx.conf"
local file = assert(io.open(conf, "r"))
print(file:read "*a")
file:close()
--- out_like
resolver 127.0.0.1 127.0.0.2 ipv6=off;
--- err



=== TEST 26: ns flags can be specified in both ipv4 and ipv6 formats
--- opts: --ns 127.0.0.1 --ns 127.0.0.2 --ns [::1] --ns [2003:dead:beef:4dad:23:46:bb:101]
--- src
local conf = ngx.config.prefix() .. "conf/nginx.conf"
local file = assert(io.open(conf, "r"))
print(file:read "*a")
file:close()
print(str)
--- out_like
resolver 127.0.0.1 127.0.0.2 \[::1\] \[2003:dead:beef:4dad:23:46:bb:101\] ipv6=off;
--- err



=== TEST 27: ns flag works with resolve ipv6 flag
--- opts: --ns 127.0.0.1 --resolve-ipv6
--- src
local conf = ngx.config.prefix() .. "conf/nginx.conf"
local file = assert(io.open(conf, "r"))
print(file:read "*a")
file:close()
print(str)
--- out_like
resolver 127.0.0.1;
--- err



=== TEST 28: returns error message on invalid name server ip
--- opts: --ns invalid
--- src
--- out
--- err
Invalid value for --ns option. Expected: IP
--- ret: 255



=== TEST 29: --http-conf
--- opts: --http-conf 'lua_shared_dict dogs 1m;'
--- src
ngx.say(ngx.shared.dogs and "yes" or "no")
--- out
yes
--- err



=== TEST 30: --valgrind & --gdb
--- opts: --valgrind --gdb
--- src
print("hi")
--- out
--- err
ERROR: options --gdb and --valgrind cannot be specified at the same time.
--- ret: 25



=== TEST 31: --gdb & --rr
--- opts: --gdb --rr
--- src
print("hi")
--- out
--- err
ERROR: options --gdb and --rr cannot be specified at the same time.
--- ret: 25



=== TEST 32: --rr & --valgrind
--- opts: --rr --valgrind
--- src
print("hi")
--- out
--- err
ERROR: options --rr and --valgrind cannot be specified at the same time.
--- ret: 25



=== TEST 33: --errrlog-level debug
--- opts: --errlog-level debug
--- src
ngx.log(ngx.DEBUG, 'debug message')
--- out
--- err_like
1: debug message
