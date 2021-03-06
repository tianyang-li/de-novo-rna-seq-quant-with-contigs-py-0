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

import random

def main():
    s_out = open('s.fasta', 'w')  # subject
    q_out = open('q.fastq', 'w')  # query reads
    
    s1 = "".join(random.choice(["A", "C", "G", "T"]) for _ in xrange(200))
    s2 = "".join(random.choice(["A", "C", "G", "T"]) for _ in xrange(200))
    
    s_out.write(">1\n%s\n" % s1)
    s_out.write(">2\n%s\n" % s2)
    
    qual_str = "~" * 100
    
    for q_start in xrange(100):
        q_seq = "%s%s" % (s1[q_start:100], s2[100:100 + q_start])
        q_out.write("@q%d\n%s\n+\n%s\n" % (q_start, q_seq, qual_str))
    
    s_out.close()
    q_out.close()

if __name__ == '__main__':
    main()
