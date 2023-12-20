#include "GameObject.h"
#include "TextComponent.h"
#include "AnimationComponent.h"

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
    components.push_back(c);
}

void GameObject::draw(sf::RenderWindow& window)
{
    AnimationComponent* animComp = getComponent<AnimationComponent>();
    if(animComp)
        animComp->update();

    TextComponent* textComp = getComponent<TextComponent>();
    if(textComp)
        window.draw(*textComp->getText());

    SpriteComponent* spriteComp = getComponent<SpriteComponent>();
    if(spriteComp)
        window.draw(*spriteComp->getSprite());
}

GameObject::GameObject() {}