
default:	build

clean:
	rm -rf Makefile objs

build:
	$(MAKE) -f objs/Makefile
	$(MAKE) -f objs/Makefile manpage

install:
	$(MAKE) -f objs/Makefile install

upgrade:
	/nginx.exe -t

	kill -USR2 `cat /logs/nginx.pid`
	sleep 1
	test -f /logs/nginx.pid.oldbin

	kill -QUIT `cat /logs/nginx.pid.oldbin`
