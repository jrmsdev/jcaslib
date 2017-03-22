#include <jcaslib/str.h>
#include <string.h>

void
str_cat (str_type *dst, const char *adds)
{
    str_ncat (dst, adds, strlen (adds));
}
