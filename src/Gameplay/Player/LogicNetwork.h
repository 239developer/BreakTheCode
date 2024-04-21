#pragma once
#include <string>

class LogicNetwork
{
    protected:
        std::string name;
    public:
        bool active;
        LogicNetwork(std::string n) { name = n; }
        std::string getName() { return name; }
};