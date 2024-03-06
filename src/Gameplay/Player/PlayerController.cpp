#include "PlayerController.h"
#include "../Viewport/Camera.h"
#include "../Engine/Time.h"
#include "../Engine/Input.h"
#include <cmath>
#include <iostream>

//          !!! DEPRECATED !!!

void PlayerController::setParent(GameObject* p)
{
    Component::setParent(p);
    if(!transform)
    {
        transform = p->getComponent<Transform>();
        if(!transform)
        {    
            transform = new Transform();
        }
        parent->addComponent(transform);
    }
    // gridPosition = transform->position;
}

//          !!! DEPRECATED !!!

void PlayerController::fixedUpdate()
{
    // move up/down/left/right
    if(Input::getKeyDown(sf::Keyboard::Key::W))
    {
        cell->y -= 1;
    }
    else if(Input::getKeyDown(sf::Keyboard::Key::S))
    {
        cell->y += 1;
    }
    else if(Input::getKeyDown(sf::Keyboard::Key::A))
    {
        cell->x -= 1;
    }
    else if(Input::getKeyDown(sf::Keyboard::Key::D))
    {
        cell->x += 1;
    }

    //check if out of bounds
    if(cell->x < 0)
    {
        cell->x = 0;
    }
    if(cell->y < 0)
    {
        cell->y = 0;
    }
    if(cell->x > gridSize->x - 1)
    {
        cell->x = gridSize->x - 1;
    }
    if(cell->y > gridSize->y - 1)
    {
        cell->y = gridSize->y - 1;
    }

    //apply position
    sf::Vector2f delta(cellSize->x * cell->x, cellSize->y * cell->y);
    transform->position = *gridPosition + delta;
}

//          !!! DEPRECATED !!!

void PlayerController::update()
{
    fixedUpdate();
}

//          !!! DEPRECATED !!!