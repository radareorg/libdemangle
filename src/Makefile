AR_EXT=a
SO_EXT=dylib
RANLIB=ranlib

LIBNAME=libldmg

RR=..
include deps.mk
SRC=
SRC+=ldmg.c
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
SRC+=cxx/d-demangle.c

OBJ=$(subst .c,.o,$(SRC))

all: libldmg.$(SO_EXT) libldmg.$(AR_EXT) ldmg

ldmg: $(OBJ) main.o
	$(CC) -o ldmg $(CFLAGS) $(LDFLAGS) main.o libldmg.$(AR_EXT)

libldmg.$(SO_EXT): $(OBJ)
	$(CC) -shared -o libldmg.$(SO_EXT) $(OBJ) $(LDFLAGS)

libldmg.$(AR_EXT): $(OBJ)
	ar -r libldmg.$(AR_EXT) $(OBJ)
	$(RANLIB) libldmg.$(AR_EXT)
