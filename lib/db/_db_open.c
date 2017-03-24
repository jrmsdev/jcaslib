#include <jcaslib/db.h>

DBM *
_db_open (const char *fname, int flags)
{
    return (dbm_open (fname, flags, 0640));
}
