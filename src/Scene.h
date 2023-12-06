#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
#include "GameObject/GameObject.h"

class Scene
{
    private:
        std::string sceneName;
    public:
        std::vector<GameObject*> objects;
        std::string name() const;
        void setName(std::string newName);
};