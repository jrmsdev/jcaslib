#!/usr/bin/env python3

import sys
from os import path
from glob import glob

if __name__ == '__main__':

    gcov_files = list ()
    gcov_excluded = 0

    for f in sorted (glob ('*.gcov')):
        fpath = f.replace ('^#', '../').replace ('#', '/')

        if fpath in gcov_files:
            print ("gcov dup file?:", f, '->', fpath)

        else:
            gcov_files.append (fpath.replace ('.gcov', ''))

    if len (gcov_files) == 0:
        print ('gcov miss: no *.gcov files found')
        sys.exit (1)

    src_files = list ()
    src_files.extend (glob ('../bin/*/*.c'))
    src_files.extend (glob ('../lib/*/*.c'))
    src_files.extend (glob ('*_t.c'))

    gcov_miss = 0

    src_excluded = 0
    for f in sorted (src_files):
        status = '  ok'

        if path.basename (f) == 'main.c':
            src_excluded += 1
            continue

        if f not in gcov_files:
            status = 'miss'
            gcov_miss += 1
            print ('gcov ', status, ': ', f.replace ('../', '', 1), sep = '');

    print (' src:', len (src_files), end='')
    print (' - ok:', len (src_files) - src_excluded, end='')
    print (' - excluded:', src_excluded, end='')
    print (' file(s)')
    print ('gcov:', len (gcov_files), end='')
    print (' - ok:', len (gcov_files) - gcov_excluded, end='')
    print (' - excluded:', gcov_excluded, end='')
    print (' - miss:', gcov_miss, end='')
    print (' file(s)')

    sys.exit (0)
