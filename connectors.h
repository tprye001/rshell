#ifndef CONNECTORS_H
#define CONNECTORS_H

#include "ABC.h"

class connectors : private ABC {
  private:
    bool check;
  public:
    virtual bool compare();
};

#endif
