#include <jcaslib/log.h>
#include "_log.h"

int log_warn(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return _logfp(stderr, "WARN", fmt, ap);
}
