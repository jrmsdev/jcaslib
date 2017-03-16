#include <jclib/str.h>
#include <jclib/lib.h>
#include <stdio.h>

int
main (void)
{
	str_array_type *arr = str_array_alloc ();

	str_array_insert (arr, 0, "lalala0");
	str_array_insert (arr, 1, "lalala1");
	str_array_append (arr, "lalala2");
	str_array_insert (arr, 5, "lalala5");
	str_array_append (arr, "lalala6");

    for (size_t i = 0; i <= str_array_last (arr); i++)
    {
        printf ("arr[%zu] -> %s\n", i, str_array_get (arr, i));
    }

	str_array_free (arr);
	return (0);
}
