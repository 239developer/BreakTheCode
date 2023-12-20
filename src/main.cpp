#include <iostream>
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

int main()
{
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(videoMode, "devbuild", sf::Style::Fullscreen);
    // window.setFramerateLimit(60);

    SceneManager manager;
    std::shared_ptr<Scene> mainScene = manager.createSceneFromFile("main.scene");
    manager.loadScene(mainScene);

    sf::Clock clock;
    float lastTime = 0.0f;
    float currTime = 0.0f;
    float deltaTime = 0.0f;
    const float minFrameDuration = 1.0f / 60;

    while(window.isOpen())
    {
        currTime = clock.getElapsedTime().asSeconds();
        deltaTime = currTime - lastTime;
        if(deltaTime >= minFrameDuration)   // update the display only if some time has passed from the last frame
        {
            lastTime = currTime;
            window.clear();

            sf::Event event;
            while (window.pollEvent(event))
            {
            if (event.type == sf::Event::Closed)
                window.close();
            }

            manager.drawScene(window);
            manager.handleEvents();
            window.display();
        }
    }

    return 0;
}