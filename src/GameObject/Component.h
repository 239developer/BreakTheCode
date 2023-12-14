#pragma once
#include <string>
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
};