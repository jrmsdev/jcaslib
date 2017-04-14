#include <jcaslib/test.h>

void
t_error (test_T *t, const char *errmsg)
{
    const char *t_name = t->name;
    errx (1, "[FAIL] ERROR %s: %s", t_name, errmsg);
}
