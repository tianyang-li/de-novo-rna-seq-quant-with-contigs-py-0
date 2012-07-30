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

#include <pthread.h>

#include "seq_align_0_sup1.h"

namespace seq_align_0 {

void DoSingleGlocalAlign(_SingleSeq const &a, _SingleSeq const &b,
		std::vector<SingleAlign> &aligns) {
}

void ConvertSingleSeqVector(std::vector<SingleSeq> const &contigs,
		std::vector<_SingleSeq> &contigs_) {
	for (std::vector<SingleSeq>::const_iterator i = contigs.begin();
			i != contigs.end(); ++i) {
		contigs_.push_back(_SingleSeq(*i));
	}
}



}

