#include <jcaslib/path.h>

void
path_join (str_type *dst, size_t count, char *str, ...)
{
    va_list ap;
    va_start (ap, str);
    str_vjoin (dst, PATH_SEP, count, str, ap);
    va_end (ap);
}
