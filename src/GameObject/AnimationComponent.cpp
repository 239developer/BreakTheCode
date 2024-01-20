#include "AnimationComponent.h"
#include <iostream>

void AnimationComponent::setAnimation(sf::Image* t, std::vector<sf::IntRect> b, std::vector<int> f)
{
    atlas = t;
    textureBounds = b;
    timecodes = f;
    maxID = timecodes.size();
    std::cout << f[0] << " " << timecodes[0] << " " << maxID << "\n";
    currentID = 0;
    currentFrame = 0;

    texture = new sf::Texture();
    sprite = new sf::Sprite();
    sf::IntRect bounds = textureBounds[currentID];
    texture->loadFromImage(*atlas, bounds);
    sprite->setTexture(*texture);
}

void AnimationComponent::update()
{
    if(loop || playing)
    {
        if(++currentFrame >= timecodes[currentID])
        {
            if(++currentID > maxID)
            {
                currentID = 0;
                currentFrame = 0;
            }
            texture->~Texture();
            texture = new sf::Texture();
            texture->loadFromImage(*atlas, textureBounds[currentID]);
            sprite->setTexture(*texture);
        }
    }
    if(currentFrame == 0)
        playing = false;
}

void AnimationComponent::setID(int id = 0)
{
    currentID = id;
    if(currentID > maxID)
        currentID = 0;
    currentFrame = timecodes[currentID];
}

void AnimationComponent::setLoop(bool b = true)
{
    loop = b;
}