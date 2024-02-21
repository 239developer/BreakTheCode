#include "Transform.h"
#include "../../GameObject/SpriteComponent.h"
#include "../Viewport/Camera.h"
#include <iostream>

void Transform::translate(sf::Vector2f displacement)
{
    std::cout << position.x << " " << position.y << "\n";
    position += displacement;
}

void Transform::draw()
{
    SpriteComponent* sc = parent->getComponent<SpriteComponent>();
    if(sc)
    {
        sc->getSprite()->setPosition(position - Camera::position);
    }
}