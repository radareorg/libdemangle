LDMG
====

Formerly /lib-de-man-gle/

Author
------

--pancake 2018-2020


Description
-----------

This library provides a simple interface to demangle symbols from
different programming languages.

The library is written in C for portability and simplicity, but
aims to be usable from other languages, mainly WebAssembly and
Javascript.

This code comes from radare2, but it's been extracted on purpose
in order to provide a safe place with proper testsuite and tracking
to make it easy and safe to use by other projects, like Frida.

Licensing
---------

The c++ demangler is GPL because it comes from binutils.

Use the --without-gpl configure flag to build without it.

The other demanglers (java/dalvik, msvc, swift, objc, ..) are LGPL,
but we may want to switch to MIT/BSD to avoid legal issues when
statically linking this library.
