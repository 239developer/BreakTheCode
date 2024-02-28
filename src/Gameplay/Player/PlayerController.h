#pragma once
#include "../../GameObject/GameObject.h"
#include "../Engine/Transform.h"

class PlayerController : public Component
{
    private:
        Transform* transform;
        sf::Vector2f* gridPosition = new sf::Vector2f(800.0, 120.0);
        sf::Vector2f* cellSize = new sf::Vector2f(60.0, 60.0);
        sf::Vector2i* gridSize = new sf::Vector2i(16, 12);
        sf::Vector2i* cell = new sf::Vector2i(0, 0);
    public:
        using Component::Component;
        virtual void setParent(GameObject*) override;
        void fixedUpdate();
};