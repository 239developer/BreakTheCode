#include "ObjectLoader.h"
#include "../Gameplay/Player/PlayGrid.h"
#include <iostream>

void ObjectLoader::loadPlayGrid(GameObject* parent, std::vector<std::string> lines)
{
    PlayGrid* component = new PlayGrid();
    try
    {
        for(int i = 1; i < PlayGrid::tileTypeAmount + 1; i++)
        {
            sf::Texture* texture = new sf::Texture();
            texture->loadFromFile("../assets/textures/tiles/" + lines[i]);
            std::cout << "Loaded texture: [" << lines[i] << "]\n";
            component->addTexture(*texture);
        }
        std::vector<float> v = extractCoordinates(lines[0], 0, 1);
        component->setSize((int)v[0], (int)v[1]);

        for(int i = PlayGrid::tileTypeAmount + 1; i < lines.size(); i++)
        {
            std::vector<float> v = extractCoordinates(lines[i], 0, 4);
            component->addTile(v[0], v[1], v[2], v[3], v[4]);
        }

        parent->addComponent(component);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}