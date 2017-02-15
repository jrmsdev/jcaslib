#include <stdlib.h>
#include <stdarg.h>
#include <jclib/log.h>

void log_exit(int stat, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    __logfp(stderr, fmt, ap);
    exit(stat);
}
