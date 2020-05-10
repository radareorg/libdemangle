CFLAGS+=-I$(RR)/src
LDMG_LDFLAGS+=$(RR)/src/libldmg.a

CFLAGS+=$(shell pkg-config --cflags r_util)
LDFLAGS+=$(shell pkg-config --libs r_util)

