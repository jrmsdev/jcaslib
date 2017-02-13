#include <stdio.h>

#include ".build_info.h"
#include <jclib/build_info.h>

void print_build_info() {
    printf("%s\n", "Build info:");
    printf("  %s at %s\n", JCL_BUILD_BY, JCL_BUILD_TIME);
    printf("  %s\n", JCL_BUILD_OS);
    printf("  %s\n", JCL_CC_VERSION);
}
