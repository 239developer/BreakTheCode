#include <string>
#include <vector>

std::vector<float> extract_coordinates(std::string const & str, std::size_t k = 0, int count = 1)
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
        std::vector<float> nextCoordinates = extract_coordinates(str, m, 0);
        coordinates.insert(coordinates.end(), nextCoordinates.begin(), nextCoordinates.end());
    }

    return coordinates;
}