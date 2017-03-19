#include <jclib/db.h>
#include <jclib/str.h>
#include <jclib/lib.h>

static str_array_type * lskeys (DBM *db, const char *kbase);
static dbdata * getdata (DBM *db, str_array_type *klist);

dbdata *
db_fetchall (DBM *db, const char *kbase)
{
    str_array_type *klist = lskeys (db, kbase);
    dbdata *dat = getdata (db, klist);
    str_array_free (klist);
    return (dat);
}

str_array_type *
lskeys (DBM *db, const char *kbase)
{
    str_array_type *l = str_array_alloc ();
    char addkey = 0;
    size_t klen = 0;
	if (kbase != NULL)
		klen = strlen (kbase);
    for (datum k = dbm_firstkey (db); k.dptr != NULL; k = dbm_nextkey (db))
    {
		if (kbase == NULL)
			addkey = 1;
		else if (strncmp (k.dptr, kbase, klen) >= 0)
			addkey = 1;
		if (addkey)
	        str_array_append (l, (const char *) k.dptr);
    }
    return (l);
}

dbdata *
getdata (DBM *db, str_array_type *klist)
{
	dbdata *dat = dbdata_alloc (klist->len);
	for (size_t idx = 0; idx < klist->len; idx++)
	{
		dat->db[idx]->key =
				(char *) xmalloc ((klist->data[idx]->len + 1) * sizeof (char));
		memcpy (dat->db[idx]->key,
				str_array_get (klist, idx), klist->data[idx]->len);
		char *v = db_fetch (db, dat->db[idx]->key);
		size_t vlen = strlen (v);
		dat->db[idx]->val = (char *) xmalloc ((vlen + 1) * sizeof (char));
		memcpy (dat->db[idx]->val, v, vlen);
	}
    return (dat);
}
