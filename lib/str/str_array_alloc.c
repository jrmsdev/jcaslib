#include <jcaslib/str.h>
#include <jcaslib/lib.h>

str_array_type *
str_array_alloc ()
{
    size_t arrsize = (STR_ARRAY_ALLOC * sizeof (str_type));
    str_array_type *arr = (str_array_type *) xmalloc (sizeof (str_array_type));
    arr->data = (str_type **) xmalloc (arrsize);
    for (size_t i = 0; i < STR_ARRAY_ALLOC; i++)
    {
        arr->data[i] = NULL;
    }
    arr->allocated = arrsize;
    arr->len = 0;
    arr->last = 0;
    return (arr);
}
