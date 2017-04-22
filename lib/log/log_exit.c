#include <jcaslib/log.h>
#include <stdlib.h>
#include "_log.h"

void log_exit(int stat, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    _logfp(stderr, "ERR", fmt, ap);
    exit(stat);
}
