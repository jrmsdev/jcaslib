include ../mk/vars.mk

.if exists(.opts.mk)
include .opts.mk
.endif


BUILDD ?= ../build/lib
INCD ?= ../include/jclib
CFLAGS_INCLUDE = -I../include
CFLAGS += $(CFLAGS_INCLUDE) $(CFLAGS_DEFINE) -fPIC -c
SCRIPTSD ?= ../scripts

OBJS != ls *.c | sed 's/\.c/\.o/'


.PHONY: build
build: .build_info.h $(BUILDD)/libjc.a


$(BUILDD)/libjc.a: $(OBJS)
	@mkdir -vp $(BUILDD)
	ar -rc $(BUILDD)/libjc.a $(OBJS)


.build_info.h: $(SCRIPTSD)/build_info.sh
	@CC=$(CC) INCD=$(INCD) $(SCRIPTSD)/build_info.sh
	touch .build_info.h


.PHONY: depend
depend: .build_info.h
	$(CC) $(CFLAGS_INCLUDE) -E -MM *.c >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


.PHONY: clean
clean:
	@rm -vrf $(BUILDD) $(OBJS)


.PHONY: distclean
distclean: clean clean-depend
	@rm -vf .build_info.h .opts.mk


# -- configure

CFG_CFLAGS_DEFINE =

.ifdef USE_GDBM
CFG_CFLAGS_DEFINE += -DUSE_GDBM
.endif

.PHONY: configure
configure: .build_info.h
	@rm -f .opts.mk ; touch .opts.mk
	@echo 'CFLAGS_DEFINE += $(CFG_CFLAGS_DEFINE)' >>.opts.mk
	touch .opts.mk
