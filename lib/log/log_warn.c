#include <jcaslib/log.h>
#include "_log.h"

int
log_warn(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int ret = _logfp(stderr, "WARN", fmt, ap);
    va_end (ap);
    return (ret);
}
