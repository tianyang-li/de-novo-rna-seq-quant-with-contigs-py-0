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

class SWAlgin {
public:
};

class AlignSeq {
public:
	std::string seq; // 'A' 'C' 'G' 'T' only
	std::string id; // name
	std::vector<SWAlgin> aligns;
};

void ReadContigPairSW(std::vector<AlignSeq> *reads,
		std::vector<AlignSeq> *contigs);

void _ReadContigPairSW(std::vector<AlignSeq> &reads,
		std::vector<AlignSeq> &contigs);

}

#endif  // SW_ALIGN_0_H_
