#include <jcaslib/db.h>

void
db_close (DBM *db)
{
    dbm_close (db);
}
