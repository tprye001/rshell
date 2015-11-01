#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <queue>
#include <cstring>

std::queue<std::string> parse (std::string line) {
  std::queue<std::string> ret;

  for (int c = 0; c < line.size(); c++) {
    if (line.at(c) == '#') {
      c = line.size();
      str.erase(c, line.size() - c);
    }
  }

  char * sbstrng = strtok(line, " ");
  while(sbstrng != NULL) {
    ret.push(substrng);
    sbstrng = strtok(NULL, " ");
  }
}

#endif
