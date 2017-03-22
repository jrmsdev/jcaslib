#include <jcaslib/str.h>

void
str_array_insert (str_array_type *arr, size_t idx, const char *str)
{
    if (idx > arr->len)
        str_array_realloc (arr);

    if (arr->data[idx] == NULL)
        arr->data[idx] = str_alloc ();

    str_set (arr->data[idx], str);
    size_t newlen = arr->len + 1;

    if (arr->len < newlen)
        arr->len = newlen;

    if (arr->last < idx)
        arr->last = idx;
}
