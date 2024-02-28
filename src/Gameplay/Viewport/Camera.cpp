#include "Camera.h"

sf::RenderWindow Camera::window;
sf::Vector2f Camera::position = *(new sf::Vector2f(0.0, 0.0));

void Camera::translate(sf::Vector2f displacement)
{
    position += displacement;
}