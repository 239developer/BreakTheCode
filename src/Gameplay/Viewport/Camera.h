#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
    public:
        static sf::RenderWindow window;
        static sf::Vector2f position;
        static void translate(sf::Vector2f);
        Camera() = delete;
};