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

def single_unaligned(psl_file, read_file, fmt, unaligned_out, aligned_out):
    aligned_ids = set([])
    
    with open(psl_file, 'r') as fin:
        for line in fin:
            aligned_ids.add(line.strip().split("\t")[9]) 
    
    with open(unaligned_out, 'w') as un_fout:
        with open(aligned_out, 'w') as a_fout:
            for rec in SeqIO.parse(read_file, fmt):
                if rec.id not in aligned_ids:
                    un_fout.write(rec.format(fmt))
                else:
                    a_fout.write(rec.format(fmt))

class _ActionType(object):
    get_unaligned = 1

def main():
    action = None
    psl_file = None
    s_read_file = None
    s_unaligned_file = None
    s_aligned_file = None
    
    #TODO: paired end reads
    
    try:
        opts, args = getopt.getopt(sys.argv[1:],
                                   '',
                                   ['SP=', 'psl=',
                                    'SR='])
    except getopt.GetoptError as err:
        print >> sys.stderr, str(err)
        sys.exit(1)
    
    for opt, arg in opts:
        if opt == '--psl':
            psl_file = arg
        if opt == '--SP':  # single read output prefix
            s_unaligned_file = "%s_unaligned.fasta" % arg
            s_aligned_file = "%s_aligned.fasta" % arg
            action = _ActionType.get_unaligned
        if opt == '--SR':
            s_read_file = arg
        
    if ((action == _ActionType.get_unaligned 
         and not(s_read_file 
                 and s_unaligned_file 
                 and s_aligned_file))):
        print >> sys.stderr, "missing"
        sys.exit(1)
    
    if action == _ActionType.get_unaligned:
        single_unaligned(psl_file, s_read_file,
                         'fasta', s_unaligned_file,
                         s_aligned_file)

if __name__ == '__main__':
    main()
        

