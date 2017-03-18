INCD = ../../include/jclib
CFLAGS_INCLUDE = -I../../include
CFLAGS_DEFINE +=
CFLAGS += $(CFLAGS_INCLUDE) $(CFLAGS_DEFINE) -fPIC -c

MOD_NAME != basename $(PWD)

BUILDD = ../../build/lib/$(MOD_NAME)
MOD_SRCS != ls *.c

MOD_OBJS =
.for src in $(MOD_SRCS)
MOD_OBJS += $(BUILDD)/$(src:S/.c/.o/)
.endfor


.PHONY: build
build: pre-build $(MOD_OBJS)


# pre-build target could be overwritten per module if needed
.PHONY: pre-build
pre-build:


$(MOD_OBJS):
	@mkdir -p $(BUILDD)
	$(CC) $(CFLAGS) -o $(.TARGET) $(.TARGET:T:S/.o/.c/)


.PHONY: depend
depend: pre-build
	$(CC) $(CFLAGS_INCLUDE) -E -MM *.c |\
			sed 's#^\(.*\)\.o:#$(BUILDD)/\1.o:#' >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


.PHONY: clean
clean: clean-mod
	@rm -vrf $(BUILDD)


# clean-mod target could be overwritten per module if needed
.PHONY: clean-mod
clean-mod:


.PHONY: distclean
distclean: clean clean-depend
	@rm -vf configure.opts config.h


CFG_CFLAGS_DEFINE =

# configure target could be overwritten per module if needed
.PHONY: configure
configure:
