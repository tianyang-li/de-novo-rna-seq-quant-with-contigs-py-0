// Tianyang Li 2012
// tmy1018@gmail.com

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "learn.h"

int main(int argc, char **argv) {
	std::string s2 = "tttatttttt";
	std::cout << s2 << std::endl;
	seqan::reverseComplement(s2);
	std::cout << s2 << std::endl;
	return 0;
}

