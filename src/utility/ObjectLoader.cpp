#include "ObjectLoader.h"
#include <iostream>

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
        if(x != "-")
        {
            coordinates.push_back(std::stof(x));
            count++;
        }
        std::vector<float> nextCoordinates = extractCoordinates(str, m, count - 1);
        coordinates.insert(coordinates.end(), nextCoordinates.begin(), nextCoordinates.end());
    }

    return coordinates;
}

void ObjectLoader::placeTransformable(std::shared_ptr<sf::Transformable> transform, std::string line)
{
    std::vector<float> v = extractCoordinates(line);
    const sf::Vector2f pos(v[0], v[1]);
    transform->setPosition(pos);
}

void ObjectLoader::loadSprite(std::shared_ptr<Scene> scene, std::string line)
{
    std::string texturePath = line.substr(0, line.find_first_of(" "));
    std::shared_ptr<sf::Texture> texture(new sf::Texture());
    if(texture->loadFromFile("../assets/textures/" + texturePath));
        std::cout << "Loaded texture: [" << texturePath << "]" << "\n";

    scene->textures.push_back(texture);

    std::shared_ptr<sf::Sprite> sprite(new sf::Sprite());
    const sf::Texture& const_texture = *scene->textures.back();
    sprite->setTexture(const_texture);
    
    std::vector<float> v = extractCoordinates(line);   // extracts just 2 coordinates representing position
    const sf::Vector2f pos(v[0], v[1]);
    sprite->setPosition(pos);
    
    scene->sprites.push_back(sprite);
}

void ObjectLoader::loadText(std::shared_ptr<Scene> scene, std::string line, std::string textStr)
{
    std::string fontPath = line.substr(0, line.find_first_of(" "));
    std::shared_ptr<sf::Font> font(new sf::Font());
    if(font->loadFromFile("../assets/fonts/" + fontPath));
        std::cout << "Loaded font: [" << fontPath << "]" << "\n";

    scene->fonts.push_back(font);

    std::shared_ptr<sf::Text> text(new sf::Text());
    const sf::Font& const_font = *scene->fonts.back();
    text->setFont(const_font);

    std::vector<float> v = extractCoordinates(line, 0, 5);  // extracts 6 coordinates:
    const sf::Vector2f pos(v[0], v[1]);                     // 2 for position
    unsigned int size = (unsigned int)v[2];                 // 1 for font size (px)
    sf::Uint8 r = (sf::Uint8)v[3];                          // 3 for color (r, g, b)
    sf::Uint8 g = (sf::Uint8)v[4];
    sf::Uint8 b = (sf::Uint8)v[5];
    const sf::Color color(r, g, b);          

    text->setPosition(pos); // apply extracted numbers
    text->setCharacterSize(size);
    text->setFillColor(color);

    replaceAll(textStr, "\\n", "\n");
    text->setString(textStr);

    scene->texts.push_back(text);
}