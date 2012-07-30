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

from libcpp.string cimport string
from libcpp.vector cimport vector

cdef extern from "_seq_align_0_lib/seq_align_0.h" namespace "seq_align_0":
    cdef cppclass SingleAlign:
        SingleAlign(string, string) except +
    
        int s1_start, s1_end
        string s1_id
        
        int s2_start, s2_end
        string s2_id
        
        string align_str
    
    
    cdef cppclass SingleSeq:
        SingleSeq(string, string) except +
        string id
        string seq
