#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "Game/Graphics/PixelShader.h"
#include "Game/Graphics/Texture.h"
#include "Game/Graphics/Tile.h"
#include "SDL2/SDL.h"

struct NameComponent {
  std::string name;
};

struct TransformComponent {
  glm::vec2 position;
};

struct SpeedComponent {
  glm::vec2 velocity;
};

struct SpriteComponent {
  Texture* texture = nullptr; 
  std::string textureName;    
  int xIndex = 0;
  int yIndex = 0;
  int size = 48;
  int animationFrames = 0;
  int animationDuration = 0;
  PixelShader shader = { nullptr, "" };
  Uint32 lastUpdate = 0;
};

struct TilemapComponent {
  int width = 1;  
  int height = 1; 
  int tileSize;
  std::vector<Tile> map;
};

struct CameraComponent {
  int viewportWidth;
  int viewportHeight;
  double zoom = 1.0;
};

struct WorldComponent {
  int width;
  int height;
};

struct ColliderComponent {
  int xo;
  int yo;
  int w;
  int h;
  SDL_Color debugColor = {255, 255, 255};
};
