#include "Component.h"

Component::Component (GameObject* p)
{
    parent = p;
}

Component::~Component() {}

GameObject * Component::getParent()
{
    return parent;
}