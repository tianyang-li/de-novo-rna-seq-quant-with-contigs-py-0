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

import sys
import getopt

def usage():
    print >> sys.stderr, "%s" % (sys.argv[0])

def die_usage():
    usage()
    sys.exit(1)

def main():
    r2c_align_file = None  # SAM or BAM containing read to contig alignments
    c2c_align_file = None  # SAM or BAM containing contig to contig alignments
    
    if not r2c_align_file:
        print >> sys.stderr, "Read to contig alignment file missing!"
        die_usage()
        
    if not c2c_align_file:
        print >> sys.stderr, "Contig to contig alignment file is missing"
        die_usage()

if __name__ == '__main__':
    main()



