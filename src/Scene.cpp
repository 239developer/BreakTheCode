#include "Scene.h"

std::string Scene::name() const
{
    return sceneName;
}

void Scene::setName(std::string newName)
{
    sceneName = newName;
}