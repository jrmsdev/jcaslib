#include <jclib/log.h>

int log_dbg(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return _logfp(stderr, "D", fmt, ap);
}
