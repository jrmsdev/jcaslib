include ../../vars.mk

path_info.bin: path_info.c
	$(CC) $(CFLAGS) -I ../../include -o path_info.bin \
		path_info.c ../../build/lib/libjc.a

.PHONY: clean
clean:
	@rm -vf path_info.bin
