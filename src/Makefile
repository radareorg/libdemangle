SO_EXT=dylib

RR=..
include deps.mk
SRC=
SRC+=api.c
SRC+=cxx.c
SRC+=demangler.c
SRC+=java.c
#SRC+=main.c
SRC+=microsoft_demangle.c
SRC+=msvc.c
SRC+=objc.c
SRC+=rust.c
SRC+=swift.c
SRC+=cxx/cp-demangle.c
SRC+=cxx/rust-demangle.c

OBJ=$(subst .c,.o,$(SRC))

all: libdemangle.$(SO_EXT)
#	rm libdemangle.$(SO_EXT)
	#$(CC) -g -DHAS_MAIN=0 -I../../include swift-sd.c -L../../util -lr_util
	#./a.out

libdemangle.$(SO_EXT): $(OBJ)
	$(CC) -shared -o libdemangle.$(SO_EXT) $(OBJ) $(LDFLAGS)
