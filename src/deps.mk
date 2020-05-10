CFLAGS+=-I$(RR)/src
LDFLAGS+=-L$(RR)/src -ldemangle

CFLAGS+=$(shell pkg-config --cflags r_util)
LDFLAGS+=$(shell pkg-config --libs r_util)

