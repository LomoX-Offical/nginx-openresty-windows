Name
====

array-var-nginx-module - Add support for array-typed variables to nginx config files

*This module is not distributed with the Nginx source.* See the
installation instructions.

Table of Contents
=================

* [Name](#name)
* [Status](#status)
* [Synopsis](#synopsis)
* [Description](#description)
* [Directives](#directives)
    * [array_split](#array_split)
    * [array_join](#array_join)
    * [array_map](#array_map)
    * [array_map_op](#array_map_op)
* [Installation](#installation)
* [Compatibility](#compatibility)
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
location /foo {
    array_split ',' $arg_files to=$array;

    # use the set_quote_sql_str directive in the ngx_set_misc
    # module to map to each element in the array $array:
    array_map_op set_quote_sql_str $array;

    array_map "name = $array_it" $array;

    array_join ' or ' $array to=$sql_condition;

    # well, we could feed it to ngx_drizzle to talk to MySQL, for example ;)
    echo "select * from files where $sql_condition";
}
```

Description
===========

This module provides array typed nginx variables to `nginx.conf`.

Under the hood, this module just "abuses" the nginx string values to hold binary pointers
to C data structures (NGINX core's `ngx_array_t` struct on the C land).

The array type gives `nginx.onf` wonderful capabilities of handling value lists. Nowadays, however,
you are highly recommended to use the [ngx_lua](https://github.com/openresty/lua-nginx-module) module
so as to have the full scripting power provided by the Lua language in nginx.

[Back to TOC](#table-of-contents)

Directives
==========

[Back to TOC](#table-of-contents)

array_split
-----------
**syntax:** *array_split &lt;separator&gt; &lt;subject&gt; to=$target_variable*

**default:** *no*

**context:** *http, server, server if, location, location if*

Splits the string value in the `subject` argument with the separator string specified by the
`separator` argument. The result is an array-typed value saved to the nginx variable specified by the `to=VAR` option.

For example,

```nginx
array_split "," $arg_names to=$names;
```

will split the string values in the URI query argument `names` into an array-typed value saved to the custom nginx variable
`$names`.

This directive creates an array-typed variable. Array-typed variables cannot be used outside
the directives offered by this module. If you want to use the values in an array-typed variable
in other contexts,
you must use the [array_join](#array_join) directive to produce a normal string value.

[Back to TOC](#table-of-contents)

array_join
----------
**syntax:** *array_split &lt;separator&gt; $array_var*

**default:** *no*

**context:** *http, server, server if, location, location if*

Joins the elements in the array-typed nginx variable (`$array_var`) into a single string value
with the separator specified by the first argument.

For example,

```nginx
location /foo {
    array_split ',' $arg_names to=$names;
    array_join '+' $names;
    echo $names;
}
```

Then request `GET /foo?names=Bob,Marry,John` will yield the response body

```
Bob+Marry+John
```

In the example above, we use the [ngx_echo](https://github.com/openresty/echo-nginx-module) module's [echo](https://github.com/openresty/echo-nginx-module#echo) directive to output
the final result.

[Back to TOC](#table-of-contents)

array_map
---------
**syntax:** *array_map &lt;template&gt; $array_var*

**syntax:** *array_map &lt;template&gt; $array_var to=$new_array_var*

**default:** *no*

**context:** *http, server, server if, location, location if*

Maps the string template to each element in the array-typed nginx variable specified. Within
the string template, you can use the special iterator variable `$array_it` to reference the current
array element in the array being mapped.

For example,

```nginx
array_map "[$array_it]" $names;
```

will change each element in the array variable `$names` by putting the square brackets around
each element's string value. The modification is in-place in this case.

If you do not want in-place modifications, you can use the `to=$var` option to specify a new nginx variable to hold the results. For instance,

```nginx
array_map "[$array_it]" $names to=$new_names;
```

where the results are saved into another (array-typed) nginx variable named `$new_names` while
the `$names` variable keeps intact.

Below is a complete example for this:

```nginx
location /foo {
    array_split ',' $arg_names to=$names;
    array_map '[$array_it]' $names;
    array_join '+' $names;
    echo "$names";
}
```

Then request `GET /foo?names=bob,marry,nomas` will yield the response body

```
[bob]+[marry]+[nomas]
```

[Back to TOC](#table-of-contents)

array_map_op
------------
**syntax:** *array_map_op &lt;directive&gt; $array_var*

**syntax:** *array_map_op &lt;directive&gt; $array_var to=$new_array_var*

**default:** *no*

**context:** *http, server, server if, location, location if*

Similar to the [array_map](#array_map) directive but maps the specified nginx configuration directive instead of
a string template to each element in the array-typed nginx variable specified. The result
of applying the specified configuration directive becomes the result of the mapping.

The nginx configuration directive being used as the iterator must be implemented by [Nginx Devel Kit](https://github.com/simpl/ngx_devel_kit) (NDK)'s set_var submodule's `ndk_set_var_value`.
For example, the following [set-misc-nginx-module](http://github.com/openresty/set-misc-nginx-module) directives can be invoked this way:

* [set_quote_sql_str](http://github.com/openresty/set-misc-nginx-module#set_quote_sql_str)
* [set_quote_pgsql_str](http://github.com/openresty/set-misc-nginx-module#set_quote_pgsql_str)
* [set_quote_json_str](http://github.com/openresty/set-misc-nginx-module#set_quote_json_str)
* [set_unescape_uri](http://github.com/openresty/set-misc-nginx-module#set_unescape_uri)
* [set_escape_uri](http://github.com/openresty/set-misc-nginx-module#set_escape_uri)
* [set_encode_base32](http://github.com/openresty/set-misc-nginx-module#set_encode_base32)
* [set_decode_base32](http://github.com/openresty/set-misc-nginx-module#set_decode_base32)
* [set_encode_base64](http://github.com/openresty/set-misc-nginx-module#set_encode_base64)
* [set_decode_base64](http://github.com/openresty/set-misc-nginx-module#set_decode_base64)
* [set_encode_hex](http://github.com/openresty/set-misc-nginx-module#set_encode_base64)
* [set_decode_hex](http://github.com/openresty/set-misc-nginx-module#set_decode_base64)
* [set_sha1](http://github.com/openresty/set-misc-nginx-module#set_encode_base64)
* [set_md5](http://github.com/openresty/set-misc-nginx-module#set_decode_base64)

This is a higher-order operation where other nginx configuration directives can be used
as arguments for this `map_array_op` directive.

Consider the following example,

```nginx
array_map_op set_quote_sql_str $names;
```

This line changes each element in the array-typed nginx variable `$names` by applying the
[set_quote_sql_str](https://github.com/openresty/set-misc-nginx-module#set_quote_sql_str)
directive provided by the [ngx_set_misc](https://github.com/openresty/set-misc-nginx-module)
module one by one. The result is that each element in the array `$names` has been escaped as SQL string literal values.

You can also specify the `to=$var` option if you do not want in-place modifications of the input arrays. For instance,

```nginx
array_map_op set_quote_sql_str $names to=$quoted_names;
```

will save the escaped elements into a new (array-typed) nginx variable named `$quoted_names` with `$names` intact.

The following is a relatively complete example:

```nginx
location /foo {
    array_split ',' $arg_names to=$names;
    array_map_op set_quote_sql_str $names;
    array_join '+' $names to=$res;
    echo $res;
}
```

Then request `GET /foo?names=bob,marry,nomas` will yield the response body

```
'bob'+'marry'+'nomas'
```

Pretty cool, huh?

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
     --add-module=/path/to/array-var-nginx-module

 $ make -j2
 $ make install
```

Download the latest version of the release tarball of this module from [array-var-nginx-module file list](https://github.com/openresty/array-var-nginx-module/tags).

Also, this module is included and enabled by default in the [ngx_openresty bundle](http://openresty.org).

[Back to TOC](#table-of-contents)

Compatibility
==============

The following versions of Nginx should work with this module:

* **1.7.x** (last tested: 1.7.10)
* **1.6.x**
* **1.5.x** (last tested: 1.5.12)
* **1.4.x** (last tested: 1.4.2)
* **1.2.x** (last tested: 1.2.9)
* **1.1.x** (last tested: 1.1.5)
* **1.0.x** (last tested: 1.0.8)
* **0.9.x** (last tested: 0.9.4)
* **0.8.x** (last tested: 0.8.54)
* **0.7.x >= 0.7.44** (last tested: 0.7.68)

Earlier versions of Nginx like 0.6.x and 0.5.x will *not* work.

If you find that any particular version of Nginx above 0.7.44 does not
work with this module, please consider reporting a bug.

[Back to TOC](#table-of-contents)

Source Repository
=================

Available on github at [openresty/array-var-nginx-module](https://github.com/openresty/array-var-nginx-module).

[Back to TOC](#table-of-contents)

Getting involved
================

You'll be very welcomed to submit patches to the author or just ask for
a commit bit to the source repository on GitHub.

[Back to TOC](#table-of-contents)

Author
======

Yichun "agentzh" Zhang (章亦春) &lt;agentzh@gmail.com&gt;, CloudFlare Inc.

[Back to TOC](#table-of-contents)

Copyright & License
===================

Copyright (c) 2009-2015, Yichun Zhang (agentzh) &lt;agentzh@gmail.com&gt;, CloudFlare Inc.

This module is licensed under the terms of the BSD license.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

*   Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
*   Redistributions in binary form must reproduce the above copyright
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
========

* [NDK](https://github.com/simpl/ngx_devel_kit)
* [ngx_lua](https://github.com/openresty/lua-nginx-module)
* [ngx_set_misc](https://github.com/openresty/set-misc-nginx-module)

[Back to TOC](#table-of-contents)

