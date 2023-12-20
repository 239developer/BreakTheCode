#include "AnimationComponent.h"

void AnimationComponent::setAnimation(sf::Image* t, sf::IntRect* b, int* f)
{
    atlas = t;
    textureBounds = b;
    timecodes = f;
    maxID = sizeof(timecodes) / sizeof(int) - 1;
    currentID = 0;
    currentFrame = 0;
    texture->loadFromImage(*atlas, textureBounds[currentID]);
}

void AnimationComponent::update()
{
    if((loop || playing) && (++currentFrame >= timecodes[currentID]))
    {
        if(++currentID > maxID)
        {
            currentID = 0;
            currentFrame = 0;
        }
        texture->loadFromImage(*atlas, textureBounds[currentID]);
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