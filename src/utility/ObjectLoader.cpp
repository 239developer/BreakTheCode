#include "ObjectLoader.h"
#include "../GameObject/TextComponent.h"
#include "../GameObject/SpriteComponent.h"
#include "../GameObject/SceneChanger.h"
#include <iostream>

const char BUTTON_SCENECAHNGER = 'c';

void ObjectLoader::replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

std::vector<float> ObjectLoader::extractCoordinates(std::string const & str, std::size_t k = 0, int count = 1)
{
    std::vector<float> coordinates;
    if(count < 0) return coordinates;

    char const* digits = "-0123456789";
    char const* digits_ = "0123456789.-";
    std::size_t const n = str.find_first_of(digits, k);
    if (n != std::string::npos)
    {
        std::size_t const m = str.find_first_not_of(digits_, n);
        std::string x = str.substr(n, m != std::string::npos ? m-n : m);
        coordinates.push_back(std::stof(x));
        std::vector<float> nextCoordinates = extractCoordinates(str, m, count - 1);
        coordinates.insert(coordinates.end(), nextCoordinates.begin(), nextCoordinates.end());
    }

    return coordinates;
}

void ObjectLoader::loadSprite(GameObject* parent, std::string line)
{
    SpriteComponent* component = new SpriteComponent();
    std::string texturePath = line.substr(0, line.find_first_of(" "));
    sf::Texture* texture = new sf::Texture();
    try
    {
        texture->loadFromFile("../assets/textures/" + texturePath);
        std::cout << "Loaded texture: [" << texturePath << "]\n";
        sf::Sprite* sprite = new sf::Sprite();
        sprite->setTexture(*texture);

        std::vector<float> v = extractCoordinates(line.substr(line.find_first_of(" "), std::string::npos));   // extracts just 2 coordinates representing position
        const sf::Vector2f pos(v[0], v[1]);

        sprite->setPosition(pos);

        component->setSprite(sprite, texture);
        parent->addComponent(component);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}

void ObjectLoader::loadText(GameObject* parent, std::string line, std::string textStr)
{
    TextComponent* component = new TextComponent();
    std::string fontPath = line.substr(0, line.find_first_of(" "));
    sf::Font* font(new sf::Font());
    try
    {
        font->loadFromFile("../assets/fonts/" + fontPath);
        std::cout << "Loaded font: [" << fontPath << "]\n";
        sf::Text* text = new sf::Text();
        text->setFont(*font);

        std::vector<float> v = extractCoordinates(line.substr(line.find_first_of(" "), std::string::npos), 0, 5);  // extracts 6 coordinates:
        const sf::Vector2f pos(v[0], v[1]);          // 2 for position
        unsigned int size = (unsigned int)v[2];      // 1 for font size (px)
        sf::Uint8 r = (sf::Uint8)v[3];               // 3 for color (r, g, b)
        sf::Uint8 g = (sf::Uint8)v[4];
        sf::Uint8 b = (sf::Uint8)v[5];
        const sf::Color color(r, g, b);   

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

void ObjectLoader::loadButton(GameObject* parent, std::string line)
{
    try
    {
        SpriteComponent* spriteComp = parent->getComponent<SpriteComponent>();

        char c = line[0];
        line.erase(0, 2);
        switch(c)
        {
            case BUTTON_SCENECAHNGER:
                SceneChanger* button = new SceneChanger();
                button->setScene(line);
                parent->addComponent(button);
                break;
        }
        // std::cout << "Loaded a button\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}