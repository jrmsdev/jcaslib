#include <jcaslib/log.h>
#include "_log.h"

int log_err(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return _logfp(stderr, "ERR", fmt, ap);
}
