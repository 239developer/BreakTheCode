#pragma once
#include <string>
class SceneManager;
class GameObject;

class Component
{
    protected:
        GameObject* parent = nullptr;
    public:
        Component();
        virtual ~Component();
        virtual void setParent(GameObject* p);
        GameObject* getParent();
        virtual void draw() {}
        virtual void update() {}
};