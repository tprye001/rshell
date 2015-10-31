#ifndef CONNECTORS_H
#define CONNECTORS_H

#include "ABC.h"
#include <string>

class Connector : private ABC {
  private:
    std::string type;
  public:
    Connector (std::string t) : type(t) { }
    virtual bool execute();
};

#endif
