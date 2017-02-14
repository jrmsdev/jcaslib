#include ".build_info.h"
#include <jclib/build_info.h>
#include <jclib/log.h>

void print_build_info() {
    log_print("%s", "Build info:");
    log_print("  %s on %s", JCL_BUILD_BY, JCL_BUILD_TIME);
    log_print("  %s", JCL_BUILD_OS);
    log_print("  %s", JCL_CC_VERSION);
}
