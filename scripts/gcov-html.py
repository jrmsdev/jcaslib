#!/usr/bin/env python3

import os
import os.path
import sys
import html
import glob
import re

gcov_out = 'gcov.out'
htmlcov_dir = './htmlcov'

#
# -- HTML templates
#

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
        color: #00ee00;
    }
    code.normal {
        color: #008800;
    }
    code.info {
        color: #aa00bb;
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

TMPL_FILE_SUMM = '{idx:5}: {lines_exec:15} <i>{name}</i>'

TMPL_CODE_NORMAL = '<code class="normal">{lineno:>4}: {content}</code>'

TMPL_CODE_NOEXEC = '<code class="noexec">{lineno:>4}: {content}</code>'

TMPL_CODE_EXEC = '<code class="exec">{lineno:>4}: {content}</code>'

TMPL_GCOV_INFO = '<code class="info"><small>{content}</small></code>'

#
# -- file i/o (write) actions
#

def write_html_head (out_f, title):
    with open (out_f, 'w') as fh:
        print (TMPL_HEAD.format (title = title, css = CSS), file = fh)
        fh.flush ()
        fh.close ()


def write_html_tail (out_f):
    with open (out_f, 'a') as fh:
        print (TMPL_TAIL, file = fh)
        fh.flush ()
        fh.close ()


def write_summary (funcs, files):
    dst = os.path.join (htmlcov_dir, 'summary.html')

    def files_info (fh):
        print ("files:", len (files), file = fh)
        idx = 0
        for i in files:
            idx += 1
            i['idx'] = idx
            line = TMPL_FILE_SUMM.format(**i)
            print (line, file = fh)

    write_html_head (dst, 'gcov run summary');

    with open (dst, 'a') as fh:
        files_info (fh)
        fh.flush ()
        fh.close ()

    write_html_tail (dst);


def write_html (dst, title, gcov):
    write_html_head (dst, title)
    with open (dst, 'a') as fh:
        for line in gcov['lines']:
            print (line['tmpl'].format (**line['data']), file = fh)
        fh.flush ()
        fh.close ()
    write_html_tail (dst)


def write_index (gcovdb):
    dst = os.path.join (htmlcov_dir, 'index.html')
    write_html_head (dst, 'index')

    with open (dst, 'a') as fh:

        print ("scanned files:", len (gcovdb), file = fh)

        for i in gcovdb:
            print ("       ", i['src'], file = fh)

        fh.flush ()
        fh.close ()

    write_html_tail (dst)
    print ("index:", dst)

#
# -- parse gcov info/report files
#

def parse_summary ():

    funcs_data = list()
    files_data = list()

    def new_cur ():
        return {'name': None, 'lines_exec': None}

    with open (gcov_out, 'r') as fh:
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

    print ("summary: funcs", len (funcs_data), "- files", len (files_data))
    write_summary (funcs_data, files_data)


# -- parse gcov regexs
re_gcov_attr_source = re.compile ('^\s*-:\s*0:Source:(.*)$')
re_gcov_attr_runs = re.compile ('^\s*-:\s*0:Runs:(\d*)$')
re_gcov_normal = re.compile ('^\s*-:\s*(\d*):(.*)$')
re_gcov_noexec = re.compile ('^\s*#####:\s*(\d*):(.*)$')
re_gcov_exec = re.compile ('^\s*\d*:\s*(\d*):(.*)$')
re_gcov_info = re.compile ('^(\w+\s.*)$')


def parse_gcov (src):

    def new_code_line (gcov, tmpl, lineno, content):
        gcov['lines'].append ({
            'tmpl': tmpl,
            'data': {'lineno': lineno, 'content': content},
        })

    def new_line (gcov, tmpl, content):
        gcov['lines'].append ({'tmpl': tmpl, 'data': {'content': content}})

    dst = os.path.join (htmlcov_dir, src)
    dst = dst.replace('.gcov', '.html')
    gcov = dict(lines = list ())

    # XXX: not sure why yet but it needs to start as 1 instead of 0
    gcov_lines = 1

    print ("parse:", src, "->", dst)

    with open (src, 'r') as fh:
        for line in fh.readlines ():

            m = None
            gcov_lines += 1

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
                    new_code_line (gcov, TMPL_CODE_NORMAL, idx,
                            html.escape (m.group (2)))
                continue

            m = re_gcov_noexec.match (line)
            if m:
                idx = m.group (1)
                new_code_line (gcov, TMPL_CODE_NOEXEC, idx,
                        html.escape (m.group (2)))
                continue

            m = re_gcov_exec.match (line)
            if m:
                idx = m.group (1)
                new_code_line (gcov, TMPL_CODE_EXEC, idx,
                        html.escape (m.group (2)))
                continue

            m = re_gcov_info.match (line)
            if m:
                new_line (gcov, TMPL_GCOV_INFO, html.escape (m.group (1)))
                continue

            if m is None:
                print ("parse:", src, "unkown line:", gcov_lines)

        fh.close ()
    write_html (dst, src.replace ('.gcov', ''), gcov)
    return gcov


#
# -- main
#

def scan_files ():
    db = list()

    def gcov_append (src, gcov):
        db.append ({'src': src.replace ('.gcov', ''), 'data': gcov})

    for src in sorted (glob.glob ('*.gcov')):
        gcov_append (src, parse_gcov (src))

    return db


def pre_checks ():
    if not os.path.isfile (gcov_out):
        print (gcov_out, "file not found")
        sys.exit (1)
    if not os.path.isdir (htmlcov_dir):
        print (htmlcov_dir, "dir not found")
        sys.exit (1)


def main ():
    pre_checks ()
    gcovdb = scan_files ()
    parse_summary ()
    write_index (gcovdb)


if __name__ == '__main__':
    sys.exit (main())
