#include <jclib/str.h>
#include <jclib/lib.h>

int
main (void)
{
	str_type **arr = xmalloc (3 * sizeof (str_type *));

	arr[0] = str_alloc ();
	str_set (arr[0], "arr0");
	str_free (arr[0]);

	free (arr);

	str_array_type *sarr = str_array_alloc ();

	str_array_realloc (sarr);

	str_array_free (sarr);

	return (0);
}
