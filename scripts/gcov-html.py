#!/usr/bin/env python3

import os
import os.path
import sys
import html
import glob


index_file = 'gcov.index'
htmlcov_dir = 'htmlcov'


CSS = '''<style>
    body {
        background-color: #000000;
        color: #00bb00;
        font-family: monospace;
        font-size: 14px;
        padding: 1% 1%;
        margin: 0;
    }
    </style>'''

TMPL_HEAD = '''<!doctype html>
<html>
<head>
    {css}
    <title>jcaslib tests coverage - {title}</title>
</head>
<body>
<pre>'''

TMPL_TAIL = '''</pre>
</body>
</html>'''


def html_head (out_f, title):
    with open (out_f, 'w') as fh:
        print (TMPL_HEAD.format (title = title, css = CSS), file = fh)
        fh.flush ()
        fh.close ()


def html_tail (out_f):
    with open (out_f, 'a') as fh:
        print (TMPL_TAIL, file = fh)
        fh.flush ()
        fh.close ()


def cat_file (src, dst):
    with open (src, 'r') as srcfh:
        with open (dst, 'a') as dstfh:
            for src_l in srcfh.readlines ():
                dstfh.write (html.escape (src_l))
            dstfh.flush ()
            dstfh.close ()
        srcfh.close ()


def parse_index ():

    funcs_data = list()
    files_data = list()

    def new_cur ():
        return {'name': None, 'lines_exec': None}

    with open (index_file, 'r') as fh:
        in_function = False
        in_file = False
        cur = None

        for line in fh.readlines ():

            if cur is None:
                if not in_function and line.startswith ('Function '):
                    in_function = True
                    cur = new_cur ()

                if not in_file and line.startswith ('File '):
                    in_file = True
                    cur = new_cur ()

            if in_function:

                if line.strip () == "":
                    in_function = False
                    funcs_data.append (cur)
                    cur = None

                elif line.startswith ('Function '):
                    try:
                        cur['name'] = line.strip().split(' ')[1].replace("'", "")
                    except IndexError as e:
                        cur['name'] = '[[IndexError:%s]]' % str (e)

            if in_file:

                if line.strip () == "":
                    in_file = False
                    files_data.append (cur)
                    cur = None

                elif line.startswith ('File '):
                    try:
                        cur['name'] = line.strip().split(' ')[1].replace("'", "")
                    except IndexError as e:
                        cur['name'] = '[[IndexError:%s]]' % str (e)

            if cur is not None:

                if line.startswith ('Lines executed:'):
                    try:
                        cur['lines_exec'] = line.strip().split(':')[1].strip()
                    except IndexError as e:
                        cur['lines_exec'] = '[[IndexError:%s]]' % str (e)

        fh.close ()

    for fd in funcs_data:
        print ("funcs_data:", fd)

    for fd in files_data:
        print ("files_data:", fd)


def write_gcov_index ():
    idxn = os.path.basename (index_file)
    dst = os.path.join (htmlcov_dir, idxn + '.html')
    html_head (dst, idxn);
    cat_file (index_file, dst)
    html_tail (dst);


def write_gcov_html (src):
    dst = os.path.basename (src)
    out_f = os.path.join (htmlcov_dir, dst + '.html')
    html_head (out_f, dst)
    cat_file (src, out_f)
    html_tail (out_f)


def parse_gcov (src):
    pass


def scan_files ():
    for src in glob.glob ('*.gcov'):
        write_gcov_html (src)
        parse_gcov (src)


def pre_checks ():
    if not os.path.isfile (index_file):
        print (index_file, "file not found")
        sys.exit (1)
    if not os.path.isdir (htmlcov_dir):
        print (htmlcov_dir, "dir not found")
        sys.exit (1)


def main ():
    pre_checks ()
    write_gcov_index ()
    scan_files ()
    parse_index ()


if __name__ == '__main__':
    sys.exit (main())
