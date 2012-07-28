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

#include <seqan/align.h>

namespace sw_align_0 {

class SingleSWAlgin {
public:
	std::string s1_id;
	int s1_start, s1_end;

	std::string s2_id;
	int s2_start, s2_end;

	std::string aling_str;
};

class SingleAlignSeq {
public:
	SingleAlignSeq(std::string seq_in, std::string id_in) :
			seq(seq_in), id(id_in) {
	}

	std::string seq; // 'A' 'C' 'G' 'T' only
	std::string id; // name
	std::vector<SingleSWAlgin> aligns;
};

void SingleReadContigPairSWCPP(std::vector<SingleAlignSeq> *reads,
		std::vector<SingleAlignSeq> *contigs);

void _SingleReadContigPairSWCPP(std::vector<SingleAlignSeq> &reads,
		std::vector<SingleAlignSeq> &contigs);

}

#endif  // SW_ALIGN_0_H_
