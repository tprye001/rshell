#ifndef COMMANDS_H
#define COMMANDS_H

#include "ABC.h"
#include <vector>
#include <string>

class Commands : private ABC {
  private:
    std::string type;
    std::vector<std::string> arg;
  public:
    Commands (std::string t, std::vector<std::string> a) : type(t), arg(a) { }
    bool execute();
};

#endif
