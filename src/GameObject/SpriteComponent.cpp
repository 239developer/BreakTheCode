#include "SpriteComponent.h"

void SpriteComponent::setSprite(sf::Sprite* s, sf::Texture* t)
{
    texture = t;
    sprite = s;
}

sf::Sprite* SpriteComponent::getSprite()
{
    return sprite;
}