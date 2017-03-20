#include <jclib/db.h>

void
db_close (DBM *db)
{
    dbm_close (db);
}
