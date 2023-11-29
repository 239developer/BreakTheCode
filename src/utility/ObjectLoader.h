#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "../Scene.h"

class ObjectLoader
{
    private:
        std::vector<float> extractCoordinates(std::string const & str, std::size_t k, int count);
        void replaceAll(std::string& str, const std::string& from, const std::string& to); // replaces all instances of [from] in [str] with [to]
    public:
        void placeTransformable(std::shared_ptr<sf::Transformable> transform, std::string line);
        void loadSprite(std::shared_ptr<Scene> scene, std::string line);
        void loadText(std::shared_ptr<Scene> scene, std::string line, std::string textStr);
};