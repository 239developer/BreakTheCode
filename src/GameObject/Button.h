#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

class Button : public Component
{
    protected:
        sf::FloatRect bounds;
    public:
        using Component::Component;
        bool isPressed();
        virtual void press();
        void setParent(GameObject* p) override;
};