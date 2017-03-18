#include <jclib/db.h>

void
db_insert_or_update (DB *db, const char *key, const char *val)
{
	int stat = _db_put (db, key, val, DB_INSERT_FLAGS);
	if (stat == 1)
		(void) _db_put (db, key, val, DB_UPDATE_FLAGS);
}
