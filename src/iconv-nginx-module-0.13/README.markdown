<!---
Don't edit this file manually! Instead you should generate it by using:
    wiki2markdown.pl doc/manpage.wiki
-->

Name
====

iconv-nginx-module

Table of Contents
=================

* [Name](#name)
* [Description](#description)
* [Usage](#usage)
    * [set_iconv](#set_iconv)
    * [iconv_buffer_size](#iconv_buffer_size)
    * [iconv_filter](#iconv_filter)
* [Compatibility](#compatibility)
* [Installation](#installation)
* [Copyright & License](#copyright--license)
* [Changelog](#changelog)
* [See Also](#see-also)

Description
===========

This is a nginx module that uses libiconv to convert characters of different
encoding. It brings the 'set_iconv' command to nginx.

This module depends on the ngx_devel_kit(NDK) module.

Usage
=====

set_iconv
---------

**syntax:** *set_iconv &lt;destination_variable&gt; &lt;from_variable&gt; from=&lt;from_encoding&gt; to=&lt;to_encoding&gt;*

**default:** *none*

**phase:** *rewrite*

[Back to TOC](#table-of-contents)

iconv_buffer_size
-----------------

**syntax:** *iconv_buffer_size &lt;size&gt;*

**default:** *iconv_buffer_size &lt;pagesize&gt;*

[Back to TOC](#table-of-contents)

iconv_filter
------------

**syntax:** *iconv_filter from=&lt;from_encoding&gt; to=&lt;to_encoding&gt;*

**default:** *none*

**phase:** *output-filter*

Here is a basic example:

```nginx

 #nginx.conf

 location /foo {
     set $src '你好'; #in UTF-8
     set_iconv $dst $src from=utf8 to=gbk; #now $dst holds 你好 in GBK
 }

 #everything generated from /foo will be converted from utf8 to gbk
 location /bar {
     iconv_filter from=utf-8 to=gbk;
     iconv_buffer_size 1k;
     #content handler here
 }
```

[Back to TOC](#table-of-contents)

Compatibility
=============

The following versions of Nginx should work with this module:

* 1.9.x (last tested: 1.9.3)
* 1.8.x
* 1.7.x
* 1.6.x
* 1.5.x
* 1.4.x
* 1.3.x
* 1.2.x (last tested: 1.2.7)
* 1.1.x (last tested: 1.1.5)
* 1.0.x (last tested: 1.0.8)
* 0.9.x (last tested: 0.9.4)
* 0.8.x (last tested: 0.8.54)
* 0.7.x (last tested: 0.7.68)

[Back to TOC](#table-of-contents)

Installation
============

Get the nginx source code from nginx.org (http://nginx.org/).
Untar the source code and build nginx with this module.

```bash

 wget 'http://sysoev.ru/nginx/nginx-1.9.3.tar.gz'
 tar -xzvf nginx-1.9.3.tar.gz
 cd nginx-1.9.3/

 git-clone http://github.com/simpl-it/ngx_devel_kit.git
 git-clone http://github.com/calio/form-input-module.git

 ./configure --add-module=/path/to/iconv-nginx-module/ --add-module=/path/to/ngx_devel_kit
 make -j2
 make install
```

[Back to TOC](#table-of-contents)

Copyright & License
===================

This program is licenced under the BSD license.

Copyright (c) 2010, Calio <vipcalio@gmail.com>.

Copyright (c) 2010-2015, Yichun Zhang <agentzh@gmail.com>.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of the Taobao Inc. nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

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

Changelog
=========

This module's change logs are part of the OpenResty bundle's change logs. Please see
See <http://openresty.org/#Changes>

[Back to TOC](#table-of-contents)

See Also
========

* The [OpenResty](https://openresty.org) bundle.
