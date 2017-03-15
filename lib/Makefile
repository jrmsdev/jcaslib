BUILDD = ../build/lib
SCRIPTSD = ../scripts
LIB_PATH = $(BUILDD)/libjc.a
SHARED_LIB_PATH = $(BUILDD)/libjc.so

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
	@ar -Drc $(LIB_PATH) $(MOD_OBJS)
	ranlib $(LIB_PATH)


$(SHARED_LIB_PATH): $(MOD_OBJS)
	@mkdir -p $(BUILDD)
	$(CC) -shared -o $(SHARED_LIB_PATH) $(MOD_OBJS)


$(MOD_OBJS):
	@$(MAKE) -C $(.TARGET:H:T) build


.PHONY: clean
clean:
	@rm -vrf $(BUILDD)


.PHONY: distclean
distclean:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh distclean


.PHONY: depend
depend:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh depend


.PHONY: clean-depend
clean-depend:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh clean-depend


.PHONY: configure
configure:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh configure
