#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "utility/ObjectLoader.h"

class SceneManager
{
    private:
        static std::shared_ptr<Scene> currentScene;
        static ObjectLoader loader;
        static std::string sceneFileName;
        static bool queuedNew;
    public:
        SceneManager() = delete;
        // NB we're working with just 1 active scene
        static void exitGame();
        static void queueLoading(std::string);
        static void loadScene(std::shared_ptr<Scene> sceneToLoad);
        static void drawScene();
        static void handleEvents();
        static std::shared_ptr<Scene> createSceneFromFile(std::string filePath);
};