include config.mk

all:
	$(MAKE) -C src
	$(MAKE) -C test
	#$(MAKE) -C src/cxx
