#include "SceneChanger.h"
#include "../Scene.h"
#include <iostream>
#include <memory>

void SceneChanger::setScene(std::string str)
{
    sceneFileName = str;
    std::cout << "Assigned a button to switch to [" << str << "]\n";
}

void SceneChanger::press()
{
    SceneManager::queueLoading(sceneFileName);
    std::cout << "Queued load of a scene: [" << sceneFileName << "]\n";
}