#include "Tile.h"

void Tile::rotate(int steps)
{
    rotation += steps;
    rotation %= 4;
    if(rotation < 0) rotation += 4;
}

void Tile::setRotation(int steps)
{
    rotation = 0;
    rotate(steps);
}

void Tile::setPosition(int _x, int _y)
{
    x = _x;
    y = _y;
}