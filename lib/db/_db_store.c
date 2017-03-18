#include <jclib/db.h>
#include <err.h>

int
_db_store (DBM *db, const char *key, const char *val, int flags)
{
	datum *_key = _datum_alloc (key);
	datum *_val = _datum_alloc (val);

	int stat = dbm_store (db, *_key, *_val, flags);
	if (stat == -1)
	{
		_datum_free (_key);
		_datum_free (_val);
		db_close (db);
		err (1, "db put failed");
		/* not reached */
		return (stat);
	}

	_datum_free (_key);
	_datum_free (_val);

	return (stat);
}
