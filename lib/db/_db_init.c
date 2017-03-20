#include <jclib/db.h>

#define DB_INIT_KEY "db:init"

void
_db_init (DBM *db)
{
    char *init = db_fetch (db, DB_INIT_KEY);
    if (init == NULL)
        db_insert (db, DB_INIT_KEY, "initialised");
}
