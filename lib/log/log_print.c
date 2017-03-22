#include <jcaslib/log.h>

int log_print(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    return _logfp(stdout, NULL, fmt, ap);
}
