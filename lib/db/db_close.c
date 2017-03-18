#include <jclib/db.h>
#include <err.h>

void
db_close (DBM *db)
{
	dbm_close (db);
}
