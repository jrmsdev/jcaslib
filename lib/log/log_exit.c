#include <jclib/log.h>
#include <stdlib.h>

void log_exit(int stat, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    _logfp(stderr, "E", fmt, ap);
    exit(stat);
}
