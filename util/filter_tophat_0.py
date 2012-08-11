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

"""
for
    SINGLE
reads only    
"""

import getopt
import sys

import pysam
from Bio import SeqIO

def filter_tophat(tophat_file, unaligned_file, read_file):
    bamfile = pysam.Samfile(tophat_file, 'rb')
    aligned_ids = set([])
    for align in bamfile.fetch():
        if not align.is_unmapped:
            aligned_ids.add(align.qname)
    with open(unaligned_file, 'w') as fout:
        for rec in SeqIO.parse(read_file, 'fastq'):
            if rec.id not in aligned_ids:
                fout.write(rec.format('fasta'))

def main():
    tophat_file = None
    unaligned_file = None
    read_file = None
    try:
        opts, _ = getopt.getopt(sys.argv[1:], 's:', ['tophat=', 'un='])
    except getopt.GetoptError as err:
        print >> sys.stderr, str(err)
        sys.exit(1)
    for opt, arg in opts:
        if opt == '--un':
            unaligned_file = arg
        if opt == '-s':
            read_file = arg 
        if opt == '--tophat':
            tophat_file = arg
    if (not tophat_file
        or not unaligned_file
        or not read_file):
        print >> sys.stderr, "missing"
        sys.exit(1)
    filter_tophat(tophat_file, unaligned_file, read_file)

if __name__ == '__main__':
    main()    

