#include <jcaslib/log.h>
#include "_log.h"

int
log_err(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int ret = _logfp(stderr, "ERR", fmt, ap);
    va_end (ap);
    return (ret);
}
