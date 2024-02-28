#include "SpriteComponent.h"
#include "../Gameplay/Viewport/Camera.h"
#include "../Gameplay/Engine/Transform.h"

void SpriteComponent::setSprite(sf::Sprite* s, sf::Texture* t)
{
    texture = t;
    sprite = s;
}

sf::Sprite* SpriteComponent::getSprite()
{
    return sprite;
}

sf::Texture* SpriteComponent::getTexture()
{
    return texture;
}

void SpriteComponent::draw()
{
    Transform* transform = parent->getComponent<Transform>();
    if(transform)
    {    
        sprite->setPosition(transform->position - Camera::position);
    }

    Camera::window.draw(*sprite);
}
