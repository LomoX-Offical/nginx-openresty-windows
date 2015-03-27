# vi:filetype=

use Test::Nginx::Socket;

repeat_each(3);

plan tests => repeat_each() * 2 * blocks();

no_long_string();

run_tests();

#no_diff();

__DATA__

=== TEST 1: base32 (5 bytes)
--- config
    location /bar {
        set $a 'abcde';
        set_encode_base32 $a;
        set $b $a;
        set_decode_base32 $b;

        echo $a;
        echo $b;
    }
--- request
    GET /bar
--- response_body
c5h66p35
abcde



=== TEST 2: base32 (1 byte)
--- config
    location /bar {
        set $a '!';
        set_encode_base32 $a;
        set $b $a;
        set_decode_base32 $b;

        echo $a;
        echo $b;
    }
--- request
    GET /bar
--- response_body
44======
!



=== TEST 3: base32 (1 byte) - not in-place editing
--- config
    location /bar {
        set $a '!';
        set_encode_base32 $a $a;
        set_decode_base32 $b $a;

        echo $a;
        echo $b;
    }
--- request
    GET /bar
--- response_body
44======
!



=== TEST 4: base32 (hello world)
--- config
    location /bar {
        set $a '"hello, world!\nhiya"';
        set_encode_base32 $a;
        set $b $a;
        set_decode_base32 $b;

        echo $a;
        echo $b;
    }
--- request
    GET /bar
--- response_body
49k6ar3cdsm20trfe9m6888ad1knio92
"hello, world!
hiya"



=== TEST 5: base32 (0 bytes left)
--- config
    set_misc_base32_padding on;
    location /bar {
        set $a '"hello, world!"';
        set_encode_base32 $a;

        echo $a;
    }
--- request
    GET /bar
--- response_body
49k6ar3cdsm20trfe9m68892



=== TEST 6: base32 (6 bytes padded)
--- config
    set_misc_base32_padding on;
    location /bar {
        set $a '"hello, world!"a';
        set_encode_base32 $a;

        echo $a;
    }
--- request
    GET /bar
--- response_body
49k6ar3cdsm20trfe9m68892c4======



=== TEST 7: base32 (4 bytes left)
--- config
    set_misc_base32_padding on;
    location /bar {
        set $a '"hello, world!"ab';
        set_encode_base32 $a;

        echo $a;
    }
--- request
    GET /bar
--- response_body
49k6ar3cdsm20trfe9m68892c5h0====



=== TEST 8: base32 (3 bytes left)
--- config
    set_misc_base32_padding on;
    location /bar {
        set $a '"hello, world!"abc';
        set_encode_base32 $a;

        echo $a;
    }
--- request
    GET /bar
--- response_body
49k6ar3cdsm20trfe9m68892c5h66===



=== TEST 9: base32 (1 bytes left)
--- config
    set_misc_base32_padding on;
    location /bar {
        set $a '"hello, world!"abcd';
        set_encode_base32 $a;

        echo $a;
    }
--- request
    GET /bar
--- response_body
49k6ar3cdsm20trfe9m68892c5h66p0=

