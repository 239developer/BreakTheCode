#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "SpriteComponent.h"

class AnimationComponent : public SpriteComponent
{
    private:
        sf::Image* atlas;
        std::vector<sf::IntRect> textureBounds;
        std::vector<int> timecodes; 
        int maxID;
        int currentID;
        int currentFrame;
        bool playing;
        bool loop;
    public:   
        using SpriteComponent::SpriteComponent;   
        void setAnimation(sf::Image*, std::vector<sf::IntRect>, std::vector<int>);
        void update(); 
        void setLoop(bool);
        void setID(int);
        virtual void draw() override;
};