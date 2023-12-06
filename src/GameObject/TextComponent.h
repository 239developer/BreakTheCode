#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class TextComponent : public Component
{
    private:
        sf::Font* font;
        sf::Text* text;
    public:
        using Component::Component;
        void setText(sf::Text*, sf::Font*);
        sf::Text* getText();
};