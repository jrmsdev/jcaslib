include ../mk/vars.mk

BINS != ls *.c | sed 's/\.c/.bin/'

.PHONY: build
build: $(BINS)

.SUFFIXES: .c .bin

.c.bin:
	$(CC) -I../include $(CFLAGS) -o $@ $< ../build/lib/libjcas.a

.PHONY: clean
clean:
	@rm -vf *.bin

.PHONY: depend
depend:
	$(CC) -I../include -E -MM *.c | sed 's/\.o/.bin/' >.depend
