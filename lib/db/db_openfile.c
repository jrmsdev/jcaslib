#include <stdio.h>
#include <fcntl.h>
#include <err.h>
#include <jclib/db.h>

DBM * db_openfile (const char *filename)
{
    DBM *dbm = dbm_open (filename, O_CREAT | O_RDWR, 0660);
    if (dbm == NULL)
        err(1, "could not open db file");
    return (dbm);
}
