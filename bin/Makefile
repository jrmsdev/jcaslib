include ../vars.mk

BUILDD ?= ../build


.PHONY: build
build: $(BUILDD)/bin/jclib


$(BUILDD)/bin/jclib: jclib.c $(BUILDD)/lib/libjc.a
	@mkdir -vp $(BUILDD)/bin
	$(CC) $(CFLAGS) -I ../include -o $(BUILDD)/bin/jclib \
			jclib.c $(BUILDD)/lib/libjc.a


$(BUILDD)/lib/libjc.a:
	@make -C ../lib $(BUILDD)/lib/libjc.a


.PHONY: clean
clean:
	@rm -vrf $(BUILDD)/bin


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	$(CC) -I ../include -E -MM *.c >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
