#include "ObjectLoader.h"
#include "../GameObject/SpriteComponent.h"
#include <iostream>

void ObjectLoader::loadSprite(GameObject* parent, std::string line)
{
    SpriteComponent* component = new SpriteComponent();
    std::string texturePath = line.substr(0, line.find_first_of(" "));
    sf::Texture* texture = loadTexture(texturePath);
    try
    {
        // texture->loadFromFile("../assets/textures/" + texturePath);
        // std::cout << "Loaded texture: [" << texturePath << "]\n";
        sf::Sprite* sprite = new sf::Sprite();
        sprite->setTexture(*texture);

        std::vector<float> v = extractCoordinates(line.substr(line.find_first_of(" "), std::string::npos), 3);   // extracts 4 coordinates representing:
        const sf::Vector2f pos(v[0], v[1]); //position
        sprite->setPosition(pos);
        sprite->setScale(v[2], v[3]); //and scale

        component->setSprite(sprite, texture);
        parent->addComponent(component);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}