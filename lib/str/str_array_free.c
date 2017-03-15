#include <jclib/str.h>

void
str_array_free (str_array_type *arr)
{
	for (size_t i = 0; i < str_array_size (arr); i++)
	{
		str_free (arr->data[i]);
		arr->data[i] = NULL;
	}
	arr->allocated = 0;
	arr->len = 0;
	free (arr->data);
	arr->data = NULL;
	free (arr);
	arr = NULL;
}
