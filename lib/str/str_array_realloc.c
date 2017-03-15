#include <jclib/str.h>
#include <jclib/lib.h>

void
str_array_realloc (str_array_type *arr)
{
	str_type **d = (str_type **) xrealloc (arr->data,
			str_array_size (arr) + (STR_ARRAY_ALLOC * sizeof (str_type)));
	size_t newsize = str_array_size (arr) + STR_ARRAY_ALLOC;
	arr->data = d;
	for (size_t i = str_array_size (arr); i < newsize; i++)
	{
		arr->data[i] = str_alloc ();
	}
	arr->allocated = newsize;
}
