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
    if(manager)
    {
        manager->queueLoading(sceneFileName);
        std::cout << "Queued load of a scene: [" << sceneFileName << "]\n";
    }
    else
    {
        std::cout << "No SceneManager provided\n";
    }
}

void SceneChanger::setManager(SceneManager* man)
{
    manager = man;
}