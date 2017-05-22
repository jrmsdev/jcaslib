.PATH: ../../mk
.if exists(configure.mk)
include configure.mk
.endif

BUILDD != echo $$(realpath $(PWD)/../..)/build
INCD != realpath $(PWD)/../../include
BIN_NAME != basename $(PWD)
BIN_PATH = $(BUILDD)/bin/$(BIN_NAME)
BIN_STATIC_PATH = $(BUILDD)/bin/$(BIN_NAME).static
BIN_SRCS != ls *.c
LIB_SRCS != ls ../../lib/*/*.c ../../lib/*/*.h
LIB_PATH = $(BUILDD)/lib/libjcas.a
SHARED_LIB_PATH = $(BUILDD)/lib/libjcas.so
BIN_OBJS_DIR = $(BIN_PATH).objs
BIN_OBJS =
.for srcf in $(BIN_SRCS)
BIN_OBJS += $(BIN_OBJS_DIR)/$(srcf:S/.c/.o/)
.endfor


.PHONY: build
build: pre-build $(BIN_PATH) $(BIN_STATIC_PATH)


# pre-build target could be overwritten per binary if needed
.PHONY: pre-build
pre-build:


$(BIN_PATH): $(BIN_OBJS) $(SHARED_LIB_PATH)
	@mkdir -p $(BUILDD)/bin
	$(CC) $(CFLAGS) $(CFLAGS_DEFINE) -I$(INCD) -L$(BUILDD)/lib\
		-o $(BIN_PATH) $(BIN_OBJS) $(LDFLAGS) -ljcas


$(BIN_STATIC_PATH): $(BIN_OBJS) $(LIB_PATH)
	@mkdir -p $(BUILDD)/bin
	$(CC) $(CFLAGS) $(CFLAGS_DEFINE) -I$(INCD) -L$(BUILDD)/lib\
		-o $(BIN_STATIC_PATH) $(BIN_OBJS) $(LIB_PATH) $(LDFLAGS)


$(BIN_OBJS):
	@mkdir -p $(BIN_OBJS_DIR)
	$(CC) $(CFLAGS) $(CFLAGS_DEFINE) -I$(INCD) -fPIC -c\
		-o $(.TARGET) $(.TARGET:T:S/.o/.c/)


$(SHARED_LIB_PATH) $(LIB_PATH): $(LIB_SRCS)
	@$(MAKE) -C ../../lib build


# clean-bin target could be overwritten per binary if needed
.PHONY: clean-bin
clean-bin:


.PHONY: clean
clean: clean-bin
	@rm -vrf $(BIN_PATH) $(BIN_OBJS) $(BIN_NAME).sh $(BIN_NAME).valgrind
	@rm -vf vgcore.* $(BIN_NAME).vg* $(BIN_NAME).gdb


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend: pre-build
	$(CC) $(CFLAGS_DEFINE) -I$(INCD) -E -MM *.c |\
			sed 's#^\(.*\)\.o:#$(BIN_OBJS_DIR)/\1.o:#' >$(PWD)/.depend
	$(CC) $(CFLAGS_DEFINE) -I$(INCD) -E -MM main.c |\
			sed 's#^main\.o\:#$(BIN_PATH):#' >>$(PWD)/.depend
	$(CC) $(CFLAGS_DEFINE) -I$(INCD) -E -MM main.c |\
			sed 's#^main\.o\:#$(BIN_STATIC_PATH):#' >>$(PWD)/.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf $(PWD)/.depend


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
	@rm -f $(BIN_NAME).sh $(BIN_NAME).valgrind $(BIN_NAME).gdb

	@echo '#!/bin/sh -x' >$(BIN_NAME).sh

#~ 	@echo 'export DYLD_LIBRARY_PATH=$(BUILDD)/lib' >>$(BIN_NAME).sh
#~ 	@echo 'export LD_LIBRARY_PATH=$(BUILDD)/lib' >>$(BIN_NAME).sh

	@cat $(BIN_NAME).sh >$(BIN_NAME).gdb
	@cat $(BIN_NAME).sh >$(BIN_NAME).valgrind

	@echo 'exec $(BIN_STATIC_PATH) $$@' >>$(BIN_NAME).sh

	@echo 'corefile=/var/dumps/$(BIN_NAME).core' >>$(BIN_NAME).gdb
	@echo 'test -s $$corefile &&' >>$(BIN_NAME).gdb
	@echo '  exec gdb $(BIN_STATIC_PATH) $$corefile' >>$(BIN_NAME).gdb
	@echo 'exec gdb $(BIN_STATIC_PATH)' >>$(BIN_NAME).gdb

	@echo 'VGARGS=$${VGARGS:-"--leak-check=full --show-leak-kinds=all"}' >>$(BIN_NAME).valgrind
	@echo 'exec $(DEV_VG) $${VGARGS} $(BIN_STATIC_PATH) $$@' >>$(BIN_NAME).valgrind

	@chmod 0750 $(BIN_NAME).sh $(BIN_NAME).valgrind $(BIN_NAME).gdb
