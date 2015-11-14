#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <queue>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include "isConnector.h"

std::queue<std::string> parse (std::string line) {
  std::queue<std::string> ret;

  for (unsigned c = 0; c < line.size(); c++) {
    if (line.at(c) == '#') {
      line.erase(c, line.size() - 1);
    }
  }

  char * linePointer = new char[line.size() + 1];
  std::copy(line.begin(), line.end(), linePointer);
  linePointer[line.size()] = '\0';

  bool bracStart = false;
  char * sbstrng = std::strtok(linePointer, " ");
  while(sbstrng != NULL) {
    if (*sbstrng == '[') {
      ret.push("test");
      bracStart = true;
    }
    else if (bracStart && isConnector(sbstrng)) {
      //error stuff
      std::cout << "missing ']'" << std::endl;
      exit(1);
    }
    else if (bracStart && *sbstrng == ']')
      bracStart = false;
    else
      ret.push(sbstrng);
    sbstrng = std::strtok(NULL, " ");
  }
  delete[] linePointer;
  return ret;
}

#endif
