#include "Clicker.h"
#include "Loader.h"
#include <iostream>

Clicker::Clicker()
{
    
}

std::string Clicker::getName(int id)
{
    switch(id)
    {
        case 0: return "tiles/floor";
        case 1: return "tiles/player";
        case 2: return "tiles/wall";
        case 3: return "tiles/button";
        case 4: return "tiles/piston_head";
        case 5: return "tiles/piston_base";
        case 6: return "tiles/piston_rod";
        case 7: return "tiles/crate";
        case 8: return "tiles/win";
    }
    return "";
}

void Clicker::add()
{
    if(curr < 0)
    {
        curr = tiles.size();
        tiles.push_back(new Tile());
        // std::cout << "added a tile\n";
    }
}

void Clicker::set()
{
    if(curr >= 0)
    {
        tiles[curr]->x = (int)sf::Mouse::getPosition().x / cell;        
        tiles[curr]->y = (int)sf::Mouse::getPosition().y / cell;        
        std::cout << tiles[curr]->x << " " << tiles[curr]->y << " ";
        std::cout << tiles[curr]->rotation << " " << tiles[curr]->id - 1 << " -1\n";
        curr = -1;
    }
}

void Clicker::change()
{
    if(curr >= 0 && ++tiles[curr]->id > 8)
        tiles[curr]->id = 0;
    // std::cout << "changed the tile\n";
}

void Clicker::rotate()
{
    if(curr >= 0)
    {
        tiles[curr]->rotateCW();
        // std::cout << "rotated the tile\n";
    }
}

std::vector<sf::Sprite*> Clicker::draw()
{
    std::vector<sf::Sprite*> out;
    for(Tile* tile : tiles)
    {
        sf::Sprite* sprite = new sf::Sprite();
        if(tile->id >= 0)
        {
            sf::Texture* t = new sf::Texture();
            std::string texturePath = "../assets/textures/" + getName(tile->id) + ".png";
            if(t->loadFromFile(texturePath))
            {
                // std::cout << "Loaded texture: [" << texturePath << "]\n";
            }
            sprite->setTexture(*t);
            sprite->setScale(cell / 256.0, cell / 256.0);
            sprite->setPosition(tile->x * cell, tile->y * cell);
            // std::cout << tile->x << " " << tile->y << " " << tile->id << "\n";
            // sprite->setRotation(tile->rotation * 90.0f);
            out.push_back(sprite);
        }
    }
    return out;
}