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

    gcov_miss = 0
    for f in sorted (src_files):
        status = '  ok'
        if f not in gcov_files:
            status = 'miss'
            gcov_miss += 1
            print ('gcov ', status, ': ', f.replace ('../', '', 1), sep = '');

    print ('      src:', len (src_files))
    print ('     gcov: {}'.format (len (gcov_files)))
    print ('gcov   ok: {} (excluded: {})'.format (
            len (gcov_files) - gcov_excluded, gcov_excluded))
    print ('gcov miss:', gcov_miss, 'file(s)')

    sys.exit (0)
