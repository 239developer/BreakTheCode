#include "Piston.h"

Piston::Piston(sf::Vector2f displacement, LogicNetwork* n, int min, int max, Tile& _head, Tile& _rod)
    : Wall::Wall(displacement), LogicTile::LogicTile(displacement, n)
{
    minLength = min;
    maxLength = max;
    head = _head;
    rod = _rod;
    extend(isActive());
}

void Piston::extend(bool targetState)
{
    if(targetState)
    {
        currentLength = maxLength;
    }
    else
    {
        currentLength = minLength;
    }
}

void Piston::setLength(int targetLength)
{
    currentLength = targetLength;
    if(currentLength < minLength)
    {
        currentLength = minLength;
    }
    else if(currentLength > maxLength)
    {
        currentLength = maxLength;
    }
}

void Piston::draw()
{
    rod.setRotation(this->rotation);
    for(int i = 0; i <= currentLength; i++)
    {
        rod.setPosition(x + i * Tile::sin(this->rotation), y + i * Tile::sin(this->rotation - 1));
        rod.draw();
    }
    draw();
    head.setRotation(this->rotation);
    head.draw();
}