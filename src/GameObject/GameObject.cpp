#include "GameObject.h"

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