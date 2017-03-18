#include <jclib/db.h>

void
db_update (DB *db, const char *key, const char *val)
{
	(void) _db_put (db, key, val, DB_UPDATE_FLAGS);
}
