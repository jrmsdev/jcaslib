#!/usr/bin/env python3

import sys
from glob import glob

EXCLUDE_TESTFILES = True

if __name__ == '__main__':

    gcov_files = list ()
    gcov_excluded = 0
    for f in sorted (glob ('*.gcov')):
        fpath = f.replace ('^#', '../').replace ('#', '/')

        if EXCLUDE_TESTFILES and fpath.endswith ('_t.c.gcov'):
            gcov_excluded += 1
            continue

        if fpath in gcov_files:
            print ("gcov dup file?:", f, '->', fpath)
        else:
            gcov_files.append (f.replace ('^#', '../').replace ('#', '/').replace ('.gcov', ''))

    if len (gcov_files) == 0:
        print ('gcov miss: no *.gcov files found')
        sys.exit (1)

    src_files = list ()
    #~ src_files.extend (glob ('../bin/*/*.c'))
    src_files.extend (glob ('../lib/*/*.c'))

    if not EXCLUDE_TESTFILES:
        src_files.extend (glob ('*_t.c'))

    includes_mode = False
    if len (sys.argv) == 2 and sys.argv[1] == '--includes':
        includes_mode = True
    include_files = list()

    gcov_miss = 0
    for f in sorted (src_files):
        if includes_mode:
            if f != 'includes_t.c' and not f.endswith ('_t.c'):
                include_files.append (f)
        else:
            status = '  ok'
            if f not in gcov_files:
                status = 'miss'
                gcov_miss += 1
                print ('gcov ', status, ': ', f.replace ('../', '', 1), sep = '');

    if includes_mode:
        print ('#include "includes_t.h"')
        print ()
        for f in include_files:
            print ('#include "{}"'.format (f))
        print ()
        print ('#include <jcaslib/test.h>')
        print ()
        print ('void includes_t (test_suite_T *ts) {')
        print ('  int expect = 1;')
        print ('  test_T *t = t_start (ts, "{:d} files", expect);'.format (
                len (include_files)))
        print ('  t_check (t, 0, "");')
        print ('  t_end (t);')
        print ('}')
        print ()
        print ('int main (int argc, char *argv[]) {')
        print ('  if (argc < 1)')
        print ('    errx (1, "ERROR: argc < 1???");')
        print ('  int expect = 1;')
        print ('  test_suite_T *ts = tsuite_start (argv[0], expect);')
        print ('  includes_t (ts);')
        print ('  return (tsuite_end (ts));')
        print ('}')
    else:
        print ('gcov  src:', len (src_files))
        print ('gcov   ok: {} (excluded: {})'.format (
                len (gcov_files) - gcov_excluded, gcov_excluded))
        print ('gcov miss:', gcov_miss, 'file(s) not tested')

    sys.exit (0)
