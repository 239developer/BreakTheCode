#include "PlayerController.h"
#include "../Viewport/Camera.h"
#include "../Engine/Time.h"
#include <cmath>
#include <iostream>

float speed = 500.0f; //pixels per second

void PlayerController::setParent(GameObject* p)
{
    Component::setParent(p);
    if(!transform)
    {
        transform = new Transform();
        parent->addComponent(transform);
    }
}

void PlayerController::fixedUpdate()
{
    // move up/down/left/right
    sf::Vector2f dir = *(new sf::Vector2f(0.0, 0.0));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        dir.y -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        dir.y += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        dir.x -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        dir.x += 1;
    }
    float r = sqrt(dir.x * dir.x + dir.y * dir.y);
    if(r == 0) r = 1;
    dir = dir * speed / r;
    transform->translate(dir * 0.02f);
    // std::cout << r << " " << dir.x * Time::fixedDeltaTime() << " " << dir.y * Time::fixedDeltaTime() << "\n";

    // Camera::translate(dir * Time::fixedDeltaTime());
}