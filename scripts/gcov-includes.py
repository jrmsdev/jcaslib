#!/usr/bin/env python3

import sys
from os import path
from glob import glob

if __name__ == '__main__':

    src_files = list ()
    src_files.extend (glob ('../bin/*/*.c'))
    src_files.extend (glob ('../lib/*/*.c'))

    print ('#include "includes_t.h"')
    print ()

    included_files = 0
    for f in src_files:
        if path.basename (f) != 'main.c':
            print ('#include "{}"'.format (f))
            included_files += 1

    print ()
    print ('#include <jcaslib/test.h>')
    print ()

    print ('void includes_t (test_suite_T *ts) {')
    print ('  int expect = 1;')
    print ('  test_T *t = t_start (ts, "{:d} files", expect);'.format (
           included_files))
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

    print ('included files:', included_files, file = sys.stderr)

    sys.exit (0)
