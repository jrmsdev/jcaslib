#include <jcaslib/log.h>
#include "_log.h"

int
log_perror(char *fmt, ...)
{
    perror ("");
    va_list ap;
    va_start(ap, fmt);
    int ret = _logfp(stderr, "ERR", fmt, ap);
    va_end (ap);
    return (ret);
}
