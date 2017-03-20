#include <jclib/str.h>
#include <jclib/lib.h>

void
str_array_realloc (str_array_type *arr)
{
    if (str_array_len (arr) > 0)
    {
        size_t newsize = str_array_size (arr)
                + (STR_ARRAY_ALLOC * sizeof (str_type *));
        str_type **d = (str_type **) xrealloc (arr->data, newsize);
        arr->data = d;
        arr->allocated = newsize;
        for (size_t i = str_array_len (arr) + STR_ARRAY_ALLOC; i < newsize; i++)
        {
            arr->data[i] = NULL;
        }
    }
}
