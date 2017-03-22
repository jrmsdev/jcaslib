.PATH: ../mk
.if exists(configure.mk)
include configure.mk
.endif

BUILDD = ../build/lib
SCRIPTSD = ../scripts
LIB_PATH = $(BUILDD)/libjc.a
SHARED_LIB_PATH = $(BUILDD)/libjc.so

MOD_HEADERS != ls ../include/jclib/*.h
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
	$(CC) -shared -o $(SHARED_LIB_PATH) $(MOD_OBJS) $(LD_CFLAGS)


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
