#include <jcaslib/path.h>
#include <jcaslib/os.h>

void
path_join (str_type *dst, size_t count, char *str, ...)
{
    va_list ap;
    va_start (ap, str);
    str_vjoin (dst, OS_SEP, count, str, ap);
    va_end (ap);
}
