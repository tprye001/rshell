#ifndef COMMANDS_H
#define COMMANDS_H

#include "ABC.h"
#include <vector>
#include <string>

class commands : private ABC {
  private:
    std::vector<std::string> arg;
  public:
    virtual bool execute();
};

#endif
