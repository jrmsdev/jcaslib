#include <jclib/str.h>
#include <string.h>

void str_set (str_type *dst, const char *adds)
{
    str_nset (dst, adds, strlen (adds));
}
