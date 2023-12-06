#include "Button.h"

bool Button::isPressed()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i pos = sf::Mouse::getPosition();
        return bounds.contains(pos);
    }
    return false;
}