// Tianyang Li 2012
// tmy1018@gmail.com

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "learn.h"

int main(int argc, char **argv) {
	seqan::String<seqan::Dna> s1 = "ACcgtACGT";
	std::cout << s1 << std::endl;
	seqan::reverseComplement(s1);
	std::cout << s1 << std::endl;
	std::vector<seqan::String<seqan::Dna> > v1;
	v1.push_back(s1);
	std::cout << v1[0] << std::endl;
	seqan::reverseComplement(v1[0]);
	std::cout << v1[0] << std::endl;
	return 0;
}

