include ../vars.mk

BINS != ls *.c | sed 's/\.c/\.bin/'
CFLAGS += -I ../../include

build: $(BINS)

.SUFFIXES: .bin .c
.c.bin: $(.PREFIX).o
	@make -C ../../lib build
	$(CC) $(CFLAGS) -o $(.TARGET) $(.PREFIX).o ../../build/lib/libjc.a

.PHONY: clean
clean:
	@rm -vf *.bin *.o

.PHONY: depend
depend:
	@$(CC) -I ../../include -E -MM *.c >.depend

.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
