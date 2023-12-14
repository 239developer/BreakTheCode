#include "GameObject.h"
#include "TextComponent.h"
#include "SpriteComponent.h"
#include "SceneChanger.h"

#include <iostream>

template <typename T>
inline T* GameObject::getComponent()
{
    T* result = nullptr;
    for(Component* c : components)
    {
        result = dynamic_cast<T*>(c);
        if(result)
            break;
    }
    return result;
}

void GameObject::addComponent(Component* c)
{
    c->setParent(this);
    components.push_back(c);
}

void GameObject::draw(sf::RenderWindow& window)
{
    SpriteComponent* spriteComp = getComponent<SpriteComponent>();
    if(spriteComp)
        window.draw(*spriteComp->getSprite());

    TextComponent* textComp = getComponent<TextComponent>();
    if(textComp)
    {
        window.draw(*textComp->getText());
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
}

GameObject::GameObject() {}