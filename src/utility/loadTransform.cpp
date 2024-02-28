#include "ObjectLoader.h"
#include "../Gameplay/Engine/Transform.h"

void ObjectLoader::loadTransform(GameObject* parent, std::string line)
{
    Transform* component = new Transform();

    std::vector<float> v = extractCoordinates(line.substr(line.find_first_of(" "), std::string::npos), 0, 1);  // extracts 2 coordinates:
    const sf::Vector2f pos(v[0], v[1]);          // 2 for position

    component->position = pos;

    parent->addComponent(component);
}