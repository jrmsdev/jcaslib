#include <jclib/db.h>
#include <jclib/lib.h>
#include <string.h>

DBT *
dbt_alloc (const char *str)
{
	size_t slen = strlen (str) + 1;
	DBT *t = (DBT *) xmalloc (sizeof (DBT));
	t->size = slen;
	t->data = (void *) strndup (str, slen);
	return (t);
}
