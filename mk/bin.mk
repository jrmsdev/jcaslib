BUILDD = ../../build
INCD = ../../include
BIN_NAME != basename $(PWD)
BIN_PATH = $(BUILDD)/bin/$(BIN_NAME)
LIB_PATH = $(BUILDD)/lib/libjc.a


.PHONY: build
build: $(BIN_PATH)


$(BIN_PATH): $(BIN_NAME).c $(LIB_PATH)
	@mkdir -p $(BUILDD)/bin
	$(CC) $(CFLAGS) -I $(INCD) -o $(BIN_PATH) $(BIN_NAME).c $(LIB_PATH)


$(BUILDD)/lib/libjc.a:
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
