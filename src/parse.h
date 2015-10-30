#include <string>
#include <queue>
#include "ABC.h"

std::queue<ABC> parse (std::string line) {
  std::queue<ABC> ret;
  for (int c = 0; c < line.size(); c++) {
    if (line.at(c) == '#')
      c = line.size();
    else if (line.at(c) == ';' || line.at(c) == ''
  }
}
