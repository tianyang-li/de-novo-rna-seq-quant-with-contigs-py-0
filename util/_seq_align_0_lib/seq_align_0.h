/*
 * Tianyang Li 2012
 * tmy1018@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SEQ_ALIGN_0_H_
#define SEQ_ALIGN_0_H_

#include <string>
#include <vector>

namespace seq_align_0 {

class SingleAlign {
public:
	SingleAlign(std::string s1_id_in, std::string s2_id_in) :
			s1_id(s1_id_in), s2_id(s2_id_in) {
		SetStrandNull();
	}

	SingleAlign(SingleAlign const &x) :
			s1_id(x.s1_id), s1_start(x.s1_start), s1_end(x.s1_end), s2_id(
					x.s2_id), s2_start(x.s2_start), s2_end(x.s2_end), align_str(
					x.align_str) {
		CpStrand(x);
		SetStrandNull();
	}

	SingleAlign() {
		SetStrandNull();
	}

	inline SingleAlign &operator=(SingleAlign const &x) {
		if (this != &x) {
			s1_id = x.s1_id;
			s1_start = x.s1_start;
			s1_end = x.s1_end;
			s2_id = x.s2_id;
			s2_start = x.s2_start;
			s2_end = x.s2_end;
			align_str = x.align_str;
			CpStrand(x);
		}
		return *this;
	}

	std::string s1_id;
	int s1_start, s1_end; // python convention
	char s1_strand[2]; // '+' 5' -> 3'; '-' reverse_complement(5' -> 3')

	std::string s2_id;
	int s2_start, s2_end; // python convention
	char s2_strand[2]; // '+' 5' -> 3'; '-' reverse_complement(5' -> 3')

	// TODO: modify align_str if too much memory is used
	std::string align_str;
	// format
	// M - match
	// [ - gap in s1
	// ] - gap in s2
	// % - match

private:
	void SetStrandNull() {
		s1_strand[1] = '\0';
		s2_strand[1] = '\0';
	}

	void CpStrand(SingleAlign const &x) {
		s1_strand[0] = x.s1_strand[0];
		s2_strand[0] = x.s2_strand[0];
	}
};

class SingleSeq {
public:
	SingleSeq(std::string id_in, std::string seq_in) :
			id(id_in), seq(seq_in) {
	}

	SingleSeq(SingleSeq const &x) :
			id(x.id), seq(x.seq) {
	}

	SingleSeq() {
	}

	inline SingleSeq &operator=(SingleSeq const &x) {
		if (this != &x) {
			id = x.id;
			seq = x.seq;
		}
		return *this;
	}

	std::string id; // name
	std::string seq; // 'A' 'C' 'G' 'T' only
};

void SingleReadContigPairCPP(std::vector<SingleSeq> *reads,
		std::vector<SingleSeq> *contigs, std::vector<SingleAlign> *aligns);

} // namespace seq_align_0

#endif  // SEQ_ALIGN_0_H_
