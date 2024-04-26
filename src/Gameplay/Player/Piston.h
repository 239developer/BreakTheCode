#pragma once
#include "LogicTile.h"

class Piston : virtual public LogicTile, virtual public Wall
{
    protected:
        int currentLength = 0;
        int minLength = 0;
        int maxLength = 1;
        Tile head;
        Tile rod;
    public:
        Piston() {}
        Piston(int, int, int, Tile&, Tile&);
        Piston(LogicNetwork*, int, int, Tile&, Tile&);
        Piston(sf::Vector2f, LogicNetwork*, int, int, Tile&, Tile&);
        void extend(bool);
        void setLength(int);
        virtual void draw() override;
        virtual void setDisplacement(sf::Vector2f) override;
};