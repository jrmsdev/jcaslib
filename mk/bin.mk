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
SHARED_LIB_SRCS != ls ../../lib/*/*.c ../../lib/*/*.h
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


$(SHARED_LIB_PATH): $(SHARED_LIB_SRCS)
	@make -C ../../lib build


# clean-bin target could be overwritten per binary if needed
.PHONY: clean-bin
clean-bin:


.PHONY: clean
clean: clean-bin
	@rm -vrf $(BIN_PATH) $(BIN_OBJS) $(BIN_NAME).sh $(BIN_NAME).valgrind
	@rm -vf vgcore.* $(BIN_NAME).vg*


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


DEV_VG ?= valgrind
DEV_VGARGS ?= --leak-check=full --show-leak-kinds=all

.PHONY: dev
dev: build
	@rm -f $(BIN_NAME).sh $(BIN_NAME).valgrind
	@echo '#!/bin/sh' >$(BIN_NAME).sh
	@echo 'export DYLD_LIBRARY_PATH=$(BUILDD)/lib' >>$(BIN_NAME).sh
	@echo 'export LD_LIBRARY_PATH=$(BUILDD)/lib' >>$(BIN_NAME).sh
	@cat $(BIN_NAME).sh >$(BIN_NAME).valgrind
	@echo 'exec $(BIN_PATH) $$@' >>$(BIN_NAME).sh
	@echo 'VGARGS=$${VGARGS:-"$(DEV_VGARGS)"}' >>$(BIN_NAME).valgrind
	@echo '$(DEV_VG) --quiet --log-file=$(BIN_NAME).vg$$$$ $${VGARGS} $(BIN_PATH) $$@' >>$(BIN_NAME).valgrind
	@echo 'vgret=$$?' >>$(BIN_NAME).valgrind
	@echo 'if test 0 -eq $$vgret; then' >>$(BIN_NAME).valgrind
	@echo '    rm -f $(BIN_NAME).vg$$$$' >>$(BIN_NAME).valgrind
	@echo 'else' >>$(BIN_NAME).valgrind
	@echo '    echo $(BIN_NAME).vg$$$$' >>$(BIN_NAME).valgrind
	@echo '    cat $(BIN_NAME).vg$$$$' >>$(BIN_NAME).valgrind
	@echo 'fi' >>$(BIN_NAME).valgrind
	@echo 'exit $$vgret' >>$(BIN_NAME).valgrind
	@chmod 0750 $(BIN_NAME).sh $(BIN_NAME).valgrind
