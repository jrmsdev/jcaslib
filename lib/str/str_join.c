#include <jclib/str.h>

void
str_join (str_type *dst, const char *sep, int count, const char *str, ...)
{
    va_list ap;
    va_start (ap, str);
    str_vjoin (dst, sep, count, str, ap);
    va_end (ap);
}
