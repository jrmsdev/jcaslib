/*
** https://web.stanford.edu/class/cs276a/projects/docs/berkeleydb/
**/

#include <jclib/db.h>
#include <stdio.h>

int
main (void)
{
	DBM *db = db_open ("/tmp/jclib-btree");
	db_insert (db, "dbkey", "dbval");

	/* force a warn message about key already exists */
	db_insert (db, "dbkey", "dbval");

	db_replace (db, "dbkey", "dbval2");
	db_replace (db, "dbkey2", "dbval");

    str_type *val = db_fetch (db, "dbkey");
    if (val != NULL)
    {
        printf ("dbkey: %s\n", str_get (val));
        str_free (val);
    }

    val = db_fetch (db, "dbkey3");
    if (val == NULL)
    {
        printf ("dbkey3: not found\n");
    }
    else
    {
        printf ("dbkey3: %s\n", str_get (val));
        str_free (val);
    }

	db_close (db);
	return (0);
}
