CFLAGS += -Wall -pedantic -std=c11 -ggdb
BUILDD ?= ../build

.PHONY: build
build: $(BUILDD)/bin/jclib

$(BUILDD)/bin/jclib: jclib.c
	@make -C ../lib build
	@mkdir -vp $(BUILDD)/bin
	$(CC) $(CFLAGS) -I ../include -o $(BUILDD)/bin/jclib \
			jclib.c $(BUILDD)/lib/libjc.a

.PHONY: clean
clean:
	@rm -vrf $(BUILDD)/bin
	@make -C ../lib clean
