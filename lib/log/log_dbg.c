#include <jcaslib/log.h>

int log_dbg(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return _logfp(stderr, "DBG", fmt, ap);
}
