SCRIPTSD != realpath $(PWD)/../scripts

.PHONY: all
all: build


.PHONY: build
build:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh build


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


.PHONY: install
install:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh install


.PHONY: uninstall
uninstall:
	@MAKE=$(MAKE) $(SCRIPTSD)/mk-fordirs.sh uninstall
