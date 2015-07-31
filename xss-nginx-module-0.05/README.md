Name
====

xss-nginx-module - Native cross-site scripting support in nginx

Table of Contents
=================

* [Name](#name)
* [Synopsis](#synopsis)
* [Description](#description)
* [Directives](#directives)
    * [xss_get](#xss_get)
    * [xss_callback_arg](#xss_callback_arg)
    * [xss_override_status](#xss_override_status)
    * [xss_check_status](#xss_check_status)
    * [xss_input_types](#xss_input_types)
* [Limitations](#limitations)
* [Trouble Shooting](#trouble-shooting)
* [Installation](#installation)
* [Compatibility](#compatibility)
* [TODO](#todo)
* [Author](#author)
* [Copyright & License](#copyright--license)
* [See Also](#see-also)

Synopsis
========

```nginx
# accessing /foo?callback=process gives the response
# body "process(...);" (without quotes) where "..."
# is the original response body of the /foo location.
server {
    location /foo {
        # your content handler goes here...

        xss_get on;
        xss_callback_arg 'callback';
        xss_input_types 'application/json'; # default
        xss_output_type 'application/x-javascript'; # default
    }
    ...
}
```

Description
===========

This module adds cross-site AJAX support to nginx. Currently only
cross-site GET is supported. But cross-site POST will be added
in the future.

The cross-site GET is currently implemented as JSONP
(or "JSON with padding"). See http://en.wikipedia.org/wiki/JSON#JSONP
for more details.

Directives
==========

[Back to TOC](#table-of-contents)

xss_get
-------
**syntax:** *xss_get on | off*

**default:** *xss_get off*

**context:** *http, server, location, if location*

Enables JSONP support for GET requests.

[Back to TOC](#table-of-contents)

xss_callback_arg
----------------
**syntax:** *xss_callback_arg &lt;name&gt;*

**default:** *none*

**context:** *http, http, location, if location*

Specifies the JavaScript callback function name
used in the responses.

For example,

```nginx
location /foo {
    xss_get on;
    xss_callback_arg c;
    ...
}
```

then

```
GET /foo?c=blah
```

returns

```javascript
blah(...);
```

[Back to TOC](#table-of-contents)

xss_override_status
-------------------
**syntax:** *xss_override_status on | off*

**default:** *xss_check_status on*

**context:** *http, server, location, if location*

Specifies whether to override 30x, 40x and 50x status to 200
when the response is actually being processed.

[Back to TOC](#table-of-contents)

xss_check_status
-----------------
**syntax:** *xss_check_status on | off*

**default:** *xss_check_status on*

**context:** *http, server, location, if location*

By default, ngx_xss only process responses with the status code
200 or 201.

[Back to TOC](#table-of-contents)

xss_input_types
---------------
**syntax:** *xss_input_types [mime-type]...*

**default:** *xss_input_types application/json*

**context:** *http, server, location, if location*

Only processes the responses of the specified MIME types.

Example:

```nginx
xss_input_types application/json text/plain;
```

[Back to TOC](#table-of-contents)

Limitations
===========

* ngx_xss will not work with [ngx_echo](https://github.com/openresty/echo-nginx-module)'s
subrequest interfaces, due to the underlying
limitations imposed by subrequests' "postponed chain" mechanism in the nginx core.
The standard ngx_addition module also falls into this category.  You're recommended,
however, to use [ngx_lua](https://github.com/openresty/lua-nginx-module) as the content
handler to issue subrequests *and* ngx_xss
to do JSONP, because [ngx_lua](https://github.com/openresty/lua-nginx-module)'s
[ngx.location.capture()](https://github.com/openresty/lua-nginx-module#ngxlocationcapture)
interface does not utilize the "postponed chain" mechanism, thus getting out of this
limitation. We're taking this approach in production and it works great.

[Back to TOC](#table-of-contents)

Trouble Shooting
================

Use the "info" error log level (or lower) to get more
diagnostics when things go wrong.

[Back to TOC](#table-of-contents)

Installation
============

You're recommended to install this module (as well as the Nginx core and many other goodies) via the [ngx_openresty bundle](http://openresty.org). See [the detailed instructions](http://openresty.org/#Installation) for downloading and installing ngx_openresty into your system. This is the easiest and most safe way to set things up.

Alternatively, you can install this module manually with the Nginx source:

Grab the nginx source code from [nginx.org](http://nginx.org/), for example,
the version 1.7.10 (see [nginx compatibility](#compatibility)), and then build the source with this module:

```bash

 $ wget 'http://nginx.org/download/nginx-1.7.10.tar.gz'
 $ tar -xzvf nginx-1.7.10.tar.gz
 $ cd nginx-1.7.10/

 # Here we assume you would install you nginx under /opt/nginx/.
 $ ./configure --prefix=/opt/nginx \
     --add-module=/path/to/rds-json-nginx-module

 $ make -j2
 $ make install
```

Download the latest version of the release tarball of this module from [xss-nginx-module file list](https://github.com/openresty/xss-nginx-module/tags).

Also, this module is included and enabled by default in the [ngx_openresty bundle](http://openresty.org).

[Back to TOC](#table-of-contents)

Compatibility
=============

The following versions of Nginx should work with this module:

* **1.7.x** (last tested: 1.7.10)
* **1.6.x**
* **1.5.x**
* **1.4.x** (last tested: 1.4.3)
* **1.2.x** (last tested: 1.2.9)
* **1.0.x** (last tested: 1.0.10)
* **0.9.x** (last tested: 0.9.4)
* **0.8.x** (last tested: 0.8.54)
* **0.7.x** >= 0.7.30 (last tested: 0.7.67)

Earlier versions of Nginx like 0.6.x and 0.5.x will *not* work.

If you find that any particular version of Nginx above 0.7.30 does not
work with this module, please consider reporting a bug.

[Back to TOC](#table-of-contents)

TODO
====

* add cross-site POST support.

[Back to TOC](#table-of-contents)

Author
======

Yichun "agentzh" Zhang (章亦春) &lt;agentzh@gmail@com&gt;

[Back to TOC](#table-of-contents)

Copyright & License
===================

The implementation of the builtin connection pool has borrowed
a lot of code from Maxim Dounin's upstream_keepalive module.
This part of code is copyrighted by Maxim Dounin.

This module is licenced under the BSD license.

Copyright (C) 2009-2015 by Yichun "agentzh" Zhang (章亦春) &lt;agentzh@gmail.com&gt;.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

[Back to TOC](#table-of-contents)

See Also
========

* [Introduction to JSONP](http://en.wikipedia.org/wiki/JSONP)
* [ngx_lua](https://github.com/openresty/lua-nginx-module)

[Back to TOC](#table-of-contents)

