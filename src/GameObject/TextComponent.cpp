#include "TextComponent.h"

void TextComponent::setText(sf::Text* t, sf::Font* f)
{
    text = t;
    font = f;
}

sf::Text* TextComponent::getText()
{
    return text;
}