#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tile
{
    public:
        enum TILES
        {
            Floor = -1,
            Empty = 0,
            Player,
            Wall,
            Button,
            PistonHead,
            PistonBase,
            PistonRod,
            Crate
        };
        int id = 0;
        int x = 0;
        int y = 0;
        int rotation = 0;
        void rotateCW()
        {
            if(++rotation > 3)
                rotation = 0;
        }
};

class Clicker
{
    private:
        sf::RenderWindow* window;
        const int cell = 128;
        sf::Sprite* sprites[8];
        std::vector<Tile*> tiles;
        int curr = -1;

    public:
        Clicker(sf::RenderWindow*);
        void rotate();
        void change(bool);
        void add();
        void set();
        void draw();
};