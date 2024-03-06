#include "Input.h"
#include <SFML/Graphics.hpp>
#include "Time.h"
#include <iostream>

int Input::pressed[sf::Keyboard::Key::KeyCount];
bool Input::anythingDown = false;

void Input::resetKeys()
{
    for(int i = 0; i < sf::Keyboard::Key::KeyCount; i++)
    {
        if(pressed[i] > 0) 
        {
            pressed[i]++;
        }
    }
    anythingDown = false;
}

void Input::resetKey(int key)
{
    if(key >= 0 && key < sf::Keyboard::Key::KeyCount)
    {
        pressed[key] = 0;
    }
}

void Input::setKey(int key)
{
    if(key >= 0 && key < sf::Keyboard::Key::KeyCount && pressed[key] == 0)
    {
        pressed[key] = 1;
        anythingDown = true;
    }
}

bool Input::getKeyDown(int key)
{
    if(key >= 0 && key < sf::Keyboard::Key::KeyCount)
    {
        if(pressed[key] > 0 && pressed[key] <= 5)
        {
            pressed[key] = 5;
            return true;
        }
    }
    return false;
}

bool Input::getAnyKeyDown()
{
    return anythingDown;
}