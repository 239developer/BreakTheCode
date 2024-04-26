#include <iostream>
#include "ObjectLoader.h"
#include "../Gameplay/Player/TileController.h"
#include "../Gameplay/Player/Piston.h"

void ObjectLoader::loadTile(GameObject* parent, std::string line)
{

    TileController* controller = parent->getComponent<TileController>();
    if(controller != nullptr)
    {
        Tile* tile = new Tile();
        Tile* finalTile = new Tile();
        Wall* wall = new Wall();
        Piston* piston = new Piston();
        ButtonTile* button = new ButtonTile();
        std::vector<int> tileCoordinates = extractIntCoordinates(line, 2);
        std::string name = getStringFromLine(line); // name (type)
        if(name == "wall")
        {
            wall->setTexture(loadTexture("tiles/wall.png"));
            controller->addTile(wall);
            tile = wall;
        }
        else if(name == "piston")
        {
            tile->setTexture(loadTexture("tiles/piston_rod.png"));
            wall->setTexture(loadTexture("tiles/piston_head.png"));
            std::vector<int> pistonInfo = extractIntCoordinates(line, 2);
            piston = new Piston(pistonInfo[0], pistonInfo[1], pistonInfo[2], *wall, *tile);
            piston->setTexture(loadTexture("tiles/piston_base.png"));
            controller->addTile(piston);
            tile = piston;
        }
        else if(name == "player")
        {
            tile->setTexture(loadTexture("tiles/player.png"));
            tile->addTag("player");
            tile->addTag("movable");
            controller->addTile(tile);
            finalTile = tile;
        }
        else if(name == "crate")
        {
            tile->setTexture(loadTexture("tiles/crate.png"));
            tile->addTag("crate");
            tile->addTag("movable");
            controller->addTile(tile);
            finalTile = tile;
        }
        else if(name == "button")
        {
            button = new ButtonTile(extractIntCoordinates(line, 0)[0]);
            button->setTexture(loadTexture("tiles/button.png"));
            controller->addTile(button);
            finalTile = button;
        }
        finalTile->setPosition(tileCoordinates[0], tileCoordinates[1]);
        finalTile->setRotation(tileCoordinates[2]);
        std::cout << "Loaded a tile: " << name << "\n";
    }
    else
    {
        std::cout << "Tried to load a tile but a TileController was not found\n";
    }
}