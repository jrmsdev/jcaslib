include ../vars.mk

BUILDD ?= ../build/lib
INCD ?= ../include/jclib
CFLAGS += -fPIC -c -I ../include


.PHONY: build
build: .pre-build .build_info.h $(BUILDD)/libjc.a


.PHONY: .pre-build
.pre-build:
	@mkdir -vp $(BUILDD)


OBJS != ls *.c | sed 's/\.c/\.o/'


$(BUILDD)/libjc.a: $(OBJS)
	ar -rc $(BUILDD)/libjc.a $(OBJS)


.build_info.h: .build_info.gen
	@CC=$(CC) INCD=$(INCD) $(SH) ./.build_info.gen
	touch .build_info.h


.PHONY: depend
depend: configure
	$(CC) -I ../include -E -MM *.c >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


.PHONY: clean
clean:
	@rm -vrf .build_info.h $(BUILDD) $(OBJS)


.PHONY: configure
configure: .build_info.h
	@CC="$(CC)" CFLAGS="$(CFLAGS)" $(SH) ./.configure.libs
