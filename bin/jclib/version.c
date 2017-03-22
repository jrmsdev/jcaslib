#include <jcaslib/version.h>
#include <jcaslib/log.h>

void print_version() {
    if (JCASLIB_VERSION_PATCH > 0)
        log_print("%s v%d.%d.%d", JCASLIB_APP_NAME, JCASLIB_VERSION_MAJOR,
                                  JCASLIB_VERSION_MINOR, JCASLIB_VERSION_PATCH);
    else
        log_print("%s v%d.%d", JCASLIB_APP_NAME,
                               JCASLIB_VERSION_MAJOR, JCASLIB_VERSION_MINOR);
}
