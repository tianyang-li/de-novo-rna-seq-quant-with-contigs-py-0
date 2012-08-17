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
this only works on 
    SINGLE
reads    
"""

import sys
import getopt

from Bio import SeqIO
import networkx as nx

from blat_0 import read_psl
    

def scaffold_single(contig_file, read_dict, blat_file, dot_file):
    """
    blat_file
        sorted by tName then by tStart
    """  
    
    contigs = {}
    for rec in SeqIO.parse(contig_file, 'fasta'):
        contigs[rec.id] = rec
    
    gene_loci = []
    return gene_loci


def main():
    contig_file = None
    read_file = None
    blat_file = None
    try:
        opts, _ = getopt.getopt(sys.argv[1:], 'c:s:', ["blat="])
    except getopt.GetoptError as err:
        print >> sys.stderr, str(err)
        sys.exit(1)
    for opt, arg in opts:
        if opt == '-c':
            # contigs
            contig_file = arg
        if opt == '-s':
            # single reads
            read_file = arg
        if opt == '--blat':
            blat_file = arg
    if (not contig_file
        or not read_file
        or not blat_file):
        print >> sys.stderr, "missing"
        sys.exit(1)
    
    gene_loci = scaffold_single(contig_file, read_file, blat_file)


if __name__ == '__main__':
    main()

