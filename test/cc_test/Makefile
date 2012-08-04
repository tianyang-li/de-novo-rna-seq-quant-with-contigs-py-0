CC = g++
CFLAGS = -W -Wall -Wno-long-long -pedantic -Wno-variadic-macros -ggdb
LIBS = -lrt
INC = -I ../../util/seqan-1.3.1/

all: test1

test1: test1.cc test1.h seq_align_0.a
	$(CC) $(CFLAGS) $(LIBS) $(INC) \
	../../util/_seq_align_0_lib/seq_align_0.a  test1.cc -o test1

seq_align_0.a:	
	cd ../../util/_seq_align_0_lib/ && $(MAKE)

clean:
	rm -rfv *.o test1

.PHONY: clean seq_align_0.a
	