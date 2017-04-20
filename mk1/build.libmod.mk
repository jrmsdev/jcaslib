SH = /bin/sh

# -- main targets

.PHONY: all
all: build

.PHONY: build
build:
	@echo "build.libmod: $(PWD)"

.PHONY: clean
clean:
	@echo "clean.libmod PWD: $(PWD)"
