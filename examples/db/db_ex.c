/*
** https://web.stanford.edu/class/cs276a/projects/docs/berkeleydb/
**/

#include <jclib/db.h>

int
main (void)
{
	DBM *db = db_open ("/tmp/jclib-btree");
	db_insert (db, "dbkey", "dbval");

	/* should raise a warn message about key already exists */
	db_insert (db, "dbkey", "dbval");

	db_replace (db, "dbkey", "dbval2");
	db_replace (db, "dbkey2", "dbval");

	db_close (db);
	return (0);
}
