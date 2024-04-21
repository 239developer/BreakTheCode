#pragma once
#include "../../GameObject/Component.h"
#include "Tile.h"

class TileController : public Component
{
    private:
        int tickLength = 5; // object updates per game tick
        int tickCounter = 0;
        std::vector<Tile*> tiles;
        sf::Vector2i gridSize;
        std::vector<Tile*> tilesOn(int, int); // returns all the tiles with given coordinates
        std::vector<Tile*> tilesOn(int, int, std::string); // overload that also checks for tag
        bool hasTile(int, int); // returns true if it finds a tile with given coordinates
        bool hasTile(int, int, std::string); // overload that also checks for the tag
        bool pushThing(Tile*, int, int); // recursively (can set max tiles pushed) tries to push tile in a given direction; 
        bool pushThing(Tile*, int); // no max amount of tiles pushed
        // bool pushThingToOneOf(); // can stop on tiles with specified tags instead of just walls
    public:
        TileController(int, int, int); // cellSize, sizeX, sizeY
        void addTile(Tile*);
        virtual void update() override;
        void nextTick(); // game update (when player pressed a button)
};