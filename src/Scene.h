#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

class Scene {
    private:
        std::string sceneName;
    public:
        std::vector<std::shared_ptr<sf::Texture>> textures;
        std::vector<std::shared_ptr<sf::Sprite>> sprites;
        std::string name() const;
        void setName(std::string newName);
};