all: util/sw_align_0.so

util/sw_align_0.so: util/sw_align_0.pyx util/_cython_setup.py
	cd util && python _cython_setup.py build_ext --inplace 

clean:
	rm -fv util/sw_align_0.so util/sw_align_0.c
	rm -rfv util/build

.PHONY: clean

