#include <iostream>
#include <fstream>
#include "SceneManager.h"
#include "utility/utility.cpp"

const int SceneManager::NAME_SECTION = 0;
const int SceneManager::OBJECTS_SECTION = 1;

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
    {
        window.draw(*sprite);
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

        switch(syntaxCounter)
        {
            case NAME_SECTION:
                scene->setName(nextLine);
                break;
            case OBJECTS_SECTION:
                std::string texturePath = nextLine.substr(0, nextLine.find_first_of(" "));
                std::shared_ptr<sf::Texture> texture(new sf::Texture());
                if(texture->loadFromFile("../assets/textures/" + texturePath));
                    std::cout << "Loaded texture: [" << texturePath << "]" << "\n";

                scene->textures.push_back(texture);

                std::shared_ptr<sf::Sprite> sprite(new sf::Sprite());

                const sf::Texture& const_texture = *scene->textures.back();
                sprite->setTexture(const_texture);
                
                std::vector<float> v = extract_coordinates(nextLine);
                const sf::Vector2f pos(v[0], v[1]);
                sprite->setPosition(pos);
                
                scene->sprites.push_back(sprite);
                break;
        }
    }

    return scene;
}