#pragma once

#include <SDL2/SDL.h>
#include "ECS/System.h"

class Render : public System {
  public:
    virtual void run(SDL_Renderer* renderer) = 0;
};