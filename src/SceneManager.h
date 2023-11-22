#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <string>

class SceneManager
{
    private:
        Scene currentScene;
        static const int NAME_SECTION;
        static const int OBJECTS_SECTION;
    public:
        // NB we're working with just 1 active scene
        void unloadScene();
        void loadScene(std::shared_ptr<Scene> sceneToLoad);
        void drawScene(sf::RenderWindow& window);

        std::shared_ptr<Scene> createSceneFromFile(std::string filePath);
};