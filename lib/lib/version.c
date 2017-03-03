#include <jclib/version.h>
#include <jclib/log.h>

void print_version() {
    log_print("%s v%s", JCL_APP_NAME, JCL_VERSION);
}
