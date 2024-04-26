#include "LogicTile.h"

std::vector<LogicNetwork*> LogicTile::networks;

LogicNetwork* LogicTile::getNetworkByID(int id)
{
    for(LogicNetwork* n : networks)
    {
        if(n->getID() == id)
        {
            return n;
        }
    }
    LogicNetwork* x = new LogicNetwork(id);
    networks.push_back(x);
    return x;
}

LogicTile::LogicTile(int networkID) : Tile::Tile()
{
    setNetwork(getNetworkByID(networkID));
    addTag("logic");
}

LogicTile::LogicTile(LogicNetwork* n) : Tile::Tile()
{
    setNetwork(n);
    addTag("logic");
}

LogicTile::LogicTile(sf::Vector2f displacement, LogicNetwork* n) : Tile::Tile(displacement)
{
    setNetwork(n);
    addTag("logic");
}

void LogicTile::setNetwork(LogicNetwork* n)
{
    network = n;

}

void LogicTile::setInverted(bool b)
{
    inverted = b;
}

bool LogicTile::isActive()
{
    return network->active ^ inverted;

}
void LogicTile::setActive(bool b)
{
    network->active |= b ^ inverted;

}
void LogicTile::resetNetwork()
{
    network->active = false;
}

ButtonTile::ButtonTile(int networkID) : LogicTile::LogicTile(networkID)
{
    addTag("button");
}

ButtonTile::ButtonTile(LogicNetwork* n) : LogicTile::LogicTile(n)
{
    addTag("button");
}

ButtonTile::ButtonTile(sf::Vector2f displacement, LogicNetwork* n) : LogicTile::LogicTile(displacement, n)
{
    addTag("button");
}