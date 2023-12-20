#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class SpriteComponent : public Component
{
    protected:
        sf::Texture* texture;
        sf::Sprite* sprite;
    public:
        using Component::Component;
        void setSprite(sf::Sprite*, sf::Texture*);
        sf::Sprite* getSprite();
        sf::Texture* getTexture();
};