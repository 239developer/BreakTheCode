#include "Tile.h"
#include "../Viewport/Camera.h"

int Tile::cellSize = 128;

Tile::Tile() {}

Tile::Tile(sf::Vector2f displace) : Component::Component()
{
    displacement = displace;
    centerCoordinates.x = cellSize / 2.0;
    centerCoordinates.y = cellSize / 2.0;
}

int Tile::sin(int x)
{
    return (x % 2 == 0 ? 0 : (x % 4 == 1 ? 1 : -1));
}

void Tile::setSprite(sf::Sprite* s)
{
    sprite = s;
    sf::IntRect rect = sprite->getTextureRect();
    sprite->setOrigin(rect.width * 0.5f, rect.height * 0.5f);
    float scaleX = cellSize / rect.width;
    float scaleY = cellSize / rect.height;
    sprite->setScale(scaleX, scaleY);
    sprite->setRotation(90.0f * rotation);
    Tile::update();
}

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

void Tile::addTag(std::string tag)
{
    if(!hasTag(tag))
    {
        tags.push_back(tag);
    }
}

bool Tile::hasTag(std::string targetTag)
{
    for(std::string tag : tags)
    {
        if(tag == targetTag)
        {
            return true;
        }
    }
    return false;
}

void Tile::draw()
{
    sf::Vector2f position(x, y);
    position *= (float)cellSize;
    sprite->setPosition(position + displacement);
    sprite->setRotation(90.0f * rotation);
    Camera::window.draw(*sprite);
}

Wall::Wall(sf::Vector2f displace) : Tile::Tile(displace)
{
    tags.push_back("wall");
}