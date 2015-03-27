#vi:filetype=perl

use lib 'lib';
use Test::Nginx::Socket;

#repeat_each(3);

plan tests => repeat_each(2) * 2 * blocks();

no_long_string();

run_tests();

#no_diff();

__DATA__

=== TEST 1: set escape uri
--- config
	location /foo {
		set $foo "hello world";
		set_escape_uri $foo $foo;
		echo $foo;
	}
--- request
GET /foo
--- response_body
hello%20world



=== TEST 2: set escape uri(in-place)
--- config
	location /foo {
		set $foo "hello world";
		set_escape_uri $foo;
		echo $foo;
	}
--- request
GET /foo
--- response_body
hello%20world



=== TEST 3: blank string
--- config
	location /foo {
		set $foo "";
		set_escape_uri $foo;
		echo $foo;
	}
--- request
GET /foo
--- response_body eval
"\n"



=== TEST 4: blank string(in place)
--- config
	location /foo {
		set $foo "";
		set_escape_uri $foo;
		echo $foo;
	}
--- request
GET /foo
--- response_body eval
"\n"



=== TEST 5: eacape chinese character
--- config
    location /foo {
        set $foo "你好";
        set_escape_uri $foo;
        echo $foo;
    }
--- request
GET /foo
--- response_body
%e4%bd%a0%e5%a5%bd



=== TEST 6: escape long string
--- config
    location /foo {
        set $foo "法规及饿哦物权法家哦低价非结果哦我二期界  附件饿哦武器  积分饿哦为契机佛i 该软件哦气氛  份额叫我起 国无二君哦气氛为界非ieowq结果哦而完全附件  份额叫我iqfjeowiqgjeriowqfjpdjfosadijfoiasdjf 附件饿哦武器界 份额叫我起界份额叫我起哦ifjefejwioq附件饿哦武器界非风格及去哦根据份额叫我起哦界份额为契机哦乳房阿基完全哦igqtewqo个人就去哦ieorjwrewqoi日哦额外起今天诶哦我亲热为特务前日哦我而哥特完全哦iijrtewmkdf 服务鄂潜江哦irewq";
        set_escape_uri $foo;
        echo $foo;
    }
--- request
GET /foo
--- response_body
%e6%b3%95%e8%a7%84%e5%8f%8a%e9%a5%bf%e5%93%a6%e7%89%a9%e6%9d%83%e6%b3%95%e5%ae%b6%e5%93%a6%e4%bd%8e%e4%bb%b7%e9%9d%9e%e7%bb%93%e6%9e%9c%e5%93%a6%e6%88%91%e4%ba%8c%e6%9c%9f%e7%95%8c%20%20%e9%99%84%e4%bb%b6%e9%a5%bf%e5%93%a6%e6%ad%a6%e5%99%a8%20%20%e7%a7%af%e5%88%86%e9%a5%bf%e5%93%a6%e4%b8%ba%e5%a5%91%e6%9c%ba%e4%bd%9bi%20%e8%af%a5%e8%bd%af%e4%bb%b6%e5%93%a6%e6%b0%94%e6%b0%9b%20%20%e4%bb%bd%e9%a2%9d%e5%8f%ab%e6%88%91%e8%b5%b7%20%e5%9b%bd%e6%97%a0%e4%ba%8c%e5%90%9b%e5%93%a6%e6%b0%94%e6%b0%9b%e4%b8%ba%e7%95%8c%e9%9d%9eieowq%e7%bb%93%e6%9e%9c%e5%93%a6%e8%80%8c%e5%ae%8c%e5%85%a8%e9%99%84%e4%bb%b6%20%20%e4%bb%bd%e9%a2%9d%e5%8f%ab%e6%88%91iqfjeowiqgjeriowqfjpdjfosadijfoiasdjf%20%e9%99%84%e4%bb%b6%e9%a5%bf%e5%93%a6%e6%ad%a6%e5%99%a8%e7%95%8c%20%e4%bb%bd%e9%a2%9d%e5%8f%ab%e6%88%91%e8%b5%b7%e7%95%8c%e4%bb%bd%e9%a2%9d%e5%8f%ab%e6%88%91%e8%b5%b7%e5%93%a6ifjefejwioq%e9%99%84%e4%bb%b6%e9%a5%bf%e5%93%a6%e6%ad%a6%e5%99%a8%e7%95%8c%e9%9d%9e%e9%a3%8e%e6%a0%bc%e5%8f%8a%e5%8e%bb%e5%93%a6%e6%a0%b9%e6%8d%ae%e4%bb%bd%e9%a2%9d%e5%8f%ab%e6%88%91%e8%b5%b7%e5%93%a6%e7%95%8c%e4%bb%bd%e9%a2%9d%e4%b8%ba%e5%a5%91%e6%9c%ba%e5%93%a6%e4%b9%b3%e6%88%bf%e9%98%bf%e5%9f%ba%e5%ae%8c%e5%85%a8%e5%93%a6igqtewqo%e4%b8%aa%e4%ba%ba%e5%b0%b1%e5%8e%bb%e5%93%a6ieorjwrewqoi%e6%97%a5%e5%93%a6%e9%a2%9d%e5%a4%96%e8%b5%b7%e4%bb%8a%e5%a4%a9%e8%af%b6%e5%93%a6%e6%88%91%e4%ba%b2%e7%83%ad%e4%b8%ba%e7%89%b9%e5%8a%a1%e5%89%8d%e6%97%a5%e5%93%a6%e6%88%91%e8%80%8c%e5%93%a5%e7%89%b9%e5%ae%8c%e5%85%a8%e5%93%a6iijrtewmkdf%20%e6%9c%8d%e5%8a%a1%e9%84%82%e6%bd%9c%e6%b1%9f%e5%93%a6irewq



=== TEST 7: no need to escape
--- config
    location /foo {
        set $foo 'welcometotheworldofnginx';
        set_escape_uri $foo;
        echo $foo;
    }
--- request
GET /foo
--- response_body
welcometotheworldofnginx



=== TEST 8: fixed ngx_escape_uri issues: + and / should also be escaped
--- config
    location /foo {
        set $foo '+/=';
        set_escape_uri $foo;
        echo $foo;
    }
--- request
GET /foo
--- response_body
%2b%2f%3d



=== TEST 9: fixed ngx_escape_uri issues: / {} : & [] and more
--- config
    location /foo {
        set $foo '"a/b={}:<>;&[]\\^';
        set_escape_uri $foo;
        echo $foo;
    }
--- request
GET /foo
--- response_body
%22a%2fb%3d%7b%7d%3a%3c%3e%3b%26%5b%5d%5c%5e

