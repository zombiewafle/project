#pragma once

class Scene;  

class System {
public:
    System(Scene* s = nullptr) : scene(s) {}

    void setScene(Scene& s) {
        scene = &s;
    }

    Scene* getScene() const {
        return scene;
    }

    virtual void update(float dt) = 0;
    virtual void render() = 0;

protected:
    Scene* scene = nullptr;
};
