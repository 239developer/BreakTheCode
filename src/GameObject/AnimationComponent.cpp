#include "AnimationComponent.h"
#include <iostream>

void AnimationComponent::setAnimation(sf::Image* t, sf::IntRect b[], int f[])
{
    atlas = t;
    textureBounds = b;
    timecodes = f;
    maxID = sizeof(timecodes) / sizeof(int);
    std::cout << f[0] << " " << timecodes[0] << " " << maxID << "\n";
    currentID = 0;
    currentFrame = 0;

    texture = new sf::Texture();
    sprite = new sf::Sprite();
    sf::IntRect bounds = textureBounds[currentID];
    texture->loadFromImage(*atlas, bounds);
    sprite->setTexture(*texture);
    std::cout << currentID << " " << timecodes[currentID] - currentFrame << " " << currentFrame << "\n";
    update();
}

void AnimationComponent::update()
{
    if(loop || playing)
    {
        std::cout << currentID << " " << timecodes[currentID] - currentFrame << " " << currentFrame << "\n";
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

void AnimationComponent::setFrame(int frame = 0)
{
    currentFrame = frame;
    for(int i = 0; i <= maxID; i++)
    {
        if(currentFrame <= timecodes[i])
        {
            currentID = i;
            return;
        }
    }
    currentID = 0;
    currentFrame = 0;
}

void AnimationComponent::setLoop(bool b = true)
{
    loop = b;
}