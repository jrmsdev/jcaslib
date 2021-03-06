.PATH: ../mk
.if exists(configure.mk)
include configure.mk
.endif

BUILDD != echo $$(realpath $(PWD)/..)/build/lib
SCRIPTSD != realpath ../scripts
LIB_PATH = $(BUILDD)/libjcas.a
SHARED_LIB_PATH = $(BUILDD)/libjcas.so

MOD_HEADERS != ls ../include/jcaslib/*.h
MOD_SRCS != ls */*.c
MOD_OBJS =
.for src in $(MOD_SRCS)
MOD_OBJS += $(BUILDD)/$(src:S/.c/.o/)
.endfor


.PHONY: all
all: build


.PHONY: build
build: $(LIB_PATH) $(SHARED_LIB_PATH)


$(LIB_PATH): $(MOD_OBJS)
	@mkdir -p $(BUILDD)
	@ar -rc $(LIB_PATH) $(MOD_OBJS)
	ranlib $(LIB_PATH)


$(SHARED_LIB_PATH): $(MOD_OBJS)
	@mkdir -p $(BUILDD)
	$(CC) -shared -o $(SHARED_LIB_PATH) $(MOD_OBJS) $(LDFLAGS)


$(MOD_OBJS): $(MOD_SRCS) $(MOD_HEADERS)
	@$(MAKE) -C $(.TARGET:H:T) build


.PHONY: clean
clean:
	@rm -vrf $(BUILDD)


.PHONY: distclean
distclean: clean-depend
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh distclean


.PHONY: depend
depend:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh depend
	@echo '$(MOD_OBJS): \' >.depend
	@echo '    $(MOD_SRCS)' >>.depend
	@echo '$(LIB_PATH) $(SHARED_LIB_PATH): \' >>.depend
	@echo '    $(MOD_OBJS)' >>.depend
	touch $(PWD)/.depend


.PHONY: clean-depend
clean-depend:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh clean-depend
	@rm -vf $(PWD)/.depend


.PHONY: install
install:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh install


.PHONY: uninstall
uninstall:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh uninstall
