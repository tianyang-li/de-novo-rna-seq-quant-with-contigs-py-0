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
PSL lines represent alignments, and are typically taken from files generated by BLAT or psLayout. See the BLAT documentation for more details. All of the following fields are required on each data line within a PSL file:
    matches - Number of bases that match that aren't repeats
    misMatches - Number of bases that don't match
    repMatches - Number of bases that match but are part of repeats
    nCount - Number of 'N' bases
    qNumInsert - Number of inserts in query
    qBaseInsert - Number of bases inserted in query
    tNumInsert - Number of inserts in target
    tBaseInsert - Number of bases inserted in target
    strand - '+' or '-' for query strand. For translated alignments, second '+'or '-' is for genomic strand
    qName - Query sequence name
    qSize - Query sequence size
    qStart - Alignment start position in query
    qEnd - Alignment end position in query
    tName - Target sequence name
    tSize - Target sequence size
    tStart - Alignment start position in target
    tEnd - Alignment end position in target
    blockCount - Number of blocks in the alignment (a block contains no gaps)
    blockSizes - Comma-separated list of sizes of each block
    qStarts - Comma-separated list of starting positions of each block in query
    tStarts - Comma-separated list of starting positions of each block in target 
"""

import sys
import getopt

from Bio import SeqIO

def filter_self(psl_in, psl_out):
    fin = open(psl_in, 'r')
    fout = open(psl_out, 'w')
    
    for line in fin:
        entries = line.strip().split("\t")
        if entries[13] != entries[9]:
            fout.write(line)
    
    fin.close()
    fout.close() 

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
    psl_un_duplicate = 2

def main():
    action = None
    psl_file = None
    s_read_file = None
    s_unaligned_file = None
    s_aligned_file = None
    
    s_psl_in = None
    s_psl_out = None
    
    #TODO: paired end reads
    
    try:
        opts, args = getopt.getopt(sys.argv[1:],
                                   '',
                                   ['SP=', 'psl=',
                                    'SR=',
                                    'psl-un-dup',
                                    's-psl-in=', 's-psl-out='])
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
        if opt == '--psl-un-dup':
            action = _ActionType.psl_un_duplicate
        if opt == '--s-psl-in':
            s_psl_in = arg
        if opt == '--s-psl-out':
            s_psl_out = arg
        
    if (not action 
        or (action == _ActionType.get_unaligned 
         and not(s_read_file 
                 and s_unaligned_file 
                 and s_aligned_file))
        or (action == _ActionType.psl_un_duplicate
            and not(s_psl_in
                    and s_psl_out))):
        print >> sys.stderr, "missing"
        print >> sys.stderr, action, psl_file, s_read_file, s_unaligned_file,
        print >> sys.stderr, s_aligned_file,
        print >> sys.stderr, s_psl_in, s_psl_out
        sys.exit(1)
    
    if action == _ActionType.get_unaligned:
        single_unaligned(psl_file, s_read_file,
                         'fasta', s_unaligned_file,
                         s_aligned_file)
    elif action == _ActionType.psl_un_duplicate:
        filter_self(s_psl_in, s_psl_out)

if __name__ == '__main__':
    main()
        
