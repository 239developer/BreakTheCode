#include <iostream>
#include <fstream>
#include "GameObject/GameObject.h"
#include "SceneManager.h"
#include "Gameplay/Viewport/Camera.h"
#include "Gameplay/Player/PlayGrid.h"

const int NAME_SECTION = 0;
const int OBJECTS_SECTION = 1;
const char END_OBJECT = '=';
const char LOAD_TRANSFORM = '@';
const char LOAD_SPRITE = 's';
const char LOAD_TEXT = 't';
const char LOAD_BUTTON = 'b';
const char LOAD_ANIMATION = 'a';
const char LOAD_TEDITOR = 'n'; //n for notepad lol
const char LOAD_PLAYER = 'p';
const char LOAD_PLAYGRID = 'g';
const char LOAD_TILECONTROLLER = 'c';
const char LOAD_TILE = 'q';

std::shared_ptr<Scene> SceneManager::currentScene;
bool SceneManager::queuedNew = false; 
std::string SceneManager::sceneFileName;

void SceneManager::queueLoading(std::string filename)
{
    sceneFileName = filename;
    queuedNew = true;
}

void SceneManager::loadScene(std::shared_ptr<Scene> sceneToLoad)
{
    currentScene = sceneToLoad;
}

void SceneManager::drawScene()
{
    Camera::window.setTitle(currentScene->name());
    for(GameObject* obj : currentScene->objects)
    {
        obj->draw();
    }
}

void SceneManager::handleEvents()
{
    for(GameObject* obj : currentScene->objects)
    {
        obj->update();
    }
    
    if(queuedNew)
    {
        queuedNew = false;
        std::shared_ptr<Scene> newScene = createSceneFromFile(sceneFileName);
        loadScene(newScene);
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
            std::vector<std::string> lines;
            int x;

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
                        case LOAD_TRANSFORM:
                            ObjectLoader::loadTransform(nextObj, nextLine);
                            break;
                        case LOAD_SPRITE:
                            ObjectLoader::loadSprite(nextObj, nextLine);
                            break;
                        case LOAD_TEXT:
                            std::getline(sceneFile, textStr);
                            ObjectLoader::loadText(nextObj, nextLine, textStr);
                            break;
                        case LOAD_TEDITOR:
                            std::getline(sceneFile, textStr);
                            ObjectLoader::loadTextEditor(nextObj, nextLine, textStr);
                            break;
                        case LOAD_BUTTON:
                            ObjectLoader::loadButton(nextObj, nextLine);
                            break;
                        case LOAD_ANIMATION:
                            textStr = nextLine.substr(0, nextLine.find_first_of(" "));
                            x = std::stof(textStr);
                            for(int i = 0; i < x; i++)
                            {
                                std::getline(sceneFile, textStr);
                                lines.push_back(textStr);
                            }
                            nextLine = nextLine.substr(nextLine.find_first_of(" ") + 1);
                            ObjectLoader::loadAnimation(nextObj, nextLine, lines);
                            lines.clear();
                            break;
                        case LOAD_TILECONTROLLER:
                            // nextLine = nextLine.substr(1);
                            ObjectLoader::loadTileController(nextObj, nextLine);
                            break;
                        case LOAD_TILE:
                            // nextLine = nextLine.substr(1);
                            ObjectLoader::loadTile(nextObj, nextLine);
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