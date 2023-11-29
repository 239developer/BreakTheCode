#include <iostream>
#include <fstream>
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
    for(std::shared_ptr<sf::Sprite> sprite : currentScene.sprites)
        window.draw(*sprite);
    for(std::shared_ptr<sf::Text> text : currentScene.texts)
        window.draw(*text);
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
                switch(c)
                {  
                    case LOAD_SPRITE:
                        loader.loadSprite(scene, nextLine);
                        break;
                    case LOAD_TEXT:
                        std::string textStr;
                        std::getline(sceneFile, textStr);
                        loader.loadText(scene, nextLine, textStr);
                        break;
                }
                break;
        }
    }

    return scene;
}