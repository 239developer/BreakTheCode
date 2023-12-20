#include <SFML/Graphics.hpp>
#include <string>
#include "utility/ObjectLoader.h"

class SceneManager
{
    private:
        ObjectLoader loader;
        Scene currentScene;
    public:
        // NB we're working with just 1 active scene
        void unloadScene();
        void loadScene(std::shared_ptr<Scene> sceneToLoad);
        void drawScene(sf::RenderWindow& window);

        std::shared_ptr<Scene> createSceneFromFile(std::string filePath);
};