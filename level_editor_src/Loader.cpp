#include "Loader.h"
#include <iostream>

sf::Texture* Loader::loadTexture(std::string name)
{
    std::string texturePath = "../assets/textures/" + name + ".png";
    sf::Texture* texture = new sf::Texture();
    try
    {
        texture->loadFromFile(texturePath);
        std::cout << "Loaded texture: [" << texturePath << "]\n";
    }
    catch(const std::exception& e)
    {
        
    }
    return texture;
}