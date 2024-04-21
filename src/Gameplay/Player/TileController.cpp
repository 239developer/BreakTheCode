#include "TileController.h"
#include "../Engine/Input.h"

TileController::TileController(int cellSize, int gridSize_x, int gridSize_y)
{
    Tile::cellSize = cellSize;
    gridSize.x = gridSize_x;
    gridSize.y = gridSize_y;
}

void TileController::addTile(Tile* tile)
{
    tiles.push_back(tile);
}

void TileController::update()
{
    if(    Input::getKeyDown(sf::Keyboard::Key::W)
        || Input::getKeyDown(sf::Keyboard::Key::A)
        || Input::getKeyDown(sf::Keyboard::Key::S)
        || Input::getKeyDown(sf::Keyboard::Key::D))
    {
        nextTick();
    }
}

std::vector<Tile*> TileController::tilesOn(int targetX, int targetY)
{
    std::vector<Tile*> foundTiles;
    for(Tile* tile : tiles)
    {
        if(tile->x == targetX && tile->y == targetY)
        {
            foundTiles.push_back(tile);
        }
    }
    return foundTiles;
}

std::vector<Tile*> TileController::tilesOn(int targetX, int targetY, std::string targetTag)
{
    std::vector<Tile*> foundTiles;
    for(Tile* tile : tilesOn(targetX, targetY))
    {
        if(tile->hasTag(targetTag))
        {
            foundTiles.push_back(tile);
        }
    }
    return foundTiles;
}

bool TileController::hasTile(int targetX, int targetY)
{
    return tilesOn(targetX, targetY).size() > 0;
}

bool TileController::hasTile(int targetX, int targetY, std::string targetTag)
{
    return tilesOn(targetX, targetY, targetTag).size() > 0;
}

bool TileController::pushThing(Tile* thing, int direction, int maxThingsPushed)
{
    if(maxThingsPushed > 0)
    {
        int targetX = thing->x + Tile::sin(direction);
        int targetY = thing->y + Tile::sin(direction - 1);
        bool allow = true;
        allow &= targetX >= 0 && targetX < gridSize.x;
        allow &= targetY >= 0 && targetY < gridSize.y;
        allow &= !hasTile(targetX, targetY, "wall");
        if(allow) // check if we can push something
        {
            std::vector<Tile*> moreThings = tilesOn(targetX, targetY, "movable");
            if(moreThings.size() > 0)
            {
                allow = pushThing(moreThings[0], direction, maxThingsPushed - 1);
            }
        }

        if(allow)
        {
            thing->x = targetX;
            thing->y = targetY;
        }
        return allow;
    }
    return false;
}

bool TileController::pushThing(Tile* thing, int direction)
{
    return pushThing(thing, direction, gridSize.x + gridSize.y);
}

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
    
}