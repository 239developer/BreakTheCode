#pragma once
#include <SFML/Graphics.hpp>
#include "../../GameObject/GameObject.h"

class Transform : public Component
{
    public:
        using Component::Component;
        sf::Vector2f position = *(new sf::Vector2f(0.0, 0.0));
        void translate(sf::Vector2f);
        void draw() override;
};