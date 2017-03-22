#include "build_info.h"
#include <jclib/log.h>
#include <string.h>

void print_build_info() {
    if (strncmp (JCASLIB_BUILD_TIME, "NOVAL", 5) != 0)
    {
        log_print("");
        log_print("Build info:");
        log_print("  %s on %s", JCASLIB_BUILD_BY, JCASLIB_BUILD_TIME);
        log_print("  %s", JCASLIB_BUILD_OS);
        log_print("  %s", JCASLIB_CC_VERSION);
        log_print("");
        log_print("Modules:");
        log_print("  %s", JCASLIB_MODULES);
    }
    if (strncmp (CONFIGURE_OPTS, "NOVAL", 5) != 0)
    {
        log_print("");
        log_print("Configure options:");
        log_print("  %s", CONFIGURE_OPTS);
    }
}
