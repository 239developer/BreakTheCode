#include "TextComponent.h"
#include "../Gameplay/Viewport/Camera.h"
#include "../Gameplay/Engine/Transform.h"

void TextComponent::setText(sf::Text* t, sf::Font* f)
{
    text = t;
    font = f;
}

sf::Text* TextComponent::getText()
{
    return text;
}

void TextComponent::draw()
{
    Transform* transform = parent->getComponent<Transform>();
    if(transform)
    {    
        text->setPosition(transform->position - Camera::position);
    }

    Camera::window.draw(*text);
}
