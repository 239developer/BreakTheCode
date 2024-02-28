#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "SceneManager.h"
#include "Gameplay/Engine/Time.h"
#include "Gameplay/Engine/Input.h"
#include "Gameplay/Viewport/Camera.h"

int main()
{
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    Camera::window.create(videoMode, "devbuild", sf::Style::Fullscreen);

    std::shared_ptr<Scene> mainScene = SceneManager::createSceneFromFile("main.scene");
    SceneManager::loadScene(mainScene);

    while(Camera::window.isOpen())
    {
        if(Time::nextTick())
        {
            sf::Event event;
            while (Camera::window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    Camera::window.close();
                }
                else if(event.type == sf::Event::KeyPressed)
                {
                    Input::setKey(event.key.code);
                }
                else if(event.type == sf::Event::KeyReleased)
                {
                    Input::resetKey(event.key.code);
                }
            }
            
            SceneManager::handleEvents();

            Input::resetKeys();
        }

        if(Time::nextFrame())
        {
            Camera::window.clear();
            SceneManager::drawScene();
            Camera::window.display();
        }
    }

    return 0;
}