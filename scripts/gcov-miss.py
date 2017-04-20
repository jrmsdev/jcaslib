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

    src_files = glob ('../lib/*/*.c')
    src_files.extend (glob ('../bin/*/*.c'))

    gcov_miss = 0
    for f in sorted (src_files):
        if f not in gcov_files:
            print ('gcov miss:', f.replace ('../', '', 1));
            gcov_miss += 1

    print ('gcov miss:', gcov_miss, 'file(s) - found:', len (src_files))
    exit (0)
