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

from libcpp.string cimport string
from libcpp.vector cimport vector

cimport _sw_align_0
from _sw_align_0 cimport SingleSeq

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

cdef convert_SWAlign(_sw_align_0.SingleSWAlign * x):
    y = SWAlign(x.s1_id.c_str(), x.s1_start,
                x.s1_end, x.s2_id.c_str(),
                x.s2_start, x.s2_end,
                x.align_str.c_str())
    return y

cdef extern from "_sw_align_0_lib/sw_align_0.h" namespace "sw_align_0":
    void SingleReadContigPairSWCPP(vector[SingleSeq] * reads,
                                   vector[SingleSeq] * contigs,
                                   vector[_sw_align_0.SingleSWAlign] * aligns)

cdef void _get_read_id_seq(fasta_file, vector[SingleSeq] * contig_seqs_cpp):
    data_list = []
    for rec in SeqIO.parse(fasta_file, 'fasta'):
        rec_seq = str(rec.seq)
        contig_seqs_cpp.push_back(SingleSeq(< string >< char *> rec.id,
                                            < string >< char *> rec_seq))

def SingleReadContigPairSW(contig_file, read_file):

    cdef vector[SingleSeq] contig_seqs_cpp
    _get_read_id_seq(contig_file, & contig_seqs_cpp)
    
    cdef vector[SingleSeq] read_seqs_cpp
    _get_read_id_seq(read_file, & read_seqs_cpp)
    
    cdef vector[_sw_align_0.SingleSWAlign] rc_aligns 
    
    SingleReadContigPairSWCPP(& read_seqs_cpp,
                              & contig_seqs_cpp, & rc_aligns)

    
    
