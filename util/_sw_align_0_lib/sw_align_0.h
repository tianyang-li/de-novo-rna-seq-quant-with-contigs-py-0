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

#ifndef SW_ALIGN_0_H_
#define SW_ALIGN_0_H_

#include <string>
#include <vector>

namespace sw_align_0 {

class SingleSWAlign {
public:
	SingleSWAlign(std::string s1_id_in, std::string s2_id_in) :
			s1_id(s1_id_in), s2_id(s2_id_in) {
	}

	SingleSWAlign(SingleSWAlign const &x) :
			s1_id(x.s1_id), s1_start(x.s1_start), s1_end(x.s1_end), s2_id(
					x.s2_id), s2_start(x.s2_start), s2_end(x.s2_end) {
	}

	SingleSWAlign() {
	}

	SingleSWAlign &operator=(SingleSWAlign const &x) {
		if (this != &x) {
			s1_id = x.s1_id;
			s1_start = x.s1_start;
			s1_end = x.s1_end;
			s2_id = x.s2_id;
			s2_start = x.s2_start;
			s2_end = x.s2_end;
		}
		return *this;
	}

	std::string s1_id;
	int s1_start, s1_end;

	std::string s2_id;
	int s2_start, s2_end;

	std::string align_str;
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

	SingleSeq &operator=(SingleSeq const &x) {
		if (this != &x) {
			id = x.id;
			seq = x.seq;
		}
		return *this;
	}

	std::string id; // name
	std::string seq; // 'A' 'C' 'G' 'T' only
};

void SingleReadContigPairSWCPP(std::vector<SingleSeq> *reads,
		std::vector<SingleSeq> *contigs, std::vector<SingleSWAlign> *aligns);

void _SingleReadContigPairSWCPP(std::vector<SingleSeq> &reads,
		std::vector<SingleSeq> &contigs, std::vector<SingleSWAlign> &aligns);

}

#endif  // SW_ALIGN_0_H_
