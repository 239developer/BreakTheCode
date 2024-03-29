#include "Loader.h"

void Loader::loadSprite(string name)
{
    std::string texturePath = "../assets/textures/tiles/" + name + ".png";
    sf::Texture* texture = new sf::Texture();
    sf::Sprite* sprite;
    try
    {
        texture->loadFromFile(texturePath);
        std::cout << "Loaded texture: [" << texturePath << "]\n";
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
    }
    catch(const std::exception& e)
    {
        
    }
    return sprite;
}