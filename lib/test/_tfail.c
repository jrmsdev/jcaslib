#include <jcaslib/test.h>
#include "_test.h"

void _tfail (test_T *t, const char *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    _tprint (t, "[FAIL]", fmt, ap);
    va_end (ap);
}
