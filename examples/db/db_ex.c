/*
** https://web.stanford.edu/class/cs276a/projects/docs/berkeleydb/
**/

#include <jclib/db.h>

int
main (void)
{
	DB *db = db_open ("/tmp/jclib-btree.db");
	db_insert (db, "dbkey", "dbval");

	/* should raise a warn message about key already exists */
	db_insert (db, "dbkey", "dbval");

	db_update (db, "dbkey", "dbval2");

	db_close (db);
	return (0);
}
