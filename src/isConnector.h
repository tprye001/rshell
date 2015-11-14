#ifndef ISCON_H
#define ISCON_H

#include <string>
#include <vector>

/*returns true if s is a connector, false otherwise*/
bool isConnector(std::string s) {
  //vector of connectors
  std::vector<std::string> connectors;
  connectors.push_back(";");
  connectors.push_back("&&");
  connectors.push_back("||");

  for(unsigned c = 0; c < connectors.size(); c++) {
    if(connectors.at(c) == s)
      return true;
  }
  return false;
}
#endif

