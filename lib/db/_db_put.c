#include <jclib/db.h>
#include <err.h>

int
_db_put (DB *db, const char *key, const char *val, u_int flags)
{
	DBT *_key = dbt_alloc (key);
	DBT *_val = dbt_alloc (val);

	int stat = db->put (db, _key, _val, flags);
	if (stat == -1)
	{
		dbt_free (_key);
		dbt_free (_val);
		db_close (db);
		err (1, "db put failed");
		/* not reached */
		return (stat);
	}

	dbt_free (_key);
	dbt_free (_val);

	return (stat);
}
