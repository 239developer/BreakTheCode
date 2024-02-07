#include "ObjectLoader.h"
#include "../GameObject/SpriteComponent.h"
#include <iostream>

void ObjectLoader::loadSprite(GameObject* parent, std::string line)
{
    SpriteComponent* component = new SpriteComponent();
    std::string texturePath = line.substr(0, line.find_first_of(" "));
    sf::Texture* texture = new sf::Texture();
    try
    {
        texture->loadFromFile("../assets/textures/" + texturePath);
        std::cout << "Loaded texture: [" << texturePath << "]\n";
        sf::Sprite* sprite = new sf::Sprite();
        sprite->setTexture(*texture);

        std::vector<float> v = extractCoordinates(line.substr(line.find_first_of(" "), std::string::npos), 0, 1);   // extracts just 2 coordinates representing position
        const sf::Vector2f pos(v[0], v[1]);

        sprite->setPosition(pos);

        component->setSprite(sprite, texture);
        parent->addComponent(component);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}