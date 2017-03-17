#include <jclib/db.h>
#include <stdlib.h>

void
dbt_free (DBT *t)
{
	t->size = 0;
	free (t->data);
	t->data = NULL;
	free (t);
	t = NULL;
}
