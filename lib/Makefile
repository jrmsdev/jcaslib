BUILDD = ../build/lib
SCRIPTSD = ../scripts
LIB_PATH = $(BUILDD)/libjc.a

MOD_SRCS != ls */*.c
MOD_OBJS =
.for src in $(MOD_SRCS)
MOD_OBJS += $(BUILDD)/$(src:S/.c/.o/)
.endfor


.PHONY: all
all: build


.PHONY: build
build: $(LIB_PATH)


$(LIB_PATH): $(MOD_OBJS)
	@mkdir -p $(BUILDD)
	@ar -vDrc $(LIB_PATH) $(MOD_OBJS)
	ranlib $(LIB_PATH)


$(MOD_OBJS):
	@$(MAKE) -C $(.TARGET:H:T) build


.PHONY: clean
clean:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh clean


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
