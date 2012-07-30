all: util/seq_align_0.so

util/seq_align_0.so: \
util/_seq_align_0.pyx util/_cython_setup.py \
util/_seq_align_0.pxd \
seq_align_0.a
	
	cd util && python _cython_setup.py build_ext --inplace 

seq_align_0.a: 
	cd util/_seq_align_0_lib/ && $(MAKE)

test: 
	cd test && $(MAKE)

clean_test:
	cd test && $(MAKE) clean

clean:
	cd util/_seq_align_0_lib/ && $(MAKE) clean
	rm -fv util/seq_align_0.so util/_seq_align_0.cpp
	rm -rfv util/build/

.PHONY: clean test clean_test seq_align_0.a

