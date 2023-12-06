#include <iostream>
#include <fstream>
#include "GameObject/GameObject.h"
#include "SceneManager.h"

const int SceneManager::NAME_SECTION = 0;
const int SceneManager::OBJECTS_SECTION = 1;
const char SceneManager::LOAD_SPRITE = 's';
const char SceneManager::LOAD_TEXT = 't';

void SceneManager::unloadScene()
{
    
}

void SceneManager::loadScene(std::shared_ptr<Scene> sceneToLoad)
{
    currentScene = *sceneToLoad;
}

void SceneManager::drawScene(sf::RenderWindow& window)
{
    window.setTitle(currentScene.name());
    for(GameObject* obj : currentScene.objects)
    {
        obj->draw(window);
    }
}

std::shared_ptr<Scene> SceneManager::createSceneFromFile(std::string filePath)
{
    std::shared_ptr<Scene> scene = std::shared_ptr<Scene>(new Scene());
    std::ifstream sceneFile(filePath);
    std::string nextLine;

    int syntaxCounter = 0; // tracks what part of the file the program is reading
    while(sceneFile)
    {
        std::getline(sceneFile, nextLine);
        
        if(nextLine == "->")
        {
            syntaxCounter++;
            continue;
        }

        char c = nextLine[0];
        nextLine = nextLine.substr(2);

        switch(syntaxCounter)
        {
            case NAME_SECTION:
                scene->setName(nextLine);
                break;
            case OBJECTS_SECTION:
                GameObject* nextObj = new GameObject();
                switch(c)
                {   
                    case LOAD_SPRITE:
                        loader.loadSprite(nextObj, nextLine);
                        break;
                    case LOAD_TEXT:
                        std::string textStr;
                        std::getline(sceneFile, textStr);
                        loader.loadText(nextObj, nextLine, textStr);
                        break;
                }
                scene->objects.push_back(nextObj);
                break;
        }
    }

    return scene;
}