#pragma once
#include "../../GameObject/Component.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Tile : virtual public Component
{
    protected:
        sf::Vector2f centerCoordinates; 
        int rotation = 0; // (rotation * pi / 2) radians (CW)
        sf::Sprite* sprite = new sf::Sprite();
        std::vector<std::string> tags;
        sf::Vector2f displacement;
    public:
        static int sin(int);
        static int cellSize;
        int x = 0;
        int y = 0;
        Tile();
        Tile(sf::Vector2f);
        void setSprite(sf::Sprite*);
        void setTexture(sf::Texture*);
        void rotate(int);
        void setRotation(int);
        void setPosition(int, int);
        void addTag(std::string);
        bool hasTag(std::string);
        virtual void draw() override;
        virtual void setDisplacement(sf::Vector2f);
};

class Wall : virtual public Tile
{
    public:
        Wall();
        Wall(sf::Vector2f);
};