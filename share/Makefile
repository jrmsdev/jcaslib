include ../mk/vars.mk

BINS != ls *.c | sed 's/\.c/.bin/'
LIBPATH := ../build/lib/libjcas.a
LIBSRCS != ls ../lib/*/*.c ../lib/*/*.h

.PHONY: build
build: $(BINS)

.SUFFIXES: .c .bin

.c.bin: $(LIBPATH)
	$(CC) -I../include $(CFLAGS) -o $@ $< $(LIBPATH)

$(LIBPATH): $(LIBSRCS)
	@$(MAKE) -C ../lib build

.PHONY: clean
clean:
	@rm -vf *.bin

.PHONY: distclean
distclean: clean
	@rm -vf .depend

.PHONY: depend
depend:
	$(CC) -I../include -E -MM *.c | sed 's/\.o/.bin/' >.depend
