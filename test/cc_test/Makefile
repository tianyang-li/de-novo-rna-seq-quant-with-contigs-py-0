CC = g++
CFLAGS = -W -Wall -Wno-long-long -pedantic -Wno-variadic-macros -ggdb
LIBS = -lrt
INC = -I ../../../util/seqan-1.3.1/

all: test1

test1: test1.cc test1.h
	$(CC) $(CFLAGS) $(LIBS) $(INC) test1.cc -o test1

clean:
	rm -rfv *.o test1

.PHONY: clean
	