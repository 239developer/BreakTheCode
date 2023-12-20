#include <iostream>
#include <fstream>
#include "GameObject/GameObject.h"
#include "SceneManager.h"

const int NAME_SECTION = 0;
const int OBJECTS_SECTION = 1;
const char END_OBJECT = '=';
const char LOAD_SPRITE = 's';
const char LOAD_TEXT = 't';
const char LOAD_BUTTON = 'b';

std::shared_ptr<Scene> SceneManager::currentScene;

void SceneManager::loadScene(std::shared_ptr<Scene> sceneToLoad)
{
    currentScene = sceneToLoad;
}

void SceneManager::drawScene(sf::RenderWindow& window)
{
    window.setTitle(currentScene->name());
    for(GameObject* obj : currentScene->objects)
    {
        obj->draw(window);
    }
}

void SceneManager::handleEvents()
{
    for(GameObject* obj : currentScene->objects)
    {
        obj->handleEvents();
    }
}

std::shared_ptr<Scene> SceneManager::createSceneFromFile(std::string filePath)
{
    try {
        std::shared_ptr<Scene> scene = std::shared_ptr<Scene>(new Scene());
        std::ifstream sceneFile("../assets/scenes/" + filePath);
        std::string nextLine;
        GameObject* nextObj = new GameObject();

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
            if(nextLine.size() > 2) nextLine = nextLine.substr(2);
            std::string textStr;

            switch(syntaxCounter)
            {
                case NAME_SECTION:
                    scene->setName(nextLine);
                    break;
                case OBJECTS_SECTION:
                    switch(c)
                    {   
                        case END_OBJECT:
                            scene->objects.push_back(nextObj);
                            nextObj = new GameObject();
                            break;
                        case LOAD_SPRITE:
                            loader.loadSprite(nextObj, nextLine);
                            break;
                        case LOAD_TEXT:
                            std::getline(sceneFile, textStr);
                            loader.loadText(nextObj, nextLine, textStr);
                            break;
                        case LOAD_BUTTON:
                            loader.loadButton(nextObj, nextLine);
                            break;
                    }
                    break;
            }
        }
        return scene;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    return nullptr;
}