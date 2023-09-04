#pragma once
#include "ECS/SystemTypes.h"

class Update : public System {
  public:
    virtual void run(float dT) = 0;
};