#include <iostream>
#include <string>
#include <cstddef>
#include <cstdio>

#include <seqan.h>

using namespace seqan;

int main() {
	std::string s1 = "CGCGGGGCATATATTTTTTTTTTTTA";
	std::string s2 = "ATTTATTTTTCTTTTTATATGCGGCCG";

	Align<String<Dna>, ArrayGaps> ali;

	appendValue(rows(ali), s1);
	appendValue(rows(ali), s2);

	localAlignment(ali, Score<int>(1, -2, -1, 0), SmithWaterman());

	std::cout << "#####################################" << std::endl;

	std::cout << ali << std::endl;

	std::cout << "#####################################" << std::endl;

	std::cout << length(row(ali, 0)) << std::endl;
	std::cout << length(row(ali, 1)) << std::endl;

	std::cout << "#####################################" << std::endl;

	Iterator<Row<Align<String<Dna>, ArrayGaps> >::Type>::Type s1_it = iter(
			row(ali, 0), 0);
	Iterator<Row<Align<String<Dna>, ArrayGaps> >::Type>::Type s2_it = iter(
			row(ali, 1), 0);

	size_t ali_len = length(row(ali, 0));
	for (size_t i = 0; i != ali_len; ++i) {
		if (!isGap(s1_it) && !isGap(s2_it)) {
			if (*s1_it == *s2_it) {
				printf("S");
			} else {
				printf("D");
			}
		} else {
			if (isGap(s1_it)) {
				printf("1");
			} else {
				printf("2");
			}
		}
		++s1_it;
		++s2_it;
	}
	printf("\n");

	return 0;
}
