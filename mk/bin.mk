.PATH: ../../mk
.if exists(configure.mk)
include configure.mk
.endif

LD_CFLAGS += -ljc
BUILDD = ../../build
INCD = ../../include
BIN_NAME != basename $(PWD)
BIN_PATH = $(BUILDD)/bin/$(BIN_NAME)
SHARED_LIB_PATH = $(BUILDD)/lib/libjc.so


.PHONY: build
build: $(BIN_PATH)


$(BIN_PATH): $(BIN_NAME).c $(SHARED_LIB_PATH)
	@mkdir -p $(BUILDD)/bin
	$(CC) $(CFLAGS) -I$(INCD) -L$(BUILDD)/lib -o $(BIN_PATH) $(BIN_NAME).c\
		$(LD_CFLAGS)


$(SHARED_LIB_PATH):
	@make -C ../../lib build


.PHONY: clean
clean:
	@rm -vrf $(BUILDD)/bin


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	$(CC) -I $(INCD) -E -MM $(BIN_NAME).c |\
			sed 's#^$(BIN_NAME)\.o\:#$(BIN_PATH):#' >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
