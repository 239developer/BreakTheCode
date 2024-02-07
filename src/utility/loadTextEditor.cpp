#include "ObjectLoader.h"
#include "../GameObject/TextEditor.h"
#include <iostream>

void ObjectLoader::loadTextEditor(GameObject* parent, std::string line, std::string textStr)
{
    TextEditor* component = new TextEditor();
    std::string fontPath = line.substr(0, line.find_first_of(" "));
    sf::Font* font(new sf::Font());
    try
    {
        font->loadFromFile("../assets/fonts/" + fontPath);
        std::cout << "Loaded font: [" << fontPath << "]\n";
        sf::Text* text = new sf::Text();
        text->setFont(*font);

        std::vector<float> v = extractCoordinates(line.substr(line.find_first_of(" "), std::string::npos), 0, 6);  // extracts 7 coordinates:
        const sf::Vector2f pos(v[0], v[1]);          // 2 for position
        unsigned int size = (unsigned int)v[2];      // 1 for font size (px)
        sf::Uint8 r = (sf::Uint8)v[3];               // 3 for color (r, g, b)
        sf::Uint8 g = (sf::Uint8)v[4];
        sf::Uint8 b = (sf::Uint8)v[5];
        const sf::Color color(r, g, b);   
        component->setMaxWidth(v[6]);

        text->setPosition(pos);
        text->setCharacterSize(size);
        text->setFillColor(color);

        replaceAll(textStr, "\\n", "\n");
        text->setString(textStr);

        component->setText(text, font);
        parent->addComponent(component);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}