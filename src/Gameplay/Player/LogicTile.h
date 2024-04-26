#pragma once
#include "Tile.h"
#include "LogicNetwork.h"

class LogicTile : virtual public Tile
{
    protected:
        static std::vector<LogicNetwork*> networks;
        LogicNetwork* network;
        bool inverted = false;
    public:
        static LogicNetwork* getNetworkByID(int id);
        LogicTile() {}
        LogicTile(int networkID);
        LogicTile(LogicNetwork* n);
        LogicTile(sf::Vector2f displacement, LogicNetwork* n);
        void setNetwork(LogicNetwork* n);
        void setInverted(bool b);
        bool isActive();
        void setActive(bool b);
        void resetNetwork();
};

class ButtonTile : virtual public LogicTile
{
    public:
        ButtonTile() {}
        ButtonTile(int networkID);
        ButtonTile(LogicNetwork* n);
        ButtonTile(sf::Vector2f displacement, LogicNetwork* n);
};