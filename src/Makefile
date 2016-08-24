
default:	build

clean:
	rm -rf Makefile objs

build:
	$(MAKE) -f objs/Makefile
	$(MAKE) -f objs/Makefile manpage

install:
	$(MAKE) -f objs/Makefile install

upgrade:
	/usr/local/openresty/nginx/sbin/nginx -t

	kill -USR2 `cat /usr/local/openresty/nginx/logs/nginx.pid`
	sleep 1
	test -f /usr/local/openresty/nginx/logs/nginx.pid.oldbin

	kill -QUIT `cat /usr/local/openresty/nginx/logs/nginx.pid.oldbin`
