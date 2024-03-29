#include "Clicker.h"
#include "Loader.h"

Clicker::Clicker(sf::RenderWindow* win)
{
    window = win;
    sprites[0] = Loader::loadSprite("floor");
    sprites[1] = Loader::loadSprite("player");
    sprites[2] = Loader::loadSprite("wall");
    sprites[3] = Loader::loadSprite("button");
    sprites[4] = Loader::loadSprite("pistonHead");
    sprites[5] = Loader::loadSprite("pistonBase");
    sprites[6] = Loader::loadSprite("pistonRod");
    sprites[7] = Loader::loadSprite("Crate");
}

void Clicker::add()
{
    if(curr < 0)
    {
        curr = tiles.size();
        tiles.push_back(new Tile());
    }
}

void Clicker::set()
{
    if(curr >= 0)
    {
        tiles[curr]->x = (int)sf::Mouse::getPosition().x / cell;        
        tiles[curr]->y = (int)sf::Mouse::getPosition().y / cell;        
        curr = -1;
    }
}

void Clicker::change()
{
    if(curr >= 0 && ++tiles[curr]->id > 7)
        tiles[curr]->id = 0;
}

void Clicker::rotate()
{
    if(curr >= 0)
        tiles[curr]->rotateCW();
}

void Clicker::draw()
{
    for(Tile* tile : tiles)
    {
        sf::Sprite* sprite;
        if(tile->id > 0)
        {
            sprite = sprites[tile->id];
        }
        sprite->setPosition(tile->x * cell, tile->y * cell);
        sprite->setRotation(tile->rotation * 90.0f);
        window->draw(*sprite);
    }
}