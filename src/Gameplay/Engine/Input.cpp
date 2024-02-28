#include "Input.h"
#include <SFML/Graphics.hpp>
#include "Time.h"
#include <iostream>

int Input::pressed[sf::Keyboard::Key::KeyCount];

void Input::resetKeys()
{
    for(int i = 0; i < sf::Keyboard::Key::KeyCount; i++)
    {
        if(pressed[i] > 0) 
        {
            pressed[i]++;
        }
    }
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