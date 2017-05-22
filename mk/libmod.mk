.PATH: ../../mk
.if exists(configure.mk)
include configure.mk
.endif

INCD != realpath ../../include
CFLAGS_INCLUDE = -I$(INCD)
CFLAGS += $(CFLAGS_INCLUDE) $(CFLAGS_DEFINE) -fPIC -c

MOD_NAME != basename $(PWD)

BUILDD != echo $$(realpath $(PWD)/../..)/build/lib/$(MOD_NAME)
MOD_SRCS != ls *.c

MOD_OBJS =
.for src in $(MOD_SRCS)
MOD_OBJS += $(BUILDD)/$(src:S/.c/.o/)
.endfor

MOD_LIBNAME := libjcas-$(MOD_NAME)
MOD_LIBDIR != echo $$(realpath $(PWD)/../..)/build/lib
MOD_LIBPATH := $(MOD_LIBDIR)/$(MOD_LIBNAME).a
MOD_LIBPATH_SO := $(MOD_LIBDIR)/$(MOD_LIBNAME).so


.PHONY: build
build: pre-build $(MOD_OBJS)
.ifdef MOD_GENLIB
	@$(MAKE) mod-genlib
.endif


# pre-build target could be overwritten per module if needed
.PHONY: pre-build
pre-build:


$(MOD_OBJS):
	@mkdir -p $(BUILDD)
	$(CC) $(CFLAGS) -o $(.TARGET) $(.TARGET:T:S/.o/.c/)


.PHONY: depend
depend: pre-build
	$(CC) $(CFLAGS_INCLUDE) $(CFLAGS_DEFINE) -E -MM *.c |\
			sed 's#^\(.*\)\.o:#$(BUILDD)/\1.o:#' >$(PWD)/.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf $(PWD)/.depend


.PHONY: clean
clean: clean-mod
	@rm -vrf $(BUILDD)


# clean-mod target could be overwritten per module if needed
.PHONY: clean-mod
clean-mod:


.PHONY: distclean
distclean: clean clean-depend


.PHONY: mod-genlib
mod-genlib: $(MOD_LIBPATH) $(MOD_LIBPATH_SO)


$(MOD_LIBPATH): $(MOD_OBJS)
	@mkdir -p $(MOD_LIBDIR)
	@ar -rc $(MOD_LIBPATH) $(MOD_OBJS)
	ranlib $(MOD_LIBPATH)


$(MOD_LIBPATH_SO): $(MOD_OBJS)
	@mkdir -p $(MOD_LIBDIR)
	$(CC) -shared -o $(MOD_LIBPATH_SO) $(MOD_OBJS) $(LDFLAGS)


.PHONY: install-lib
install-lib:
.ifdef MOD_GENLIB
	@mkdir -vp $(DESTDIR)$(PREFIX)/lib
	@$(INSTALL_F) $(MOD_LIBPATH) $(DESTDIR)$(PREFIX)/lib
	@$(INSTALL_F) $(MOD_LIBPATH_SO) $(DESTDIR)$(PREFIX)/lib
.endif


.PHONY: install
install: install-lib


.PHONY: uninstall
uninstall:
	@rm -vf $(DESTDIR)$(PREFIX)/$(MOD_LIBNAME).*
