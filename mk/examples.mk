.if exists(.opts.mk)
include .opts.mk
.endif


BINS != ls *.c | sed 's/\.c/\.bin/'
CFLAGS += -I../../include
LD_CFLAGS +=
CFLAGS_DEFINE +=
LIB_PATH = ../../build/lib/libjc.a


.PHONY: build
build: build-lib $(BINS)


.PHONY: build-lib
build-lib:
	@$(MAKE) -C ../../lib build


.SUFFIXES: .bin .c
.c.bin: $(.PREFIX).o $(LIB_PATH)
	$(CC) $(CFLAGS) -o $(.TARGET) $(.PREFIX).o $(LIB_PATH) $(LD_CFLAGS)


.SUFFIXES: .o .c
.c.o:
	$(CC) $(CFLAGS) $(CFLAGS_DEFINE) -fPIC -c -o $(.TARGET) $(.PREFIX).c


.PHONY: clean
clean:
	@rm -vf *.bin *.o


.PHONY: distclean
distclean: clean clean-depend
	@rm -vf $(PWD)/.opts.mk


.PHONY: clean-lib
clean-lib: clean
	@$(MAKE) -C ../../lib clean


.PHONY: depend
depend:
	$(CC) -I ../../include -E -MM *.c >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


# configure target could be overwritten per example if needed
.PHONY: configure
configure:
