CC = g++
CFLAGS = -W -Wall -Wno-long-long -pedantic -Wno-variadic-macros -ggdb
LIBS = -lrt 
INC = -I ../../../util/seqan-1.3.1/

all: learn alignment_local

learn: learn.h learn.cc
	$(CC) $(CFLAGS) $(LIBS) $(INC) learn.cc -o learn

alignment_local: alignment_local.cpp
	$(CC) $(CFLAGS) $(LIBS) $(INC) alignment_local.cpp -o alignment_local 

clean:
	rm -rfv learn alignment_local

.PHONY: clean
