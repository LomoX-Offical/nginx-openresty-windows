# vi:ft= et ts=4 sw=4

use lib 't/lib';
use Test::Resty;

plan tests => blocks() * 2 + 1;

run_tests();

__DATA__

=== TEST 1: provides stacktrace on user errors
--- src
local function f()
    error("something went wrong")
end

local function g()
    f()
end

g()
--- err_like chomp
^.*?\.lua:\d+: something went wrong
stack traceback:
.*?\.lua:2: in function 'f'
.*?\.lua:6: in function 'g'
.*?\.lua:\d+: in function 'file_gen'
.*?init_worker_by_lua:\d+: in function <init_worker_by_lua:\d+>
.*?\[C\]: in function 'xpcall'
.*?init_worker_by_lua:\d+: in function <init_worker_by_lua:\d+>$
--- ret: 1



=== TEST 2: ignores number return values from the user main chunk
--- src
return 123, 456
--- err
--- ret: 0



=== TEST 3: ignores string return values from the user main chunk
--- src
return "hello world"
--- err
--- ret: 0



=== TEST 4: bad file name
--- opts: 'print("hello")'
--- err
Lua input file print("hello") not found.
--- ret: 2



=== TEST 5: threads
--- src
local function f ()
    ngx.sleep(0.1)
    ngx.say("hello")
    ngx.sleep(0.1)
    ngx.say("world")
end
assert(ngx.thread.spawn(f))
--- out
hello
world
--- err
--- ret: 0
