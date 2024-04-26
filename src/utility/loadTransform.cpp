#include "ObjectLoader.h"
#include "../Gameplay/Engine/Transform.h"
#include <iostream>

void ObjectLoader::loadTransform(GameObject* parent, std::string line)
{
    Transform* component = new Transform();

    std::vector<float> v = extractCoordinates(line.substr(line.find_first_of(" "), std::string::npos), 1);  // extracts 2 coordinates:
    sf::Vector2f pos(v[0], v[1]);          // 2 for position
    std::cout << "created a transform with x: " << v[0] << " y: " << v[1] << "\n";

    component->position = pos;

    parent->addComponent(component);
}