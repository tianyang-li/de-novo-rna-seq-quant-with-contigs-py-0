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

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

seqan_libs = ["rt"]
seqan_cflags = ['-W', '-Wall', '-Wno-long-long',
                '-pedantic', '-Wno-variadic-macros']

setup(
    cmdclass={'build_ext': build_ext},
    ext_modules=[Extension("sw_align_0",
                           ["_sw_align_0.pyx"],
                           libraries=[] + seqan_libs,
                           extra_link_args=['-fPIC'] + seqan_cflags,
                           extra_compile_args=['-fPIC'] + seqan_cflags,
                           extra_objects=["_sw_align_0_lib/sw_align_0.a"],
                           include_dirs=["seqan-1.3.1/"],
                           language="c++"
                           )
                 ]
      )


