#include <jclib/db.h>
#include <stdlib.h>

void
_datum_free (datum *d)
{
	d->dsize = 0;
	free (d->dptr);
	d->dptr = NULL;
	free (d);
	d = NULL;
}
