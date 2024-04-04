#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "Clicker.h"
#include "Loader.h"

int cell = 128;

int main()
{
    int size_x = 0;
    int size_y = 0;
    std::cin >> size_x >> size_y;

    Clicker click;
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window;
    window.create(videoMode, "editor", sf::Style::Fullscreen);

    sf::Clock clock;
    float step = 0.2f;
    float lastStep = 0.0f;
    bool LMB_pressed = false;
    bool RMB_pressed = false;
    bool R_pressed = false;
    bool T_pressed = false;
    
    sf::Sprite bg;
    sf::Texture* t = Loader::loadTexture("tiles/bg_00");
    t->setRepeated(true);
    bg.setTexture(*t);

    while(window.isOpen())
    {
        if(clock.getElapsedTime().asSeconds() - lastStep >= step)
        {
            lastStep = clock.getElapsedTime().asSeconds();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    window.close();
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
            
            if(T_pressed)
                click.add();
            else if(R_pressed)
                click.rotate();
            else if(LMB_pressed)
                click.set();
            else if(RMB_pressed)
                click.change();
            
            //draw
            window.clear();
            window.draw(bg);
            std::vector<sf::Sprite*> s = click.draw();
            for(sf::Sprite* sprite : s)
            {
                window.draw(*sprite);
            }
            window.display();
        }
    }

    return 0;
}