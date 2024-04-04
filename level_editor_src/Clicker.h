#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

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
        std::vector<Tile*> tiles;
        int curr = -1;
        std::string getName(int);
    public:
        const int cell = 128;
        Clicker();
        void rotate();
        void change();
        void add();
        void set();
        std::vector<sf::Sprite*> draw();
};