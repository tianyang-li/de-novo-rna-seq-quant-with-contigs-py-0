CC = g++
CFLAGS = -W -Wall -Wno-long-long -pedantic -Wno-variadic-macros -ggdb # remove debug
LIBS = -lrt

all: sw_align_0.a

sw_align_0.a: sw_align_0.o
	ar rcs sw_align_0.a sw_align_0.o

sw_align_0.o: sw_align_0.cc sw_align_0.h
	$(CC) $(CFLAGS) -c sw_align_0.cc -o sw_align_0.o 

clean:
	rm -rvf *.a *.o

.PHONY: clean




