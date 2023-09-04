#pragma once
#include "ECS/System.h"

class Setup : public System {
  public:
    virtual void run() = 0;
};