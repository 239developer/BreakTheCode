#include "Button.h"
#include "SpriteComponent.h"
#include "GameObject.h"
#include <iostream>

bool Button::isPressed()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition();
        sf::Vector2f pos(mousePos.x, mousePos.y);
        return bounds.contains(pos);
    }
    return false;
}

void Button::press()
{
    std::cout << "nothing here\n";
}

void Button::setParent(GameObject* p)
{
    Component::setParent(p);
    bounds = p->getComponent<SpriteComponent>()->getSprite()->getGlobalBounds();
}