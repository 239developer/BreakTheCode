#include "GameObject.h"
#include "TextComponent.h"
#include "AnimationComponent.h"
#include "SceneChanger.h"
#include "TextEditor.h"
#include "../Gameplay/Engine/Transform.h"
#include "../Gameplay/Player/PlayerController.h"

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
    Transform* transform = getComponent<Transform>();
    if(transform)
    {
        transform->draw();
    }

    AnimationComponent* animComp = getComponent<AnimationComponent>();
    if(animComp)
    {
        animComp->update();
        window.draw(*animComp->getSprite());
    }
    else
    {
        SpriteComponent* spriteComp = getComponent<SpriteComponent>();
        if(spriteComp)
        {
            window.draw(*spriteComp->getSprite());
        }
    }

    TextEditor* editor = getComponent<TextEditor>();
    if(editor)
    {
        sf::RectangleShape* selRect = editor->getSelectionRect();
        if(selRect)
            window.draw(*selRect);
        // else
        //     std::cout << "no rect\n";
        window.draw(*editor->getText());
    }
    else
    {
        TextComponent* textComp = getComponent<TextComponent>();
        if(textComp)
        {
            window.draw(*textComp->getText());
        }
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