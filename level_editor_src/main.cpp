#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "Clicker.h"

int main()
{
    int size_x = 0;
    int size_y = 0;
    std::cin >> size_x >> size_y;

    sf::VideoMode videoMode = sf::VideoMode(size_x * cell, size_y * cell);
    sf::RenderWindow window;
    window.create(videoMode, "editor");

    sf::Clock clock;
    float step = 0.2f;
    float lastStep = 0.0f;
    bool LMB_pressed = false;
    bool RMB_pressed = false;
    bool R_pressed = false;
    bool T_pressed = false;

    Clicker click(&window);

    while(window.isOpen())
    {
        if(clock.getElapsedTime().asSeconds() - lastStep >= step)
        {
            lastStep = clock.getElapsedTime();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    Camera::window.close();
                }
            }
            
            /* check for pressed buttons */
            if(LMB_pressed)
                LMB_pressed = false;
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                LMB_pressed = true;
            if(RMB_pressed)
                RMB_pressed = false;
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
                RMB_pressed = true;
            if(R_pressed)
                R_pressed = false;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                R_pressed = true;
            if(T_pressed)
                T_pressed = false;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
                T_pressed = true;
            /* ye */
            
            
            
        }
    }

    return 0;
}