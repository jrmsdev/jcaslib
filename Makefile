PREFIX ?= /opt/pkg

.PHONY: build
build:
	@make -C lib build
	@make -C bin build

.PHONY: clean
clean:
	@make -C bin clean
	@make -C lib clean
