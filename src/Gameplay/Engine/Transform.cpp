#include "Transform.h"
#include <iostream>

void Transform::translate(sf::Vector2f displacement)
{
    // std::cout << position.x << " " << position.y << "\n";
    position += displacement;
}