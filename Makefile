all: util/seq_align_0.so

util/seq_align_0.so: \
util/_seq_align_0.pyx util/_cython_setup.py \
util/_seq_align_0.pxd \
util/_seq_align_0_lib/seq_align_0.a
	
	cd util && rm -rf _seq_align_0.cpp \
	&& python _cython_setup.py build_ext --inplace 

util/_seq_align_0_lib/seq_align_0.a: util/_seq_align_0_lib/seq_align_0.cc util/_seq_align_0_lib/seq_align_0.h
	cd util/_seq_align_0_lib/ && $(MAKE)

test: 
	cd test && $(MAKE)

clean_test:
	cd test && $(MAKE) clean

clean:
	cd util/_seq_align_0_lib/ && $(MAKE) clean
	rm -fv util/seq_align_0.so util/_seq_align_0.cpp
	rm -rfv util/build/

.PHONY: clean test clean_test

