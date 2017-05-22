#include "includes_t.h"

#include "../bin/license-header/check_file.c"
#include "../bin/license-header/walkdir.c"
#include "../bin/jcasdb/usage.c"
#include "../bin/jcasdb/dbinfo.c"
#include "../bin/jcaslib/print_build_info.c"
#include "../bin/jcaslib/print_version.c"
#include "../lib/cfg/cfg.c"
#include "../lib/lib/xrealloc.c"
#include "../lib/lib/xmalloc.c"
#include "../lib/path/path_islink.c"
#include "../lib/path/path_isdir.c"
#include "../lib/path/path_exists.c"
#include "../lib/path/path_isfile.c"
#include "../lib/path/path_join.c"
#include "../lib/path/path_filename_ext.c"
#include "../lib/test/t_end.c"
#include "../lib/test/t_fatal.c"
#include "../lib/test/t_error.c"
#include "../lib/test/t_log.c"
#include "../lib/test/t_check.c"
#include "../lib/test/t_debug.c"
#include "../lib/test/tsuite_end.c"
#include "../lib/test/t_start.c"
#include "../lib/test/_tinfo.c"
#include "../lib/test/_tfail.c"
#include "../lib/test/_tprint.c"
#include "../lib/test/_tpass.c"
#include "../lib/test/tsuite_start.c"
#include "../lib/os/os_lsdir.c"
#include "../lib/os/_os_scandir.c"
#include "../lib/log/log_exit.c"
#include "../lib/log/log_warn.c"
#include "../lib/log/_logfp.c"
#include "../lib/log/log_set_progname.c"
#include "../lib/log/log_dbg.c"
#include "../lib/log/log_err.c"
#include "../lib/log/log_print.c"
#include "../lib/db/_db_updated.c"
#include "../lib/db/db_create.c"
#include "../lib/db/db_delete.c"
#include "../lib/db/db_close.c"
#include "../lib/db/db_fetch.c"
#include "../lib/db/_db_init.c"
#include "../lib/db/db_replace.c"
#include "../lib/db/_db_open.c"
#include "../lib/db/_db_store.c"
#include "../lib/db/db_open.c"
#include "../lib/db/db_insert.c"
#include "../lib/db/db_fetchall.c"
#include "../lib/db/dbdata_free.c"
#include "../lib/str/str_array_alloc.c"
#include "../lib/str/str_array_get.c"
#include "../lib/str/str_alloc.c"
#include "../lib/str/str_nset.c"
#include "../lib/str/str_set.c"
#include "../lib/str/str_array_free.c"
#include "../lib/str/str_array_append.c"
#include "../lib/str/str_join.c"
#include "../lib/str/str_vjoin.c"
#include "../lib/str/str_realloc.c"
#include "../lib/str/str_free.c"
#include "../lib/str/str_array_insert.c"
#include "../lib/str/str_array_realloc.c"
#include "../lib/str/str_cat.c"
#include "../lib/str/str_ncat.c"

#include <jcaslib/test.h>

void includes_t (test_suite_T *ts) {
  int expect = 1;
  test_T *t = t_start (ts, "65 files", expect);
  t_check (t, 0, "");
  t_end (t);
}

int main (int argc, char *argv[]) {
  if (argc < 1)
    errx (1, "ERROR: argc < 1???");
  int expect = 1;
  test_suite_T *ts = tsuite_start (argv[0], expect);
  includes_t (ts);
  return (tsuite_end (ts));
}
