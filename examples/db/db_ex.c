/*
** https://web.stanford.edu/class/cs276a/projects/docs/berkeleydb/
**/

#include <jclib/db.h>
#include <stdio.h>

int
main (void)
{
	DBM *db = db_open ("/tmp/jclib-db_ex");
	db_insert (db, "dbkey", "dbval");

	/* force a warn message about key already exists */
	db_insert (db, "dbkey", "dbval");

	db_replace (db, "dbkey", "dbval2");
	db_replace (db, "dbkey2", "dbval");

    char *val = db_fetch (db, "dbkey");
    if (val != NULL)
    {
        printf ("dbkey: %s\n", val);
    }

    val = db_fetch (db, "dbkey3");
    if (val == NULL)
    {
        printf ("dbkey3: not found\n");
    }
    else
    {
        printf ("dbkey3: %s\n", val);
    }

    dbdata *dat = db_fetchall (db, NULL);
    for (size_t i = 0; i < dbdata_len (dat); i++)
		printf ("key: %s - val: %s\n", dbdata_key (dat, i), dbdata_val (dat, i));
    dbdata_free (dat);

	db_close (db);
	return (0);
}
