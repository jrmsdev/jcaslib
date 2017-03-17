#include <jclib/db.h>
#include <err.h>

void
db_put (DB *db, const char *key, const char *val)
{
	DBT *_key = dbt_alloc (key);
	DBT *_val = dbt_alloc (val);

	int stat = db->put (db, _key, _val, R_SETCURSOR);
	if (stat == -1)
	{
		dbt_free (_key);
		dbt_free (_val);
		db_close (db);
		err (1, "db put failed");
	}

	dbt_free (_key);
	dbt_free (_val);
}
