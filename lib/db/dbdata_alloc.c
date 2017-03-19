#include <jclib/db.h>
#include <jclib/lib.h>

dbdata *
dbdata_alloc (size_t len)
{
	dbdata *dat = (dbdata *) xmalloc (sizeof (dbdata));
	dat->db = (dbrec **) xmalloc (len * sizeof (dbrec *));
	dat->len = len;
	for (size_t i = 0; i < len; i++)
		dat->db[i] = (dbrec *) xmalloc (sizeof (dbrec));
	return (dat);
}
