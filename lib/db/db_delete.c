#include <jclib/db.h>
#include <err.h>

void
db_delete (DBM *db, const char *key)
{
	datum k;
	k.dptr = (void *) key;
	k.dsize = strlen (key) + 1;
	if (dbm_delete (db, k) == -1)
		warnx ("db delete failed: %s", key);
}
