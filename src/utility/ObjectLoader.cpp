#include "ObjectLoader.h"
#include <iostream>

std::string ObjectLoader::getStringFromLine(std::string& str)
{
    const size_t n = str.find_first_not_of(" ");
    str = str.substr(n);
    std::string exit = str.substr(0, str.find_first_of(" "));
    // str = str.substr(str.find_first_of(" "));
    return exit;
}

sf::Texture* ObjectLoader::loadTexture(std::string path)
{
    try
    {
        sf::Texture* texture = new sf::Texture();
        texture->loadFromFile("../assets/textures/" + path );
        std::cout << "Loaded texture: [" << path << "]\n";
        return texture;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    return nullptr;
}

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

std::vector<float> ObjectLoader::extractCoordinates(std::string str, int count = 1)
{
    std::vector<float> coordinates;
    if(count < 0) return coordinates;

    char const* digits = "-0123456789";
    char const* digits_ = "0123456789.-";
    std::size_t const n = str.find_first_of(digits);
    if (n != std::string::npos)
    {
        std::size_t const m = str.find_first_not_of(digits_, n);
        std::string x = str.substr(n, m != std::string::npos ? m-n : m);
        str = str.substr(m != std::string::npos ? m : 0);
        coordinates.push_back(std::stof(x));
        std::vector<float> nextCoordinates = extractCoordinates(str, count - 1);
        coordinates.insert(coordinates.end(), nextCoordinates.begin(), nextCoordinates.end());
    }

    return coordinates;
}

std::vector<int> ObjectLoader::extractIntCoordinates(std::string& str, int count)
{
    std::vector<int> coordinates;
    if(count < 0) return coordinates;

    char const* digits = "-0123456789";
    std::size_t const n = str.find_first_of(digits);
    if (n != std::string::npos)
    {
        std::size_t const m = str.find_first_not_of(digits, n);
        std::string x = str.substr(n, m != std::string::npos ? m-n : m);
        coordinates.push_back(std::stoi(x));
        // std::cout << count << " " << std::stoi(x) << " ... " << str << " ... ";
        str = str.substr(m);
        // std::cout << str << " \n";
        std::vector<int> nextCoordinates = extractIntCoordinates(str, count - 1);
        coordinates.insert(coordinates.end(), nextCoordinates.begin(), nextCoordinates.end());
    }

    return coordinates;
}