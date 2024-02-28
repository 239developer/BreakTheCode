#include "GameObject.h"
#include "TextEditor.h"
#include "Button.h"
#include "../Gameplay/Engine/Transform.h"
#include "../Gameplay/Player/PlayerController.h"

#include <iostream>

void GameObject::addComponent(Component* c)
{
    c->setParent(this);
    components.push_back(c);
}

void GameObject::draw()
{
    for(Component* c : components)
    {
        c->draw();
    }
}

void GameObject::handleEvents()
{
    Button* button = getComponent<Button>();
    if(button)
    {
        if(button->isPressed())
            button->press();
    }

    TextEditor* teditor = getComponent<TextEditor>();
    if(teditor)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            teditor->selectWord();
        }
    }

    PlayerController* pc = getComponent<PlayerController>();
    if(pc)
    {
        pc->fixedUpdate();
    }
}

GameObject::GameObject() {}