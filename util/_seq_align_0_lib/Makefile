CC = g++

CFLAGS = -W -Wall -Wno-long-long \
-fPIC \
-pedantic -Wno-variadic-macros -ggdb # remove debug

LIBS = -lrt

INC= -I../seqan-1.3.1

all: seq_align_0.a

seq_align_0.a: seq_align_0.o seq_align_0_sup1.o 
	ar rcs seq_align_0.a seq_align_0.o
	rm -fv ../_seq_align_0.cpp

seq_align_0.o: seq_align_0.cc seq_align_0.h 
	$(CC) $(CFLAGS) $(INC) -c seq_align_0.cc -o seq_align_0.o 

seq_align_0_sup1.o: seq_align_0_sup1.cc seq_align_0_sup1.h
	$(CC) $(CFLAGS) $(INC) -c seq_align_0_sup1.cc -o seq_align_0_sup1.o 

clean:
	rm -rvf *.a *.o

.PHONY: clean




