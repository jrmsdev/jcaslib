include ../../../mk1/vars.mk
include ../../../mk1/build.bincmd.vars.mk

CFLAGS += -I$(INCDIR)

.PHONY: build
build:
	@$(CC) -I$(INCDIR) -E -MM $(SRCDIR)/*.c >$(CMD_DEPMK)
	@$(MAKE) -f $(BASEDIR)/mk1/build.bincmd.objs.mk build


#~ .PHONY: build
#~ build: $(CMDBIN)


#~ $(CMDBIN): $(CMDOBJS)
#~ 	$(CC) $(CFLAGS) -o $@ $(BUILDDIR)/*.o


#~ $(CMDOBJS):
#~ 	@$(CC) -I$(INCDIR) -E -MM $(SRCDIR)/*.c >$(CMD_DEPMK)
#~ 	@$(MAKE) -f $(BASEDIR)/mk1/build.bincmd.objs.mk build
