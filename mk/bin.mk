.PATH: ../../mk
.if exists(configure.mk)
include configure.mk
.endif

LDFLAGS += -ljcas
BUILDD = ../../build
INCD = ../../include
BIN_NAME != basename $(PWD)
BIN_PATH = $(BUILDD)/bin/$(BIN_NAME)
BIN_SRCS != ls *.c
SHARED_LIB_PATH = $(BUILDD)/lib/libjcas.so


.PHONY: build
build: pre-build $(BIN_PATH)


# pre-build target could be overwritten per binary if needed
.PHONY: pre-build
pre-build:


$(BIN_PATH): $(BIN_SRCS) $(SHARED_LIB_PATH)
	@mkdir -p $(BUILDD)/bin
	$(CC) $(CFLAGS) $(CFLAGS_DEFINE) -I$(INCD) -L$(BUILDD)/lib\
		-o $(BIN_PATH) $(BIN_SRCS) $(LDFLAGS)


$(SHARED_LIB_PATH):
	@make -C ../../lib build


# clean-bin target could be overwritten per binary if needed
.PHONY: clean-bin
clean-bin:


.PHONY: clean
clean: clean-bin
	@rm -vrf $(BUILDD)/bin


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend: pre-build
	$(CC) -I $(INCD) -E -MM $(BIN_NAME).c |\
			sed 's#^$(BIN_NAME)\.o\:#$(BIN_PATH):#' >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


.PHONY: install
install:
	@$(INSTALL_EXE) $(BIN_PATH) $(DESTDIR)$(PREFIX)/bin/$(BIN_NAME)


.PHONY: uninstall
uninstall:
	@rm -vf $(DESTDIR)$(PREFIX)/bin/$(BIN_NAME)
