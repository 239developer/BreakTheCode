#pragma once
#include "../../GameObject/Component.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Tile : public Component
{
    protected:
        int rotation = 0; // (rotation * pi / 2) radians (CCW)
        sf::Sprite* sprite;
    public:
        int x = 0;
        int y = 0;
        using Component::Component;
        void rotate(int);
        void setRotation(int);
        void setPosition(int, int);
        virtual void draw() override;
};