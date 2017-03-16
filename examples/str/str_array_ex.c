#include <jclib/str.h>
#include <jclib/lib.h>
#include <stdio.h>

int
main (void)
{
	str_array_type *arr = str_array_alloc ();
	printf ("array size: %zu\n", str_array_size (arr));
	printf ("array 0 len: %zu\n", str_array_len (arr));
	printf ("array 0 last: %zu\n", str_array_last (arr));

	str_array_insert (arr, 0, "lalala0");
	printf ("array 1 len: %zu\n", str_array_len (arr));
	printf ("array 1 last: %zu\n", str_array_last (arr));

	str_array_insert (arr, 1, "lalala1");
	printf ("array 2 len: %zu\n", str_array_len (arr));
	printf ("array 2 last: %zu\n", str_array_last (arr));

	str_array_append (arr, "lalala2");
	printf ("array 3 len: %zu\n", str_array_len (arr));
	printf ("array 3 last: %zu\n", str_array_last (arr));

	str_array_insert (arr, 5, "lalala5");
	printf ("array 4 len: %zu\n", str_array_len (arr));
	printf ("array 4 last: %zu\n", str_array_last (arr));

	str_array_append (arr, "lalala6");
	printf ("array 5 len: %zu\n", str_array_len (arr));
	printf ("array 5 last: %zu\n", str_array_last (arr));

    for (size_t i = 0; i <= str_array_last (arr); i++)
    {
        printf ("arr[%zu] -> %s\n", i, str_array_get (arr, i));
    }

	str_array_free (arr);
	return (0);
}
