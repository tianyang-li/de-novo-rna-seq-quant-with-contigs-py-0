// Tianyang Li 2012
// tmy1018@gmail.com

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "learn.h"

int main(int argc, char **argv) {
	seqan::String<seqan::Dna> s1 = "ACcgtACGT";
	std::cout << s1 << std::endl;
	seqan::reverseComplement(s1);
	std::cout << s1 << std::endl;
	return 0;
}

