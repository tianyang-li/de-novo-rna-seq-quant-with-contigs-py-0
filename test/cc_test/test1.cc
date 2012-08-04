// Tianyang Li 2012
// tmy1018@gmail.com

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include <seqan.h>

#include "../../util/_seq_align_0_lib/seq_align_0_sup1.h"
#include "../../util/_seq_align_0_lib/seq_align_0.h"

#include "test1.h"

int main(int argc, char **argv) {
	std::vector<seq_align_0::SingleAlign> aligns;

	std::string s0 = "GAGAGCGAGCGCTCTCGTTCGGTGGAGAAACATTTCGTTAACTTGGCGTG"
			"ATTTTCACTAGGCTGAGTGGCTAGCTACTATGTTCTGCAACCTTTAGAGC";
	std::string id0 = "0";

	std::string s1 = "ATTTTCACTAGGCTGAGTGGCTAGCTACTATGTTCTGCAACCTTTAGAGC"
			"TCATACTCAAACAAATCCTCCTGTTAGCAGGATTTCACACGCGTAAGTGG";
	std::string id1 = "1";

	seqan::Align<seqan::String<seqan::Dna> > align;

	int score_th = 10;
	int score = seq_align_0::Do2StringSW(s0, s1, align,
			seqan::Score<int>(1, -2, -3, -4), score_th) + score_th;

	printf("#################################\n");

	std::cout << score << std::endl;

	printf("#################################\n");

	std::cout << align << std::endl;

	printf("#################################\n");

	seq_align_0::Keep2StringAlign(id0, s0, id1, s1, aligns, align, true);

	if (!aligns.empty()) {
		for (std::vector<seq_align_0::SingleAlign>::const_iterator i =
				aligns.begin(); i != aligns.end(); ++i) {
			std::cout << i->s1_strand << " " << i->s1_id << ", " << i->s2_strand
					<< " " << i->s2_id << std::endl;
			std::cout << i->align_str << std::endl;
		}
	}

	return 0;
}
