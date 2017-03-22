#include <jcaslib/db.h>
#include <fcntl.h>
#include <stdlib.h>

#define oflags O_CREAT | O_SYNC | O_RDWR
#define omode 0640

DBM *
db_open (const char *fname)
{
    DBM *db = dbm_open (fname, oflags, omode);
    _db_init (db);
    return (db);
}
