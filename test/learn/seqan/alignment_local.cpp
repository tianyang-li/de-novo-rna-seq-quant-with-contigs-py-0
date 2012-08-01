#include <iostream>
#include <seqan.h>
#include <string>

using namespace seqan;

int main() {
	std::string s1 = "CGCGGGGCATATATTTTTTTA";
	std::string s2 = "ATTTATTTTTTATATGCGGCCG";

	Align<String<Dna> > ali;

	appendValue(rows(ali), s1);
	appendValue(rows(ali), s2);

	std::cout << "Score = "
			<< localAlignment(ali, Score<int>(3, -3, -2, -2), SmithWaterman())
			<< std::endl;

	std::cout << ali;

	std::cout << "Aligns Seq1[" << clippedBeginPosition(row(ali, 0)) << ":"
			<< (clippedEndPosition(row(ali, 0)) - 1) << "]";

	std::cout << " and Seq2[" << clippedBeginPosition(row(ali, 1)) << ":"
			<< (clippedEndPosition(row(ali, 1)) - 1) << "]" << std::endl
			<< std::endl;

	return 0;
}
