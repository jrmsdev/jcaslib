CFLAGS += -Wall -pedantic -std=c11 -I ../include

.PHONY: build
build: jclib.bin

jclib.bin: jclib.c
	@make -C ../lib build
	$(CC) $(CFLAGS) -o jclib.bin jclib.c ../lib/libjc.a

.PHONY: clean
clean:
	@rm -vf jclib.bin
	@make -C ../lib clean
