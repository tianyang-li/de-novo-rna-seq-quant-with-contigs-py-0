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

#ifndef SEQ_ALIGN_0_SUP1_H_
#define SEQ_ALIGN_0_SUP1_H_

#include <string>
#include <vector>

#include <seqan.h>

#include "seq_align_0.h"

namespace seq_align_0 {

inline int Do2StringSW(std::string const &a, std::string const &b,
		seqan::Align<seqan::String<seqan::Dna> > &align,
		seqan::Score<int> const &score, seqan::LocalAlignmentFinder<>) {
	seqan::appendValue(seqan::rows(align), a);
	seqan::appendValue(seqan::rows(align), b);
	return seqan::localAlignment(align, score, finder, seqan::SmithWaterman());
}

inline void DoSingleSWAlign(SingleSeq const &a, SingleSeq const &b,
		std::vector<SingleAlign> &aligns) {
	// phrep
	seqan::Score<int> score(1, -2, -4, -3);

	// pcap
	// seqan::Score<int> score(2, -5, -6, -2);

	seqan::Align<seqan::String<seqan::Dna> > align_pp;
	seqan::LocalAlignmentFinder<> finder_pp(align_pp);
	Do2StringSW(a.seq, b.seq, align_pp, score, finder_pp);

	std::string a_rc = a.seq;
	seqan::reverseComplement(a_rc);
	seqan::Align<seqan::String<seqan::Dna> > align_mp;
	seqan::LocalAlignmentFinder<> finder_mp(align_mp);
	Do2StringSW(a_rc, b.seq, align_mp, score, finder_mp);

}

}

#endif // SEQ_ALIGN_0_SUP1_H_
