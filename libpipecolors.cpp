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

#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <map>
#include <regex>
//#include "libpipecolors.h"

namespace pipecolors {

#define C_DEFAULT      0
#define C_BOLD         1
#define C_ITALIC       3
#define C_UNDERLINE    4
#define C_INVERT       7

#define C_B0           "\x1b[1m"
#define C_B1           "\x1b[0m"

#define C_FG_BLACK     "\x1b[0;30m"
#define C_FG_RED       "\x1b[0;31m"
#define C_FG_GREEN     "\x1b[0;32m"
#define C_FG_YELLOW    "\x1b[0;33m"
#define C_FG_BLUE      "\x1b[0;34m"
#define C_FG_MAGENTA   "\x1b[0;35m"
#define C_FG_CYAN      "\x1b[0;36m"
#define C_FG_GRAY      "\x1b[0;37m"
#define C_FG_DEFAULT   "\x1b[0;39m"


#define C_FG_GRAY_D    "\x1b[0;90m"
#define C_FG_RED_L     "\x1b[0;91m"
#define C_FG_GREEN_L   "\x1b[0;92m"
#define C_FG_YELLOW_L  "\x1b[0;93m"
#define C_FG_BLUE_L    "\x1b[0;94m"
#define C_FG_MAGENTA_L "\x1b[0;95m"
#define C_FG_CYAN_L    "\x1b[0;96m"
#define C_FG_WHITE     "\x1b[0;97m"

#define C_BG_NONE      ""
#define C_BG_RED       "\x1b[1;41m"
#define C_BG_GREEN     "\x1b[1;42m"
#define C_BG_BLUE      "\x1b[1;44m"
#define C_BG_DEFAULT   "\x1b[1;49m"

 std::map<std::string, std::string> getColors() {
  std::map<std::string, std::string> colors;
  colors["|00"] = C_FG_BLACK;
  colors["|01"] = C_FG_BLUE;
  colors["|02"] = C_FG_GREEN;
  colors["|03"] = C_FG_CYAN;
  colors["|04"] = C_FG_RED;
  colors["|05"] = C_FG_MAGENTA;
  colors["|06"] = C_FG_YELLOW;
  colors["|07"] = C_FG_GRAY;
  colors["|08"] = C_FG_GRAY_D;
  colors["|09"] = C_FG_BLUE_L;
  colors["|10"] = C_FG_GREEN_L;
  colors["|11"] = C_FG_CYAN_L;
  colors["|12"] = C_FG_RED_L;
  colors["|13"] = C_FG_MAGENTA_L;
  colors["|14"] = C_FG_YELLOW_L;
  colors["|15"] = C_FG_WHITE;
  colors["|16"] = C_BG_DEFAULT; // C_BG_BLACK
  colors["|17"] = C_BG_BLUE;
  colors["|18"] = C_BG_GREEN;
  colors["|19"] = C_BG_BLUE; // C_BG_CYAN
  colors["|20"] = C_BG_RED;
  colors["|21"] = C_BG_RED; // C_BG_MAGENTA
  colors["|22"] = C_FG_WHITE; //C_BG_BROWN
  colors["|23"] = C_BG_DEFAULT; // C_BG_WHITE
  colors["|30"] = C_B0; //Bold OFF
  colors["|31"] = C_B1; // Bold ON
  return colors;
}

bool has_colors(void) {
  return isatty(fileno(stdout));
}

void pcprintf( const char * fmt, ... ) {

  char *buffer;
  std::map<std::string, std::string> colors;
  std::size_t index;
  std::smatch matches;

  va_list args;
  va_start(args, fmt);

  if(int size = vasprintf(&buffer, fmt, args) == -1) {
      free(buffer);
      exit(EXIT_FAILURE);
  }

  std::string text(buffer), s(buffer);
  va_end(args);
  free(buffer);

  std::regex reg ("(\\|\\d\\d)", std::regex_constants::ECMAScript | std::regex_constants::nosubs);

  colors = getColors();
  while (std::regex_search (text,matches,reg)) {
    for (auto x:matches) {
      while ((index = s.find(x)) != std::string::npos)
        s.replace(index, x.length(), colors[x]);
    }
    text = matches.suffix().str();
  }

  std::cout << s;

}
}
