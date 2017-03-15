#include <jclib/str.h>
#include <jclib/lib.h>

str_array_type *
str_array_alloc ()
{
	str_array_type *arr = (str_array_type *) xmalloc (sizeof (str_array_type));
	arr->data = (str_type **) xmalloc (STR_ARRAY_ALLOC * sizeof (str_type));
	for (size_t i = 0; i < STR_ARRAY_ALLOC; i++)
	{
		arr->data[i] = str_alloc ();
	}
	arr->allocated = STR_ARRAY_ALLOC;
	arr->len = 0;
	return (arr);
}
