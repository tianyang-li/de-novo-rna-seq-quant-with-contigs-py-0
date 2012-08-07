#!/usr/bin/env python

#  Copyright (C) 2012 Tianyang Li
#  tmy1018@gmail.com
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License

import getopt
import sys

from Bio import SeqIO

def single_filter_raw(read_file, fmt, out_prefix):
    # TODO: more complex methods than just removing reads
    # with N?
    with open(out_prefix, 'w') as fout:
        for rec in SeqIO.parse(read_file, fmt):
            if "N" not in str(rec.seq).upper():
                fout.write(rec.format('fasta'))

class _ActionType(object):
    single = 1
    paired = 2

def main():
    action = None
    if (not action):
        print >> sys.stderr, "missing"
        sys.exit(1)
    
