#include <jclib/str.h>
#include <jclib/lib.h>

char * str_init_len (size_t len)
{
    return (char *) xmalloc (len);
}

char * str_init ()
{
    return str_init_len (STR_ALLOC);
}
