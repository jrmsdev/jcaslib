#include <jclib/log.h>

int log_warn(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return _logfp(stderr, "W", fmt, ap);
}
