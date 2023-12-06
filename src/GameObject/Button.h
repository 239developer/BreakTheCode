#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

class Button : public Component
{
    protected:
        sf::IntRect bounds;
    public:
        using Component::Component;
        virtual void onPress();
        bool isPressed();
};