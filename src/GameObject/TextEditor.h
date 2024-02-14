#pragma once
#include "TextComponent.h"

class TextEditor : public TextComponent  //depends on the font being monospaced
{
    private:
        int maxWidth;
        std::vector<int> spaces;
        std::vector<int> linefeeds;
        int charWidth;
        int lineHeight;
        sf::RectangleShape* selectionRect;
    public:
        using TextComponent::TextComponent;
        void setText(sf::Text*, sf::Font*) override;
        void setMaxWidth(int);
        void formatText();
        void selectWord();
        sf::RectangleShape* getSelectionRect();
};