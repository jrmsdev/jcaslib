#include <jclib/log.h>

int log_print(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return __logfp(stdout, fmt, ap);
}
