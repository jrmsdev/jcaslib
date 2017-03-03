BUILDD = ../../build
INCD = ../../include
BIN_NAME != basename $(PWD)


.PHONY: build
build: $(BUILDD)/bin/$(BIN_NAME)


$(BUILDD)/bin/$(BIN_NAME): $(BIN_NAME).c $(BUILDD)/lib/libjc.a
	@mkdir -vp $(BUILDD)/bin
	$(CC) $(CFLAGS) -I $(INCD) -o $(BUILDD)/bin/$(BIN_NAME) \
			$(BIN_NAME).c $(BUILDD)/lib/libjc.a


$(BUILDD)/lib/libjc.a:
	@make -C ../../lib build


.PHONY: clean
clean:
	@rm -vrf $(BUILDD)/bin


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	$(CC) -I $(INCD) -E -MM *.c >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
