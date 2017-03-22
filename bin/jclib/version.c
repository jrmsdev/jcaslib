#include <jclib/version.h>
#include <jclib/log.h>

void print_version() {
    if (JCL_VERSION_PATCH > 0)
        log_print("%s v%d.%d.%d", JCL_APP_NAME, JCL_VERSION_MAJOR,
                                  JCL_VERSION_MINOR, JCL_VERSION_PATCH);
    else
        log_print("%s v%d.%d", JCL_APP_NAME,
                               JCL_VERSION_MAJOR, JCL_VERSION_MINOR);
}
