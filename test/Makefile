RR=..

include ../src/deps.mk
CFLAGS+=$(shell pkg-config --cflags r_cons)
LDFLAGS+=-rpath ../src

all:
	$(CC) $(CFLAGS) $(LDFLAGS) test*.c -o test
	./test
