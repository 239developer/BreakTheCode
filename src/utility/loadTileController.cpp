#include <iostream>
#include "ObjectLoader.h"
#include "../Gameplay/Player/TileController.h"

void ObjectLoader::loadTileController(GameObject* parent, std::string line)
{
    try
    {
        std::vector<float> v = extractCoordinates(line, 3); // size_x, size_y, displacement(x and y)
        sf::Vector2f displacement;
        displacement.x = v[2];
        displacement.y = v[3];
        TileController* component = new TileController(128, (int)v[0], (int)v[1], displacement);
        std::cout << "Loaded a TileController\n";
        parent->addComponent(component);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}