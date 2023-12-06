#pragma once
class GameObject;

class Component
{
    protected:
        GameObject* parent = nullptr;
    public:
        Component (GameObject* p);
        virtual ~Component();
        GameObject* getParent();
};