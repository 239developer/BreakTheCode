#include "Component.h"

Component::Component() { }

Component::~Component() {}

void Component::setParent(GameObject* p)
{
    parent = p;
}

GameObject * Component::getParent()
{
    return parent;
}