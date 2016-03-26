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
    -c num              Set maximal connection count (default: 64).
    -e prog             Run the inlined Lua code in "prog".
    --help              Print this help.

    --http-include path Include the specified file in the nginx http configuration block
                        (multiple instances are supported).

    -I dir              Add dir to the search paths for Lua libraries.

    --main-include path Include the specified file in the nginx main configuration block
                        (multiple instances are supported).

    --nginx             Specify the nginx path (this option might be removed in the future).
    -V                  Print version numbers and nginx configurations.
    --valgrind          Use valgrind to run nginx
    --valgrind-opts     Pass extra options to valgrind

For bug reporting instructions, please see:
<http://openresty.org/#Community>
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



=== TEST 11: good --main-include option value (relative path)
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
