#include "TileController.h"
#include "../Engine/Input.h"
#include "Piston.h"

void TileController::nextTick()
{
    // player movement
    int direction = 0;
    if(Input::getKeyDown(sf::Keyboard::Key::W))
    {
        direction = 0;
    }
    else if(Input::getKeyDown(sf::Keyboard::Key::S))
    {
        direction = 2;
    }
    else if(Input::getKeyDown(sf::Keyboard::Key::A))
    {
        direction = 3;
    }
    else if(Input::getKeyDown(sf::Keyboard::Key::D))
    {
        direction = 1;
    }
    for(Tile* player : tilesWithTag("player"))
    {
        pushThing(player, direction);
    }

    // reset all logic networks to "off"
    for(Tile* tile : tilesWithTag("logic"))
    {
        LogicTile* logicTile = dynamic_cast<LogicTile*>(tile);
        logicTile->resetNetwork();
    }

    // check if any buttons are activated
    for(Tile* tile : tilesWithTag("button"))
    {
        ButtonTile* button = dynamic_cast<ButtonTile*>(tile);
        if(hasTile(button->x, button->y, "movable"))
        {
            button->setActive(true);
        }
    }

    // extend pistons
    for(Tile* tile : tilesWithTag("piston"))
    {
        Piston* piston = dynamic_cast<Piston*>(tile);
        piston->extend(piston->isActive());
    }
}