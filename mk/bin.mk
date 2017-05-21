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
BIN_OBJS_DIR = $(BIN_PATH).objs
BIN_OBJS =
.for srcf in $(BIN_SRCS)
BIN_OBJS += $(BIN_OBJS_DIR)/$(srcf:S/.c/.o/)
.endfor


.PHONY: build
build: pre-build $(BIN_PATH)


# pre-build target could be overwritten per binary if needed
.PHONY: pre-build
pre-build:


$(BIN_PATH): $(BIN_OBJS)
	@mkdir -p $(BUILDD)/bin
	$(CC) $(CFLAGS) $(CFLAGS_DEFINE) -I$(INCD) -L$(BUILDD)/lib\
		-o $(BIN_PATH) $(BIN_OBJS) $(LDFLAGS)


$(BIN_OBJS): $(SHARED_LIB_PATH)
	@mkdir -p $(BIN_OBJS_DIR)
	$(CC) $(CFLAGS) $(CFLAGS_DEFINE) -I$(INCD) -fPIC -c\
		-o $(.TARGET) $(.TARGET:T:S/.o/.c/)


$(SHARED_LIB_PATH):
	@make -C ../../lib build


# clean-bin target could be overwritten per binary if needed
.PHONY: clean-bin
clean-bin:


.PHONY: clean
clean: clean-bin
	@rm -vrf $(BIN_PATH) $(BIN_OBJS) $(BIN_NAME).bin


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend: pre-build
	$(CC) $(CFLAGS_DEFINE) -I$(INCD) -E -MM *.c |\
			sed 's#^\(.*\)\.o:#$(BIN_OBJS_DIR)/\1.o:#' >.depend
	$(CC) $(CFLAGS_DEFINE) -I$(INCD) -E -MM main.c |\
			sed 's#^main\.o\:#$(BIN_PATH):#' >>.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


INSTALL_BIN ?= false

.PHONY: install
install:
.if $(INSTALL_BIN) == true
	@$(INSTALL_EXE) $(BIN_PATH) $(DESTDIR)$(PREFIX)/bin/$(BIN_NAME)
.endif


.PHONY: uninstall
uninstall:
	@rm -vf $(DESTDIR)$(PREFIX)/bin/$(BIN_NAME)


.PHONY: devbin
devbin: build
	@rm -f $(BIN_NAME).bin
	@echo '#!/bin/sh' >$(BIN_NAME).bin
	@echo 'export DYLD_LIBRARY_PATH=$(BUILDD)/lib' >>$(BIN_NAME).bin
	@echo 'export LD_LIBRARY_PATH=$(BUILDD)/lib' >>$(BIN_NAME).bin
	@echo 'exec $(BIN_PATH) $$@' >>$(BIN_NAME).bin
	@chmod 0750 $(BIN_NAME).bin
