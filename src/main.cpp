#include <iostream>
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "Gameplay/Engine/Time.h"

int main()
{
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    SceneManager::window.create(videoMode, "devbuild", sf::Style::Fullscreen);

    std::shared_ptr<Scene> mainScene = SceneManager::createSceneFromFile("main.scene");
    SceneManager::loadScene(mainScene);

    while(SceneManager::window.isOpen())
    {
        if(Time::nextTick())
        {
            sf::Event event;
            while (SceneManager::window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    SceneManager::window.close();
            }
            
            SceneManager::handleEvents();
        }

        if(Time::nextFrame())
        {
            SceneManager::window.clear();
            SceneManager::drawScene();
            SceneManager::window.display();
        }
    }

    return 0;
}