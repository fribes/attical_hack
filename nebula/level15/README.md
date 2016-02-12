As suggested, running strace on flag15 prog reveals on unusual path in the search to libc.so.6:

```
open("/var/tmp/flag15/tls/i686/sse2/cmov/libc.so.6", O_RDONLY) = -1 ENOENT (No such file or directory)
```

As level15 user has permission to write at this location, the idea is to build a custom library, put it there, so that it will be executed by flag15 program.

Looking at unresoved symbols of flag15 we get:

```
level15@nebula:~$ nm ../flag15/flag15 | grep U
         U __libc_start_main@@GLIBC_2.0
         U puts@@GLIBC_2.0
```

__libc_start_main() looks great has a hook to put our code. It is a standard function. Its prototype can be found [here for example](http://refspecs.linuxbase.org/LSB_3.1.1/LSB-Core-generic/LSB-Core-generic/baselib---libc-start-main-.html)

Let's invoke a shell [see source](fakelib.c)


This library needs to have all its dependencies linked statically, whereas being a shared lib itself, hence the flags in [Makefile].
