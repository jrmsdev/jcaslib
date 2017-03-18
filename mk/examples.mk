BINS != ls *.c | sed 's/\.c/\.bin/'
OBJS = $(BINS:S/.bin/.o/)
CFLAGS += -I../../include
LD_CFLAGS +=
LIB_PATH = ../../build/lib/libjc.a


.PHONY: build
build: build-lib $(OBJS) $(BINS)


.PHONY: build-lib
build-lib:
	@$(MAKE) -C ../../lib build


.SUFFIXES: .bin .c
$(BINS): $(.PREFIX).o $(LIB_PATH)
	$(CC) $(CFLAGS) -o $(.TARGET) $(.PREFIX).o $(LIB_PATH) $(LD_CFLAGS)


.SUFFIXES: .o .c
$(OBJS):
	$(CC) $(CFLAGS) -fPIC -c -o $(.TARGET) $(.PREFIX).c


.PHONY: clean
clean:
	@rm -vf *.bin *.o


.PHONY: distclean
distclean: clean clean-depend


.PHONY: clean-lib
clean-lib: clean
	@$(MAKE) -C ../../lib clean


.PHONY: depend
depend:
	$(CC) -I ../../include -E -MM *.c >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
