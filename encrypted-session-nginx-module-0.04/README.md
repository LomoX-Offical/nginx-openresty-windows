Name
====

encrypted-session-nginx-module - encrypt and decrypt nginx variable values

*This module is not distributed with the Nginx source.* See the
installation instructions.

Table of Contents
=================

* [Name](#name)
* [Status](#status)
* [Synopsis](#synopsis)
* [Description](#description)
* [Directives](#directives)
    * [encrypted_session_key](#encrypted_session_key)
    * [encrypted_session_iv](#encrypted_session_iv)
    * [encrypted_session_expires](#encrypted_session_expires)
    * [set_encrypt_session](#set_encrypt_session)
    * [set_decrypt_session](#set_decrypt_session)
* [Installation](#installation)
* [Compatibility](#compatibility)
* [Report Bugs](#report-bugs)
* [Source Repository](#source-repository)
* [Getting involved](#getting-involved)
* [Author](#author)
* [Copyright & License](#copyright--license)
* [See Also](#see-also)

Status
======

This module is production ready.

Synopsis
========

```nginx
# key must be of 32 bytes long
encrypted_session_key "abcdefghijklmnopqrstuvwxyz123456";

# iv must not be longer than 16 bytes
#   default: "deadbeefdeadbeef" (w/o quotes)
encrypted_session_iv "1234567812345678";

# default: 1d (1 day)
encrypted_session_expires 2; # in sec

location /encrypt {
    set $raw 'text to encrypted'; # from the ngx_rewrite module
    set_encrypt_session $session $raw;
    set_encode_base32 $session; # from the ngx_set_misc module

    add_header Set-Cookie 'my_login=$session';  # from the ngx_headers module

    # your content handler goes here...
}

location /decrypt {
    set_decode_base32 $session $cookie_my_login; # from the ngx_set_misc module
    set_decrypt_session $raw $session;

    if ($raw = '') {
        # bad session
    }

    # your content handler goes here...
}
```

Description
===========

This module provides encryption and decryption support for
nginx variables based on AES-256 with Mac.

This module is usually used with the [ngx_set_misc module](http://github.com/agentzh/set-misc-nginx-module)
and the standard rewrite module's directives.

This module can be used to implement simple user login and ACL.

Usually, you just decrypt data in nginx level, and pass the unencrypted
data to your FastCGI/HTTP backend, as in

```nginx
location /blah {
    set_decrypt_session $raw_text $encrypted;

    # this directive is from the ngx_set_misc module
    set_escape_uri $escaped_raw_text $raw_text;

    fastcgi_param QUERY_STRING "uid=$uid";
    fastcgi_pass unix:/path/to/my/php/or/python/fastcgi.sock;
}
```

Lua web applications running directly on [ngx_lua](https://github.com/openresty/lua-nginx-module) can call
this module's directives directly from within Lua code:

```lua
local raw_text = ndk.set_var.set_decrypt_session(encrypted_text)
```

[Back to TOC](#table-of-contents)

Directives
==========

[Back to TOC](#table-of-contents)

encrypted_session_key
---------------------
**syntax:** *encrypted_session_key &lt;key&gt;*

**default:** *no*

**context:** *http, server, server if, location, location if*

Sets the key for the cipher (must be 32 bytes long). For example,

```nginx
encrypted_session_key "abcdefghijklmnopqrstuvwxyz123456";
```

[Back to TOC](#table-of-contents)

encrypted_session_iv
--------------------
**syntax:** *encrypted_session_iv &lt;iv&gt;*

**default:** *encrypted_session_iv "deadbeefdeadbeef";*

**context:** *http, server, server if, location, location if*

Sets the initial vector used for the cipher (must be *no longer* than 16 bytes).

For example,

```nginx
encrypted_session_iv "12345678";
```

[Back to TOC](#table-of-contents)

encrypted_session_expires
-------------------------
**syntax:** *encrypted_session_expires &lt;time&gt;*

**default:** *encrypted_session_expires 1d;*

**context:** *http, server, server if, location, location if*

Sets expiration time difference (in seconds by default).

For example, consider the following configuration:

```nginx
encypted_session_expires 1d;
```

When your session is being generated, ngx_encrypted_session will plant
an expiration time (1 day in the future in this example) into the
encrypted session string, such that when the session is being decrypted
later, the server can pull the expiration time out of the session and
compare it with the server's current system time. No matter how you
transfer and store your session, like using cookies, or URI query arguments,
or whatever.

People may confuse this setting with the expiration date of HTTP
cookies. This directive simply controls when the session gets expired;
it knows nothing about HTTP cookies. Even if the end user intercepted
this session from cookie by himself and uses it later manually, the
server will still reject it when the expiration time gets passed.

[Back to TOC](#table-of-contents)

set_encrypt_session
-------------------
**syntax:** *set_encrypt_session $target &lt;value&gt;*

**default:** *no*

**context:** *http, server, server if, location, location if*

Encrypts the string value specified by the `value` argument and saves the result into
the variable specified by `$target`.

For example,

```nginx
set_encrypt_session $res $value;
```

will encrypts the value in the variable $value into the target variable `$res`.

The `value` argument can also be an nginx string value, for example,

```nginx
set_encrypt_session $res "my value = $value";
```

The resulting data can later be decrypted via the [set_decrypt_session](#set_decrypt_session) directive.

[Back to TOC](#table-of-contents)

set_decrypt_session
-------------------
**syntax:** *set_decrypt_session $target &lt;value&gt;*

**default:** *no*

**context:** *http, server, server if, location, location if*

Similar to [set_encrypt_session](#set_encrypt_session), but performs the inverse operation, that is,
to decrypt things.

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
     --add-module=/path/to/encrypted-session-nginx-module

 $ make -j2
 $ make install
```

Download the latest version of the release tarball of this module from [encrypted-session-nginx-module file list](https://github.com/openresty/encrypted-session-nginx-module/tags).

Also, this module is included and enabled by default in the [ngx_openresty bundle](http://openresty.org).

OpenSSL should not be disabled in your Nginx build.

[Back to TOC](#table-of-contents)

Compatibility
=============

The following versions of Nginx should work with this module:

* **1.7.x** (last tested: 1.7.10)
* **1.6.x**
* **1.5.x** (last tested: 1.5.12)
* **1.4.x** (last tested: 1.4.4)
* **1.2.x** (last tested: 1.2.9)
* **1.1.x** (last tested: 1.1.5)
* **1.0.x** (last tested: 1.0.11)
* **0.9.x** (last tested: 0.9.4)
* **0.8.x** (last tested: 0.8.54)
* **0.7.x >= 0.7.46** (last tested: 0.7.68)

Earlier versions of Nginx like 0.6.x and 0.5.x will *not* work.

If you find that any particular version of Nginx above 0.7.44 does not
work with this module, please consider reporting a bug.

[Back to TOC](#table-of-contents)

Report Bugs
===========

Although a lot of effort has been put into testing and code tuning,
there must be some serious bugs lurking somewhere in this module. So
whenever you are bitten by any quirks, please don't hesitate to

1.  send a bug report or even patches to <agentzh@gmail.com>,
2.  or create a ticket on the [issue tracking interface](http://github.com/openresty/encrypted-session-nginx-module/issues)
provided by GitHub.

[Back to TOC](#table-of-contents)

Source Repository
=================

Available on github at [openresty/encrypted-session-nginx-module](http://github.com/openresty/encrypted-session-nginx-module).

[Back to TOC](#table-of-contents)

Getting involved
================

You'll be very welcomed to submit patches to the author or just ask for
a commit bit to the source repository on GitHub.

[Back to TOC](#table-of-contents)

Author
======

Yichun "agentzh" Zhang (章亦春) &lt;agentzh@gmail.com&gt;

[Back to TOC](#table-of-contents)

Copyright & License
===================

Copyright (c) 2009-2015, Yichun Zhang (agentzh) &lt;agentzh@gmail.com&gt;, Cloud Flare Inc.

This module is licensed under the terms of the BSD license.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

[Back to TOC](#table-of-contents)

See Also
=========
* [NDK](http://github.com/simpl-it/ngx_devel_kit)
* [ngx_set_misc module](http://github.com/agentzh/set-misc-nginx-module)

[Back to TOC](#table-of-contents)

