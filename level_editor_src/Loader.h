#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Loader
{
    public:
        static sf::Texture* loadTexture(std::string);
};