CFLAGS += -Wall -pedantic -std=c11 -I ../../include -ggdb

path_info.bin: path_info.c
	$(CC) $(CFLAGS) -o path_info.bin path_info.c ../../build/lib/libjc.a

.PHONY: clean
clean:
	@rm -vf path_info.bin
