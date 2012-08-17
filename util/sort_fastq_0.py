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

import sys
import getopt

from Bio import SeqIO

def sort_fastq_by_id(read_file, fmt, out_prefix):
    reads = []
    for rec in SeqIO.parse(read_file, fmt):
        reads.append(rec)
    reads.sort(key=lambda rec: rec.id.split("_")[0])
    
def main():
    read_file = None
    fmt = None
    out_prefix = None
    if (not read_file
        or not fmt
        or not out_prefix):
        print >> sys.stderr, "missing"
        sys.exit(1)    
    
if __name__ == '__main__':
    main()    
    