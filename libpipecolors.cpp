#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>

#include <string>
#include <map>
#include <regex>
#include <termcap.h>
#include "pipecolors.h"

#define C_DEFAULT      0
#define C_BOLD         1
#define C_ITALIC       3
#define C_UNDERLINE    4
#define C_INVERT       7

#define C_B0           "\033[1m"
#define C_B1           "\033[0m"

#define C_FG_BLACK     "\033[0;30m"
#define C_FG_RED       "\033[0;31m"
#define C_FG_GREEN     "\033[0;32m"
#define C_FG_YELLOW    "\033[0;33m"
#define C_FG_BLUE      "\033[0;34m"
#define C_FG_MAGENTA   "\033[0;35m"
#define C_FG_CYAN      "\033[0;36m"
#define C_FG_GRAY      "\033[0;37m"
#define C_FG_DEFAULT   "\033[0;39m"


#define C_FG_GRAY_D    "\033[0;90m"
#define C_FG_RED_L     "\033[0;91m"
#define C_FG_GREEN_L   "\033[0;92m"
#define C_FG_YELLOW_L  "\033[0;93m"
#define C_FG_BLUE_L    "\033[0;94m"
#define C_FG_MAGENTA_L "\033[0;95m"
#define C_FG_CYAN_L    "\033[0;96m"
#define C_FG_WHITE     "\033[0;97m"

#define C_BG_NONE      ""
#define C_BG_RED       "\033[1;41m"
#define C_BG_GREEN     "\033[1;42m"
#define C_BG_BLUE      "\033[1;44m"
#define C_BG_DEFAULT   "\033[1;49m"

 std::map<std::string, std::string> getColors() {
  std::map<std::string, std::string> colors;
  colors["|30"] = C_B0;
  colors["|31"] = C_B1;
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

  return colors;
}

bool has_colors(void) {
  char buffer[1024];
  int c;

  tgetent(buffer, getenv("TERM"));
  c = tgetnum("Co");

  if(c > 0 || c == -1) {
    return true;
  } else {
    return false;
  }
}

void cprintf( const char * format, ... ) {

  char buffer[256];
  std::map<std::string, std::string> colors;

  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  std::string text(buffer), s(buffer);
  va_end(args);
  std::size_t index;

  std::smatch matches;
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

int main(void) {
  cprintf("\n%s\n\n", "|01P|02i|03p|04e|05c|06ol|07o|08r|09s |10l|11i|12b|13r|14a|15r|14y |130|12.|111|07");
  return 0;
}
