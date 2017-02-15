include ../vars.mk

BUILDD ?= ../build

.PHONY: build
build: $(BUILDD)/bin/jclib

$(BUILDD)/bin/jclib: jclib.c
	@$(MAKE) -C ../lib build
	@mkdir -vp $(BUILDD)/bin
	$(CC) $(CFLAGS) -I ../include -o $(BUILDD)/bin/jclib \
			jclib.c $(BUILDD)/lib/libjc.a

.PHONY: clean
clean:
	@rm -vrf $(BUILDD)/bin
	@$(MAKE) -C ../lib clean

.PHONY: depend
depend:
	@$(CC) -I ../include -E -MM *.c >.depend

.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
