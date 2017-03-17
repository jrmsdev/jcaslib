/*
** https://web.stanford.edu/class/cs276a/projects/docs/berkeleydb/
**/

#include <jclib/db.h>

int
main (void)
{
	DB *db = db_open ("/tmp/jclib-btree.db");
	db_put (db, "dbkey", "dbval");
	db_close (db);
	return (0);
}
