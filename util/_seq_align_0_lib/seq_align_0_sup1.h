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
#include <cstddef>

#include <seqan.h>
#include <seqan/align.h>

#include "seq_align_0.h"

namespace seq_align_0 {

inline bool Do2StringSW(std::string const &a, std::string const &b,
		seqan::Align<seqan::String<seqan::Dna> > &align,
		seqan::Score<int> const &score,
		int score_th = 10 /* threshold for SW score */) {
	seqan::appendValue(seqan::rows(align), a);
	seqan::appendValue(seqan::rows(align), b);
	int sw_score = seqan::localAlignment(align, score, seqan::SmithWaterman());
	if (sw_score > score_th) {
		return true;
	} else {
		return false;
	}
}

inline bool End2AlignRelativePos(size_t seq_len, size_t align_start,
		size_t align_end, float ratio = 0.15) {
	// return true if the end or start of the sequence
	// is within ratio * seq_len of
	// the start or the end of the alignment
	size_t flank_len = ratio * seq_len;
	if (flank_len < align_start && align_end + flank_len < seq_len) {
		return false;
	}
	return true;
}

inline bool Keep2StringAlign(std::string const &a_seq, std::string const &b_seq,
		std::vector<SingleAlign> &aligns,
		seqan::Align<seqan::String<seqan::Dna> > &align, bool strand_dir) {
	// bool strand_dir
	// true: a+b+
	// false: a-b+
	size_t a_start = seqan::clippedBeginPosition(seqan::row(align, 0));
	size_t a_end = seqan::clippedEndPosition(seqan::row(align, 0));
	size_t b_start = seqan::clippedBeginPosition(seqan::row(align, 1));
	size_t b_end = seqan::clippedEndPosition(seqan::row(align, 1));
	if (!End2AlignRelativePos(a_seq.length(), a_start, a_end)
			and !End2AlignRelativePos(b_seq.length(), b_start, b_end)) {
		return false;
	}
	return true;
}

inline void DoSingleSWAlign(SingleSeq const &a, SingleSeq const &b,
		std::vector<SingleAlign> &aligns) {
	seqan::Score<int> score(1, -2, -3, -4);

	seqan::Align<seqan::String<seqan::Dna> > align_pp;
	seqan::LocalAlignmentFinder<> finder_pp(align_pp);

	// 10 is the score when there are exactly 10 overlapping
	// matches
	if (Do2StringSW(a.seq, b.seq, align_pp, score)) {
		Keep2StringAlign(a.seq, b.seq, aligns, align_pp, true);
	}

	std::string a_rc = a.seq;
	seqan::reverseComplement(a_rc);
	seqan::Align<seqan::String<seqan::Dna> > align_mp;
	seqan::LocalAlignmentFinder<> finder_mp(align_mp);

	// 10 is the score when there are exactly 10 overlapping
	// matches
	if (Do2StringSW(a_rc, b.seq, align_mp, score)) {
		Keep2StringAlign(a_rc, b.seq, aligns, align_mp, false);
	}

}

inline void _SingleReadContigPairCPP(std::vector<SingleSeq> &reads,
		std::vector<SingleSeq> &contigs, std::vector<SingleAlign> &aligns) {

}

} // namespace seq_align_0

#endif // SEQ_ALIGN_0_SUP1_H_
