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
    s_out = open("s.fasta", 'w')
    q_out = open("q.fastq", 'w')
    
    s_seq = "".join(random.choice(["A", "C", "G", "T"]) for _ in xrange(200))
    s_out.write(">s\n%s\n" % s_seq[:100])
    
    for i in xrange(100):
        q_out.write("@q%d\n%s\n+\n%s\n" % (i, s_seq[i:i + 100], '~' * 100))
    
    s_out.close()
    q_out.close()

if __name__ == '__main__':
    main()


