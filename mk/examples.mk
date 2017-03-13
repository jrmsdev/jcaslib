.if exists(.opts.mk)
include .opts.mk
.endif


BINS != ls *.c | sed 's/\.c/\.bin/'
CFLAGS += -I../../include
LD_CFLAGS +=
CFLAGS_DEFINE +=
LIB_PATH = ../../build/lib/libjc.a


build: $(BINS)


.SUFFIXES: .bin .c
.c.bin: $(.PREFIX).o
	@$(MAKE) -C ../../lib build
	$(CC) $(CFLAGS) -o $(.TARGET) $(.PREFIX).o $(LIB_PATH) $(LD_CFLAGS)


.SUFFIXES: .o .c
.c.o:
	$(CC) $(CFLAGS) $(CFLAGS_DEFINE) -fPIC -c -o $(.TARGET) $(.ALLSRC)


.PHONY: clean
clean:
	@rm -vf *.bin *.o


.PHONY: distclean
distclean: clean clean-depend


.PHONY: clean-lib
clean-lib: clean
	@$(MAKE) -C ../../lib clean


.PHONY: depend
depend:
	$(CC) -I ../../include -E -MM *.c >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


.ifdef USE_GDBM
CFG_CFLAGS_DEFINE += -DUSE_GDBM
CFG_LD_CFLAGS += -lgdbm_compat
.endif


.PHONY: configure
configure:
	@echo 'LD_CFLAGS += $(CFG_LD_CFLAGS)' >.opts.mk
	@echo 'CFLAGS_DEFINE += $(CFG_CFLAGS_DEFINE)' >>.opts.mk
	touch $(PWD)/.opts.mk
