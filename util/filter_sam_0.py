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

import pysam
from Bio import SeqIO

def filter_single(sam_file):
    s_sam = pysam.Samfile(sam_file, 'r')
    
def main():
    sam_file = None
    s_file = None
    fmt = None
    
    #TODO: paired-end reads

if __name__ == '__main__':
    main()

