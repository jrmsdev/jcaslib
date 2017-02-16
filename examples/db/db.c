#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <string.h>
#include <jclib/db.h>

static void free_dat (datum dat)
{
    if (dat.dptr != NULL)
    {
        warn ("free_dat...");
        free (dat.dptr);
        dat.dsize = 0;
    }
}

int main (void)
{
    DBM *db = db_openfile ("/tmp/jrms-dbm2");
    if (db == NULL)
        err (2, "could not db_openfile");

    datum dat = dbm_firstkey (db);
    if (dat.dptr == NULL)
    {
        warn ("no first key found");
    }
    else
    {
        printf ("firstkey: %s\n", dat.dptr);
    }

    char * key_name = "lalala1";
    datum key;
    key.dptr = key_name;
    key.dsize = (int) strlen (key_name);

    if (db == NULL)
        err (2, "dbm not available");

    free_dat(dat);
    dat = dbm_fetch(db, key);
    if (dat.dptr == NULL)
    {
        warn("key not found: %s", key.dptr);
    }
    else
    {
        printf("%s: %s\n", key.dptr, dat.dptr);
        free_dat(dat);
    }

    dbm_close(db);
}
