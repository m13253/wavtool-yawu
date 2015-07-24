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

#include "cmdline_parser.hpp"
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <libwintf8/termio.h>
#include <libwintf8/u8str.h>
#include "option_manager.hpp"

namespace YAWU {

CmdlineParser::CmdlineParser(OptionManager &option_manager) : 
    option_manager(option_manager) {
}

void CmdlineParser::parse_argv(const std::vector<WTF8::u8string> &argv) const {
    if(argv.size() >= 5) {
        log_argv(argv);
        analyze_argv(argv);
    } else {
        print_help(argv[0]);
        std::exit(argv.size() == 1 ? 0 : 1);
    }
}

void CmdlineParser::print_help(const WTF8::u8string &argv0) {
    WTF8::cerr << "Usage: "
               << argv0
               << " <output file> <input file> <STP> <note length> [<p1> <p2> <p3> <v1> <v2> <v3> [<v4> <overlap> <p4> [<p5> <v5>]]]"
               << std::endl << std::endl;
}

void CmdlineParser::log_argv(const std::vector<WTF8::u8string> &argv) {
    WTF8::clog << "Args: ";
    bool first = true;
    for(const auto &argi : argv) {
        if(first) {
            first = false;
        } else {
            WTF8::clog << ' ';
        }
        if(argi.size() != 0 && argi.find(' ') == argi.npos) {
            WTF8::clog << argi;
        } else {
            WTF8::clog << '"' << argi << '"';
        }
    }
    WTF8::clog << std::endl;
}

void CmdlineParser::analyze_argv(const std::vector<WTF8::u8string> &argv) const {
}


}

