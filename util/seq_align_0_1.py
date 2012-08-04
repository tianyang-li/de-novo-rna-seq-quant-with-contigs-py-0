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

from seq_align_0 import SingleReadContigPairAlign

def s_get_unaligned(s_read_file, aligns, fout_file):
    with open(fout_file, 'w') as fout:
        for rec in SeqIO.parse(s_read_file, 'fasta'):
            if rec.id not in aligns:
                fout.write(rec.format('fasta'))

class _ActionType(object):
    s_filter_unaglined = 1  # s_ single

def main():
    s_read_file = None  # reads unaligned by bowtie and blat
    contig_file = None
    s_unaligned_file = None
    action = None
    try:
        opts, args = getopt.getopt(sys.argv[1:], 'c:',
                                   ['SR=', 'SUA='])
    except getopt.GetoptError as err:
        print >> sys.stderr, str(err)
        sys.exit(1)
    for opt, arg in opts:
        if opt == '-c':
            contig_file = arg
        if opt == '--SR':
            s_read_file = arg
            action = _ActionType.s_filter_unaglined
        if opt == '--SUA':
            s_unaligned_file = arg
            action = _ActionType.s_filter_unaglined
    if (not action or
        (action == _ActionType.s_filter_unaglined 
         and (not s_read_file or not s_unaligned_file))
        or not contig_file):
        print >> sys.stderr, "missing"
        sys.exit(1)
    if action == _ActionType.s_filter_unaglined:
        aligns = SingleReadContigPairAlign(contig_file, s_read_file)
        s_get_unaligned(s_read_file, aligns, s_unaligned_file)
        
if __name__ == '__main__':
    main()        
    
    
