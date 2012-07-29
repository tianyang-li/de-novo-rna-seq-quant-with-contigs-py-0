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

#include <cstdio>
#include <cstdlib>

#include <pthread.h>

#include <seqan/align.h>

#include "sw_align_0.h"

namespace sw_align_0 {

void SingleReadContigPairSWCPP(std::vector<SingleSeq> *reads,
		std::vector<SingleSeq> *contigs, std::vector<SingleSWAlign> *aligns) {
	_SingleReadContigPairSWCPP(*reads, *contigs, *aligns);
}

void _SingleReadContigPairSWCPP(std::vector<SingleSeq> &reads,
		std::vector<SingleSeq> &contigs, std::vector<SingleSWAlign> &aligns) {

}

}
