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
for
    PAIRED-END 
reads
"""

import getopt
import sys

from blat_0 import read_psl

def read_paired_psl(psl1_file, psl2_file, psl_paired_out):
    """
    psl1_file, psl2_file
        sorted first by qName then by tName
    """

def main():
    psl1_file = None
    psl2_file = None
    psl_paired_out = None
    if (not psl1_file
        or not psl2_file
        or not psl_paired_out):
        print >> sys.stderr, "missing"
        sys.exit(1)
    read_paired_psl(psl1_file, psl2_file, psl_paired_out)

if __name__ == '__main__':
    main()

