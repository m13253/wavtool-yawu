/*
    wavtool-yawu
    Copyright (C) 2015 StarBrilliant <m13253@hotmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program.  If not,
    see <http://www.gnu.org/licenses/>.
*/

#include "pcm_merger.hpp"
#include "option_manager.hpp"
#include "pcm_file.hpp"

namespace YAWU {

struct PCMMerger::Private {
    PCMFile input_file;
    PCMFile output_file;
};

PCMMerger::PCMMerger(OptionManager &option_manager) :
    option_manager(option_manager) {
}

PCMMerger::~PCMMerger() {
}

void PCMMerger::prepare() {
}

}

