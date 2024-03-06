#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Tile //stores info about a tile for PlayGrid
{
    public:
        enum TileType
        {
            Empty = -1,
            Floor = 0,
            Player,
            Wall,
            Button,
            PistonHead,
            PistonBase,
            PistonRod
        };

        int type = -1;
        int network = -1;
        bool output = false;
        int x = 0;
        int y = 0;
        int dx = 0;
        int dy = 0;
        int rotation = 0;
        sf::Sprite sprite;
        Tile() { sprite = *(new sf::Sprite()); }
};