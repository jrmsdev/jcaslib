#include <jclib/db.h>
#include <jclib/lib.h>
#include <string.h>

datum *
_datum_alloc (const char *str)
{
	size_t slen = strlen (str) + 1;
	datum *d = (datum *) xmalloc (sizeof (datum));
	d->dsize = slen;
	d->dptr = (void *) xmalloc (slen * (sizeof (char)));
	strncpy (d->dptr, str, slen);
	return (d);
}
