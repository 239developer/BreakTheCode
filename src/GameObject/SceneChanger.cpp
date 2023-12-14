#include "SceneChanger.h"
#include "../SceneManager.h"
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
    SceneManager manager;
    std::shared_ptr<Scene> scene = manager.createSceneFromFile(sceneFileName);
    manager.loadScene(scene);
    std::cout << "Switched scene to: [" << sceneFileName << "]\n";
}