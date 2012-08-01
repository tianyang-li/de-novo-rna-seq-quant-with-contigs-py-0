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

class _SingleSeq {
public:
	_SingleSeq() {
	}

	_SingleSeq(SingleSeq const &x) :
			id(x.id), seq(x.seq) {
	}

	_SingleSeq(std::string const &id_in,
			seqan::String<seqan::Dna> const &seq_in) :
			id(id_in), seq(seq_in) {
	}

	_SingleSeq(_SingleSeq const &x) :
			id(x.id), seq(x.seq) {
	}

	inline _SingleSeq &operator=(_SingleSeq const &x) {
		if (this != &x) {
			id = x.id;
			seq = x.seq;
		}
		return *this;
	}

	std::string id;
	seqan::String<seqan::Dna> seq;
};

inline void DoSingleAlign(_SingleSeq const &a, _SingleSeq const &b,
		std::vector<SingleAlign> &aligns) {
	seqan::String<seqan::Dna> a_rc = a.seq;
	seqan::reverseComplement(a_rc);
}

inline void ConvertSingleSeqVector(std::vector<SingleSeq> const &contigs,
		std::vector<_SingleSeq> &contigs_) {
	for (std::vector<SingleSeq>::const_iterator i = contigs.begin();
			i != contigs.end(); ++i) {
		contigs_.push_back(_SingleSeq(*i));
	}
}

}

#endif // SEQ_ALIGN_0_SUP1_H_
