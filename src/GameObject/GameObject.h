#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Component.h"

class GameObject
{
    private:
        std::vector<Component*> components;
    public:
        std::string name = "GameObject";

        GameObject();
        void addComponent(Component * c);
        void draw();
        void update();

        template <typename T>
        inline T* getComponent()
        {
            T* result = nullptr;
            for(Component* c : components)
            {
                result = dynamic_cast<T*>(c);
                if(result)
                    break;
            }
            return result;
        }
};