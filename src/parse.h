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

  char * linePointer = new char[line.size() + 1];
  std::copy(line.begin(), line.end(), linePointer);
  linePointer[line.size()] = '\0';

  char * sbstrng = std::strtok(linePointer, " ");
  while(sbstrng != NULL) {
    ret.push(sbstrng);
    sbstrng = std::strtok(NULL, " ");
  }
  delete[] linePointer;
  return ret;
}

#endif
