#pragma once
#include <string>

class LogicNetwork
{
    protected:
        int id;
    public:
        bool active;
        LogicNetwork(int n) { id = n; }
        int getID() { return id; }
};