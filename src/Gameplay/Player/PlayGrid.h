#pragma once
#include <vector>
#include "../../GameObject/Component.h"
#include "Tile.h"

class PlayGrid : public Component
{
    private:
        int cellSize = 150;
        int width = 1;
        int height = 1;
        std::vector<int> networks;
        std::vector<sf::Texture> textures;
        std::vector<Tile*> floor; // flooring + all things that player can't be blocked by
        std::vector<Tile*> walls; // all player can be blocked by, e g piston bases
        std::vector<Tile*> buttons; // all that can activate
        std::vector<Tile*> pistons; // all that can be activated
        std::vector<Tile*> crates;
        Tile* player;

        void pushThing(Tile*, int, int);
    public:
        static const int tileTypeAmount = 9;
        using Component::Component;
        void addTexture(sf::Texture);
        void setSize(int, int);
        void addTile(int x, int y, int rotation, int type, int logicGrid);
        void gameStep();
        virtual void update() override;
        virtual void draw() override;
};