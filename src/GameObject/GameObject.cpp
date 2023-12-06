#include "GameObject.h"
#include "TextComponent.h"
#include "SpriteComponent.h"

template <typename T>
T* GameObject::getComponent()
{
    T* result = nullptr;
    for(Component * c : components)
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
    TextComponent* textComp = getComponent<TextComponent>();
    if(textComp)
        window.draw(*textComp->getText());

    SpriteComponent* spriteComp = getComponent<SpriteComponent>();
    if(spriteComp)
        window.draw(*spriteComp->getSprite());
}

GameObject::GameObject() {}