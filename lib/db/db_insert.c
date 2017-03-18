#include <jclib/db.h>
#include <err.h>

void
db_insert (DB *db, const char *key, const char *val)
{
	int stat = _db_put (db, key, val, DB_INSERT_FLAGS);
	if (stat == 1)
		warnx ("db key already exists: '%s'", key);
}
