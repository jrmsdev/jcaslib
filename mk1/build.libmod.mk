SH = /bin/sh
DEPS_FILE := $(PWD)/mod.deps.mk

.PHONY: all
all: build

.PHONY: build
build:
	@echo "build.libmod: $(PWD)"
	@echo "build.libmod: $(DEPS_FILE)"

.PHONY: clean
clean:
	@echo "clean.libmod PWD: $(PWD)"
