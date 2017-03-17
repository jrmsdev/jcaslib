/*
** https://web.stanford.edu/class/cs276a/projects/docs/berkeleydb/
**/

#include <db.h>
#include <fcntl.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>

int oflags = O_CREAT | O_SYNC | O_RDWR;
int omode = 0640;

DB *
db_open (const char *fname)
{
	return (dbopen (fname, oflags, omode, DB_BTREE, NULL));
}

void
db_close (DB *db)
{
	int stat = db->close (db);
	if (stat != 0)
		err (stat, "could not close db file");
}

DBT *
dbt_alloc (const char *str)
{
	size_t slen = strlen (str);
	DBT *t = (DBT *) calloc (1, sizeof (DBT));
	t->size = slen;
	t->data = (void *) strndup (str, slen);
	return (t);
}

void
dbt_free (DBT *t)
{
	t->size = 0;
	free (t->data);
	t->data = NULL;
	free (t);
	t = NULL;
}

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

int
main (void)
{
	DB *db = db_open ("/tmp/jclib-btree.db");
	db_put (db, "dbkey", "dbval");
	db_close (db);
	return (0);
}
