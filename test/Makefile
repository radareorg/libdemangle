RR=..

include ../src/deps.mk
LDFLAGS+=$(LDMG_LDFLAGS)

all:
	$(CC) $(CFLAGS) $(LDFLAGS) test*.c -o test
	./test
