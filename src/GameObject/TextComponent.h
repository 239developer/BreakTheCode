#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class TextComponent : public Component
{
    protected:
        sf::Font* font;
        sf::Text* text;
    public:
        using Component::Component;
        virtual void setText(sf::Text*, sf::Font*);
        sf::Text* getText();
        virtual void draw() override;
};