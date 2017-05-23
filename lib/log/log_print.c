#include <jcaslib/log.h>
#include "_log.h"

int
log_print(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int ret = _logfp(stdout, NULL, fmt, ap);
    va_end (ap);
    return (ret);
}
