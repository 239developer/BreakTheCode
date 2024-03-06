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

void GameObject::update()
{
    for(Component* c : components)
    {
        c->update();
    }
}

GameObject::GameObject() {}