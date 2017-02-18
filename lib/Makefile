include ../vars.mk

BUILDD ?= ../build/lib
INCD ?= ../include/jclib
CFLAGS_INCLUDE = -I../include
CFLAGS += $(CFLAGS_INCLUDE) -fPIC -c
SCRIPTSD ?= ../scripts


.PHONY: build
build: .pre-build .build_info.h $(BUILDD)/libjc.a


.PHONY: .pre-build
.pre-build:
	@mkdir -vp $(BUILDD)


OBJS != ls *.c | sed 's/\.c/\.o/'


$(BUILDD)/libjc.a: $(OBJS)
	ar -rc $(BUILDD)/libjc.a $(OBJS)


.build_info.h: $(SCRIPTSD)/build_info.sh
	@CC=$(CC) INCD=$(INCD) $(SCRIPTSD)/build_info.sh
	touch .build_info.h


.PHONY: depend
depend: configure
	$(CC) $(CFLAGS_INCLUDE) -E -MM *.c >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


.PHONY: clean
clean:
	@rm -vrf $(BUILDD) $(OBJS)


.PHONY: distclean
distclean:
	@$(MAKE) clean clean-depend
	@rm -vrf .build_info.h $(INCD)/uselib.*.h


.PHONY: configure
configure: .build_info.h
	@CC="$(CC)" CFLAGS="$(CFLAGS)" $(SCRIPTSD)/configure-libs.sh
