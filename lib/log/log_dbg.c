#include <jcaslib/log.h>
#include "_log.h"

int
log_dbg(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int ret = _logfp(stderr, "DBG", fmt, ap);
    va_end (ap);
    return (ret);
}
