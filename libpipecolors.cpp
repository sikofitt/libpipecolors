/*
 * libpipecolors: linux color code library
 *
 * Authors:
 * Eric Wheeler <eric@ericwheeler.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef PC_REMOVE_INVALID
#define PC_REMOVE_INVALID false
#endif

#include <cstdio>
#include <iostream>
#include <string>
#include <stdarg.h>
#include <map>
#include <boost/regex.hpp>
#include "pipecolors.h"

namespace pipecolors {

  std::map<std::string, std::string> colors;

   std::map<std::string, std::string> getColors() {
    std::map<std::string, std::string> colors;
    colors["|00"] = "\x1b[0;30m"; // FG_BLACK;
    colors["|01"] = "\x1b[0;34m"; // FG_BLUE;
    colors["|02"] = "\x1b[0;32m"; // FG_GREEN;
    colors["|03"] = "\x1b[0;36m"; // FG_CYAN;
    colors["|04"] = "\x1b[0;31m"; // FG_RED;
    colors["|05"] = "\x1b[0;35m"; // FG_MAGENTA;
    colors["|06"] = "\x1b[0;33m"; // FG_YELLOW;
    colors["|07"] = "\x1b[0;37m"; // FG_GRAY;
    colors["|08"] = "\x1b[0;90m"; // FG_GRAY_D;
    colors["|09"] = "\x1b[0;94m"; // FG_BLUE_L;
    colors["|10"] = "\x1b[0;92m"; // FG_GREEN_L;
    colors["|11"] = "\x1b[0;96m"; // FG_CYAN_L;
    colors["|12"] = "\x1b[0;91m"; // FG_RED_L;
    colors["|13"] = "\x1b[0;95m"; // FG_MAGENTA_L;
    colors["|14"] = "\x1b[0;93m"; // FG_YELLOW_L;
    colors["|15"] = "\x1b[0;97m"; // FG_WHITE;
    colors["|16"] = "\x1b[1;40m"; // BG_DEFAULT;
    colors["|17"] = "\x1b[1;44m"; // BG_BLUE;
    colors["|18"] = "\x1b[1;42m"; // BG_GREEN;
    colors["|19"] = "\x1b[1;46m"; // BG_CYAN;
    colors["|20"] = "\x1b[1;41m"; // BG_RED;
    colors["|21"] = "\x1b[1;45m"; // BG_MAGENTA;
    colors["|22"] = "\x1b[1;43m"; // BG_YELLOW;
    colors["|23"] = "\x1b[1;47m"; // BG_WHITE;
    colors["|30"] = "\x1b[1m";    // Bold ON
    colors["|31"] = "\x1b[0m";    // Bold OFF
    colors["|39"] = "\x1b[0;39m"; // FG_DEFAULT
    return colors;
  }
  bool has_colors(void) {
    return isatty(fileno(stdout));
  }

  std::string replace_colors( std::string s) {

    using namespace boost;

    regex re( "(\\|\\d\\d)" );
    match_results<std::string::const_iterator> match;
    match_flag_type flags = boost::match_default;

    std::string::const_iterator start, end;
    start = s.begin();
    end = s.end();

    colors = getColors();

    while(regex_search(start, end, match, re, flags))
    {
      if(colors[match[0]].empty() && PC_REMOVE_INVALID == false) goto skip;

      if(has_colors() && !colors[match[0]].empty()) {
        s.replace(s.find(match[0]), match[0].length(), colors[match[0]]);
      } else {
        s.erase(s.find(match[0]), match[0].length());
      }

      skip:;
      start = match[0].second;
      flags |= boost::match_prev_avail | boost::match_not_bob;
    }
    return(s);
  }

  int pcprintf( const char * fmt, ...)
  {
    char * buffer;
    va_list args;
    int ret;

    va_start(args, fmt);
    ret = vasprintf(&buffer, fmt, args);
    va_end(args);
    if(ret == -1) {
        free(buffer);
        exit(EXIT_FAILURE);
    }

    std::string s(buffer);
    free(buffer);

    std::cout << replace_colors(s);

    return(ret);

  }
} // namespace
