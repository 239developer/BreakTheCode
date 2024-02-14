#include "TextEditor.h"
#include <iostream>
#include <vector>
#include <string>

const std::string specialCharacters = " ,;.:\"\'(){}[]=+-*/&%|!?<>\n";
const float heightToWidth = 0.475;

void TextEditor::setMaxWidth(int w)
{
    maxWidth = w;
}

void TextEditor::formatText()
{
    std::string str = text->getString();
    spaces.clear();

    int pos = 0;
    while(true)
    {
        pos = str.find_first_of(specialCharacters, pos + 1);
        if(pos != std::string::npos)
        {
            spaces.push_back(pos);
        }
        else
        {
            break;
        }
    }

    int n = spaces.size();
    int d = 0;
    for(int i = 1; i < n; i++)
    {
        spaces[i] += d;
        sf::Vector2f v = text->findCharacterPos(spaces[i]);
        if(v.x > maxWidth)
        {
            str.insert(spaces[i] + 1, "\n");
            d++;
            text->setString(str);
        }
    }

    linefeeds.clear();
    linefeeds.push_back(-1); //beginning
    pos = 0;
    while(true)
    {
        pos = str.find_first_of("\n", pos + 1);
        if(pos != std::string::npos)
        {
            linefeeds.push_back(pos);
        }
        else
        {
            break;
        }
    }
    linefeeds.push_back(str.size()); //ye endd
}

void TextEditor::setText(sf::Text* t, sf::Font* f)
{
    TextComponent::setText(t, f);
    formatText();

    lineHeight = t->getCharacterSize() * 8/7;
    charWidth = (int)(lineHeight * heightToWidth);
}

void TextEditor::selectWord()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    int y = mousePos.y - text->getPosition().y;
    int line = y / lineHeight;
    int x = mousePos.x - text->getPosition().x;
    int character = x / charWidth + 1;
    int maxLine = linefeeds.size() - 2;

    if(line <= maxLine && line >= 0)
    {
        std::string str;
        std::string substr;
        str = text->getString();
        int a = linefeeds[line] + 1;
        int b = linefeeds[line + 1] - linefeeds[line] - 1;
        // std::cout << a << " " << b << " " << line << " " << linefeeds[line] << " " << linefeeds.size() << "\n";
        substr = str.substr(a, b); //current line string
        int maxChar = substr.size() + 1;
        if(character <= maxChar && character > 0)
        {
            char c = substr[character - 1];
            if(specialCharacters.find(c) == std::string::npos)
            {
                int start = substr.find_last_of(specialCharacters, character - 1) + 1;
                int end = substr.find_first_of(specialCharacters, character - 1);
                if(end < start)
                    end = substr.size();
                int wordLength = end - start;
                sf::Vector2f size(wordLength * charWidth, lineHeight);
                sf::RectangleShape* rect = new sf::RectangleShape(size);
                int x = text->getPosition().x;
                int y = text->getPosition().y;
                rect->setPosition(x + start * charWidth, y + line * lineHeight);
                sf::Color col(50, 80, 150);
                rect->setFillColor(col);

                selectionRect = rect;
                // std::cout << "created a selection rect" << "\n";
            }
        }
    }
}

sf::RectangleShape* TextEditor::getSelectionRect()
{
    return selectionRect;
}