#include <jclib/db.h>
#include <jclib/log.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DB_UPDATE_KEY DB_KEY_PREFIX"update"

void
_db_updated (DBM *db)
{
    time_t update_t = time (NULL);
    if (update_t == -1)
        log_exit (1, "could not get current epoch");

    char update_s[11];
    snprintf (update_s, 11, "%ld", update_t);

    datum k;
    datum v;
    k.dptr = (void *) DB_UPDATE_KEY;
    k.dsize = strlen (DB_UPDATE_KEY) + 1;
    v.dptr = (void *) update_s;
    v.dsize = 11;

    dbm_store (db, k, v, DBM_REPLACE);
}
