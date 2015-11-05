#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <queue>
#include <cstring>

std::queue<std::string> parse (std::string line) {
  std::queue<std::string> ret;

  for (unsigned c = 0; c < line.size(); c++) {
    if (line.at(c) == '#') {
      c = line.size();
      line.erase(c, line.size() - c);
    }
  }

  char lineData = *line.data();
  char * linePointer = &lineData;
  char * sbstrng = std::strtok(linePointer, " ");
  while(sbstrng != NULL) {
    ret.push(sbstrng);
    sbstrng = std::strtok(NULL, " ");
  }
  return ret;
}

#endif
