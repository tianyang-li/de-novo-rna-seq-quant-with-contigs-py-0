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

from Bio import SeqIO

from libcpp.string cimport string
from libcpp.vector cimport vector

cimport _sw_align_0
from _sw_align_0 cimport SingleAlignSeq

class SWAlign(object):
    def __init__(self, s1_id, s1_start, s1_end,
                 s2_id, s2_start, s2_end,
                 align_str):
        self.s1_id = s1_id
        self.s1_start = s1_start
        self.s1_end = s1_end
        
        self.s2_id = s2_id
        self.s2_start = s2_start
        self.s2_end = s2_end
        
        self.align_str = align_str

cdef extern from "_sw_align_0_lib/sw_align_0.h" namespace "sw_align_0":
    void SingleReadContigPairSWCPP(vector[SingleAlignSeq] * reads, vector[SingleAlignSeq] * contigs)

def SingleReadContigPairSW(contig_file, read_file):
    
    def get_id_seq_tuple(fasta_file):
        data_list = []
        for rec in SeqIO.parse(fasta_file, 'fasta'):
            data_list.append((rec.id, str(rec.seq)))
    
    contig_seqs = get_id_seq_tuple(contig_file)
    read_seqs = get_id_seq_tuple(read_file) 
    
    
    
    
    
