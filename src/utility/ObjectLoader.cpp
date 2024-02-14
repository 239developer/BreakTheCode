#include "ObjectLoader.h"
#include <iostream>

void ObjectLoader::setManager(SceneManager* man)
{
    manager = man;
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