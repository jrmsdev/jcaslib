#!/usr/bin/env python3

from sys import exit
from glob import glob

if __name__ == '__main__':

    gcov_files = list ()
    for f in sorted (glob ('*.gcov')):
        fpath = f.replace ('^#', '../').replace ('#', '/')
        if fpath in gcov_files:
            print ("gcov dup file?:", f, '->', fpath)
        else:
            gcov_files.append (f.replace ('^#', '../').replace ('#', '/').replace ('.gcov', ''))

    if len (gcov_files) == 0:
        print ('gcov miss: no *.gcov files found')
        exit (1)

    src_files = list ()
    src_files.extend (glob ('../bin/*/*.c'))
    src_files.extend (glob ('../lib/*/*.c'))
    src_files.extend (glob ('*_t.c'))

    idx = 0
    gcov_miss = 0
    for f in sorted (src_files):
        idx += 1
        status = '  ok'
        if f not in gcov_files:
            status = 'miss'
            gcov_miss += 1
        print ('gcov ', status, '(', idx, '): ', f.replace ('../', '', 1), sep = '');

    print ('gcov  src:', len (src_files))
    print ('gcov   ok:', len (gcov_files))
    print ('gcov miss:', gcov_miss, 'file(s) not tested')
    exit (0)
