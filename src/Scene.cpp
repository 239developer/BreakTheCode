#include "Scene.h"
// #include "GameObject/Button.h"

std::string Scene::name() const
{
    return sceneName;
}

void Scene::setName(std::string newName)
{
    sceneName = newName;
}