#include "build_info.h"
#include <jclib/log.h>
#include <string.h>

void print_build_info() {
    if (strncmp (JCL_BUILD_TIME, "NOVAL", 5) != 0)
    {
        log_print("");
        log_print("Build info:");
        log_print("  %s on %s", JCL_BUILD_BY, JCL_BUILD_TIME);
        log_print("  %s", JCL_BUILD_OS);
        log_print("  %s", JCL_CC_VERSION);
        log_print("");
        log_print("Modules:");
        log_print("  %s", JCL_MODULES);
    }
    if (strncmp (JCL_CONFIGURE, "NOVAL", 5) != 0)
    {
        log_print("");
        log_print("Configure options:");
        log_print("  %s", JCL_CONFIGURE);
    }
}
