CC=gcc
CFLAGS=-shared -static-libgcc -Wl,--version-script=version.map,-Bstatic

SHAREDLIB=libfake.so
SRCS=fakelib.c
DESTDIR=/var/tmp/flag15/tls/i686/sse2/cmov/
DESTNAME=libc.so.6

all: $(SHAREDLIB)


$(SHAREDLIB): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(SHAREDLIB)

install: all
	mkdir -p $(DESTDIR)
	cp $(SHAREDLIB) $(DESTDIR)/$(DESTNAME)

.PHONY: clean all install

clean:
	rm -f *.o *.so