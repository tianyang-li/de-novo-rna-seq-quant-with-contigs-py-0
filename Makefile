CC = g++
CFLAGS = -W -Wall -Wno-long-long -pedantic -Wno-variadic-macros
LIBS = -lrt

all: util/sw_align_0.so

util/sw_align_0.so: util/sw_align_0.pyx util/_cython_setup.py
	cd util && python _cython_setup.py build_ext --inplace 

