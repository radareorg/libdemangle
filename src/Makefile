AR_EXT=a
SO_EXT=dylib
RANLIB=ranlib

RR=..
include deps.mk
SRC=
SRC+=api.c
SRC+=cxx.c
SRC+=java.c
#SRC+=main.c
SRC+=msvc.c
SRC+=msvc_demangler.c
SRC+=microsoft_demangle.c
SRC+=objc.c
SRC+=rust.c
SRC+=swift.c
SRC+=cxx/cp-demangle.c
SRC+=cxx/rust-demangle.c

OBJ=$(subst .c,.o,$(SRC))

all: libdemangle.$(SO_EXT) libdemangle.$(AR_EXT)
#	rm libdemangle.$(SO_EXT)
	#$(CC) -g -DHAS_MAIN=0 -I../../include swift-sd.c -L../../util -lr_util
	#./a.out

libdemangle.$(SO_EXT): $(OBJ)
	$(CC) -shared -o libdemangle.$(SO_EXT) $(OBJ) $(LDFLAGS)

libdemangle.$(AR_EXT): $(OBJ)
	ar -r libdemangle.$(AR_EXT) $(OBJ)
	$(RANLIB) libdemangle.$(AR_EXT)
