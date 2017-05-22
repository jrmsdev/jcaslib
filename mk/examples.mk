.PATH: ../../mk
.if exists(configure.mk)
include configure.mk
.endif

BINS != ls $(PWD)/*.c | sed 's/\.c/\.bin/'
OBJS = $(BINS:S/.bin/.o/)
INCD != realpath ../../include
CFLAGS += -I$(INCD) $(CFLAGS_DEFINE)
LIB_PATH != echo $$(realpath $(PWD)/../..)/build/lib/libjcas.a


.PHONY: build
build: build-lib $(OBJS) $(BINS)


.PHONY: build-lib
build-lib:
	@$(MAKE) -C ../../lib build


.SUFFIXES: .bin .c
$(BINS): $(.PREFIX).o $(LIB_PATH)
	$(CC) $(CFLAGS) -o $(.TARGET) $(.PREFIX).o $(LIB_PATH) $(LDFLAGS)


.SUFFIXES: .o .c
$(OBJS):
	$(CC) $(CFLAGS) -fPIC -c -o $(.TARGET) $(.PREFIX).c


.PHONY: clean
clean:
	@rm -vf $(PWD)/*.bin $(PWD)/*.o


.PHONY: distclean
distclean: clean clean-depend


.PHONY: clean-lib
clean-lib: clean
	@$(MAKE) -C ../../lib clean


.PHONY: depend
depend:
	$(CC) -I$(INCD) $(CFLAGS_DEFINE) -E -MM *.c >$(PWD)/.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf $(PWD)/.depend
