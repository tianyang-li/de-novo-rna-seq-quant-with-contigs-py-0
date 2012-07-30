CC = g++
CFLAGS = -W -Wall -Wno-long-long -pedantic -Wno-variadic-macros -ggdb
LIBS = -lrt
INC = -I ../../../util/seqan-1.3.1/

all: learn

learn: learn.h learn.cc
	$(CC) $(CFLAGS) $(LIBS) $(INC) learn.cc -o learn

clean:
	rm -rfv learn

.PHONY: clean
