all: util/sw_align_0.so

util/sw_align_0.so: \
util/_sw_align_0.pyx util/_cython_setup.py \
util/_sw_align_0.pxd \
util/_sw_align_0_lib/sw_align_0.a
	
	cd util && rm -rf _sw_align_0.cpp \
	&& python _cython_setup.py build_ext --inplace 

util/_sw_align_0_lib/sw_align_0.a: util/_sw_align_0_lib/sw_align_0.cc util/_sw_align_0_lib/sw_align_0.h
	cd util/_sw_align_0_lib/ && $(MAKE)

test:
	cd test/ && $(MAKE)

clean:
	cd util/_sw_align_0_lib/ && $(MAKE) clean
	rm -fv util/sw_align_0.so util/_sw_align_0.cpp
	rm -rfv util/build/

.PHONY: clean

