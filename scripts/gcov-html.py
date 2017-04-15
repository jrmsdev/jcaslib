#!/usr/bin/env python3

import os
import os.path
import sys
import html
import glob
import re


index_file = 'gcov.index'
htmlcov_dir = './htmlcov'


CSS = '''<style>
    body {
        background-color: #000000;
        color: #00cc00;
        font-family: monospace;
        font-size: 14px;
        padding: 1% 1%;
        margin: 0;
        line-height: 1.5em;
    }
    code.noexec {
        color: #cc0000;
    }
    code.exec {
        color: #00ff00;
    }
    code.normal {
        color: #007700;
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

TMPL_FILE_INFO = '{idx:5}: {lines_exec:15} <i>{name}</i>'

TMPL_CODE_NORMAL = '<code class="normal">{lineno:>4}: {content}</code>'

TMPL_CODE_NOEXEC = '<code class="noexec">{lineno:>4}: {content}</code>'

TMPL_CODE_EXEC = '<code class="exec">{lineno:>4}: {content}</code>'


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


def write_index (funcs, files):
    dst = os.path.join (htmlcov_dir, 'index.html')

    def files_info (fh):
        print ("files:", len (files), file = fh)
        idx = 0
        for i in files:
            idx += 1
            i['idx'] = idx
            line = TMPL_FILE_INFO.format(**i)
            print (line, file = fh)

    html_head (dst, 'index');

    with open (dst, 'a') as fh:
        files_info (fh)
        fh.flush ()
        fh.close ()

    html_tail (dst);


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
                        cur['name'] = html.escape (
                                line.strip().split(' ')[1].replace("'", ""))
                    except IndexError:
                        cur['name'] = '[[IndexError]]'

            if in_file:

                if line.strip () == "":
                    in_file = False
                    files_data.append (cur)
                    cur = None

                elif line.startswith ('File '):
                    try:
                        cur['name'] = html.escape (
                                line.strip().split(' ')[1].replace("'", ""))
                    except IndexError:
                        cur['name'] = '[[IndexError]]'

            if cur is not None:

                if line.startswith ('Lines executed:'):
                    try:
                        cur['lines_exec'] = html.escape (
                                line.strip().split(':')[1].strip())
                    except IndexError:
                        cur['lines_exec'] = '[[IndexError]]'

        fh.close ()

    print ("index: funcs", len (funcs_data), "- files", len (files_data))
    write_index (funcs_data, files_data)


def write_html (dst, title, gcov):
    html_head (dst, title)
    with open (dst, 'a') as fh:
        for line in gcov['lines']:
            print (line['tmpl'].format (**line['data']), file = fh)
        fh.flush ()
        fh.close ()
    html_tail (dst)


re_gcov_attr_source = re.compile ('^\s*-:\s*0:Source:(.*)$')
re_gcov_attr_runs = re.compile ('^\s*-:\s*0:Runs:(\d*)$')
re_gcov_normal = re.compile ('^\s*-:\s*(\d*):(.*)$')
re_gcov_noexec = re.compile ('^\s*#####:\s*(\d*):(.*)$')
re_gcov_exec = re.compile ('^\s*\d*:\s*(\d*):(.*)$')


def parse_gcov (src):

    def new_line(tmpl, lineno, content):
        return {
            'tmpl': tmpl,
            'data': {'lineno': lineno, 'content': content},
        }

    dst = os.path.join (htmlcov_dir, src)
    dst = dst.replace('.gcov', '.html')
    gcov = dict(lines = list ())

    with open (src, 'r') as fh:
        for line in fh.readlines ():

            m = re_gcov_attr_source.match (line)
            if m:
                gcov['attr.source'] = html.escape (m.group (1))
                continue

            m = re_gcov_attr_runs.match (line)
            if m:
                gcov['attr.runs'] = html.escape (m.group (1))
                continue

            m = re_gcov_normal.match (line)
            if m:
                idx = m.group (1)
                if idx != "0":
                    gcov['lines'].append (new_line (TMPL_CODE_NORMAL,
                            idx, html.escape (m.group (2))))
                continue

            m = re_gcov_noexec.match (line)
            if m:
                idx = m.group (1)
                gcov['lines'].append (new_line (TMPL_CODE_NOEXEC,
                        idx, html.escape (m.group (2))))
                continue

            m = re_gcov_exec.match (line)
            if m:
                idx = m.group (1)
                gcov['lines'].append (new_line (TMPL_CODE_EXEC,
                        idx, html.escape (m.group (2))))
                continue

        fh.close ()
    write_html (dst, src.replace ('.gcov', ''), gcov)
    print ("parse:", src, "->", dst)


def scan_files ():
    for src in sorted (glob.glob ('*.gcov')):
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
    scan_files ()
    parse_index ()


if __name__ == '__main__':
    sys.exit (main())
