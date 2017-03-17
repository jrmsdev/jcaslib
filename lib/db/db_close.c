#include <jclib/db.h>
#include <err.h>

void
db_close (DB *db)
{
	int stat = db->close (db);
	if (stat != 0)
		err (stat, "could not close db file");
}
