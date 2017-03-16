#include <jclib/str.h>
#include <jclib/lib.h>
#include <stdio.h>

int
main (void)
{
	str_array_type *arr = str_array_alloc ();
	printf ("array size: %zu\n", str_array_size (arr));

	//~ str_array_insert (0, "lalala0");

	str_array_realloc (arr);
	printf ("array realloc size: %zu\n", str_array_size (arr));

	str_array_free (arr);
	return (0);
}
