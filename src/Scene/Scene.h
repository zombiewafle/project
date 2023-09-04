#pragma once
#include "iostream"
#include "memory"
#include "vector"
#include "SDL2/SDL.h"
#include "string"
#include "entt/entt.hpp"

#include "ECS/SystemTypes/SetupSystem.h"
#include "ECS/SystemTypes/EventSystem.h"
#include "ECS/SystemTypes/UpdateSystem.h"
#include "ECS/SystemTypes/RenderSystem.h"

class Entity; 

class Scene {
    public:
        Scene(const std::string& name);
        ~Scene();

        Entity createEntity(const std::string& name = "NO NAME");

        void addSetupSystem(std::unique_ptr<SetupSystem> system);
        void addEventSystem(std::unique_ptr<EventSystem> system);
        void addUpdateSystem(std::unique_ptr<UpdateSystem> system);
        void addRenderSystem(std::unique_ptr<RenderSystem> system);

        void setup();
        void processEvents(SDL_Event event);
        void update(float dT);
        void render(SDL_Renderer* renderer);

    private:
        entt::registry registry;

        std::string name;

        std::vector<std::unique_ptr<SetupSystem>> setupSystems;
        std::vector<std::unique_ptr<EventSystem>> eventSystems;
        std::vector<std::unique_ptr<UpdateSystem>> updateSystems;
        std::vector<std::unique_ptr<RenderSystem>> renderSystems;

        Entity* world = nullptr;
        Entity* mainCamera = nullptr;
        Entity* player = nullptr;
};
