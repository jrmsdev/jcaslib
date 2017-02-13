CFLAGS += -Wall -pedantic -std=c11 -I ../include

OBJS = build_info.o

.PHONY: build
build: .build_info.h libjc.a

libjc.a: $(OBJS)
	ar -rc libjc.a $(OBJS)

.build_info.h:
	touch .build_info.h
	@echo "#define JCL_BUILD_TIME \"`date -R`\"" >.build_info.h
	@echo "#define JCL_BUILD_BY \"`id -un`@`uname -n`\"" >>.build_info.h
	@echo "#define JCL_BUILD_EPOCH \"`date '+%s'`\"" >>.build_info.h
	@echo "#define JCL_BUILD_OS \"`uname -snrm`\"" >>.build_info.h
	@echo "#define JCL_CC_VERSION \"`$(CC) --version | head -n 1`\"" >>.build_info.h

.PHONY: clean
clean:
	@rm -vf .build_info.h libjc.a $(OBJS)
