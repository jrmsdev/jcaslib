#include <jclib/db.h>
#include <err.h>

void
db_insert (DBM *db, const char *key, const char *val)
{
	int stat = _db_store (db, key, val, DBM_INSERT);
	if (stat == 1)
		warnx ("db key already exists: '%s'", key);
}
