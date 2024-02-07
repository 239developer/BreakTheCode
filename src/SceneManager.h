#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "utility/ObjectLoader.h"

class SceneManager
{
    private:
        static std::shared_ptr<Scene> currentScene;
        ObjectLoader loader;
        std::string sceneFileName;
        bool queuedNew;
    public:
        SceneManager();
        // NB we're working with just 1 active scene
        void queueLoading(std::string);
        void loadScene(std::shared_ptr<Scene> sceneToLoad);
        void drawScene(sf::RenderWindow& window);
        void handleEvents();

        std::shared_ptr<Scene> createSceneFromFile(std::string filePath);
};