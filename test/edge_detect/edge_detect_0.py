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


from __future__ import division

import getopt
import sys
import random

from scipy.stats import chisquare
import numpy as np


def edge_stat(counts, win_size):
    """
    counts
        a list of length (2 * win_size)
        
    uses pearson's chi-squared test
    """
    # chi-stat, p-val
    return chisquare([sum(counts[:win_size]),
                      sum(counts[win_size:])])


def main():
    win_size = None
    ratio = None
    total_count = None
    try:
        opts, _ = getopt.getopt(sys.argv[1:], 'w:r:t:')
    except getopt.GetoptError as err:
        print >> sys.stderr, str(err)
        sys.exit(1)
    for opt, arg in opts:
        if opt == '-w':
            win_size = int(arg)
        if opt == '-r':
            ratio = float(arg)
        if opt == '-t':
            total_count = int(arg)
    if (not win_size
        or not ratio
        or not total_count):
        print >> sys.stderr, "missing"
        sys.exit(1)
    
    p = 1 / (ratio + 1)
    
    counts = [0] * (4 * win_size)
    
    for _ in xrange(total_count):
        if p >= random.random():
            offset = 0
        else:
            offset = 2 * win_size
        counts[offset + 
               random.randint(0, 2 * win_size - 1)] += 1
    
    for edge_loc in xrange(-win_size, win_size + 1):
        t_stat, p_val = edge_stat(counts[edge_loc + win_size:
                                         edge_loc + 3 * win_size],
                                  win_size)
        print edge_loc, t_stat, p_val
    
    
if __name__ == '__main__':
    main()
    

