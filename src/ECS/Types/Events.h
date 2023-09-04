#pragma once

#include <SDL2/SDL.h>
#include "ECS/System.h"

class Event : public System {
  public:
    virtual void run(SDL_Event event) = 0;
};