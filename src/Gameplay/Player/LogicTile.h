#pragma once
#include "Tile.h"
#include "LogicNetwork.h"

class LogicTile : virtual public Tile
{
    protected:
        LogicNetwork* network;
        bool inverted = false;
    public:
        LogicTile(sf::Vector2f displacement, LogicNetwork* n) : Tile::Tile(displacement) { setNetwork(n); tags.push_back("logic"); }
        void setNetwork(LogicNetwork* n) { network = n; }
        void setInverted(bool b) { inverted = b; }
        bool isActive() { return network->active ^ inverted; }
};