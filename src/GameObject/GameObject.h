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
        void draw(sf::RenderWindow& window);
        void handleEvents();
        template <typename T>
        T* getComponent();
};