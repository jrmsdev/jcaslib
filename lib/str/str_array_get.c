#include <jcaslib/str.h>
#include <err.h>

str_type *
str_array_get (str_array_type *arr, size_t idx)
{
    if (idx > arr->last)
        err(1, "invalid str array index: %zu", idx);

    if (arr->data[idx] == NULL)
        return (NULL);

    return (arr->data[idx]);
}
