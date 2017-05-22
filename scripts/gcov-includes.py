#!/usr/bin/env python3

import sys
from os import path
from glob import glob

if __name__ == '__main__':

    src_files = list ()
    src_files.extend (glob ('../bin/*/*.c'))
    src_files.extend (glob ('../lib/*/*.c'))

    included_files = 0
    for f in src_files:
        if path.basename (f) != 'main.c':
            print ('#include "{}"'.format (f))
            included_files += 1

    print ('#define INCLUDED_FILES "{}"'.format (included_files))
    print ('included files:', included_files, file = sys.stderr)

    sys.exit (0)
