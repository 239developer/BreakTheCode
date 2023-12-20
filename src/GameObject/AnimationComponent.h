#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "SpriteComponent.h"

class AnimationComponent : public SpriteComponent
{
    private:
        sf::Image* atlas;
        sf::IntRect* textureBounds;
        int* timecodes; 
        int maxID;
        int currentID;
        int currentFrame;
        bool playing;
        bool loop;
    public:   
        using SpriteComponent::SpriteComponent;   
        void setAnimation(sf::Image*, sf::IntRect [], int []);
        void update(); //returns (new) current frame
        void setLoop(bool);
        void setFrame(int);
};