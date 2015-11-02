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
      line.erase(c, line.size() - c);
    }
  }

  const char * lineData = line.data();
  char * sbstrng = std::strtok(lineData, " ");
  while(sbstrng != NULL) {
    ret.push(substrng);
    sbstrng = std::strtok(NULL, " ");
  }
}

#endif
