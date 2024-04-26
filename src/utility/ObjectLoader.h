#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "../Scene.h"
#include "../GameObject/GameObject.h"
class SceneManager;

class ObjectLoader
{
    private:
        static std::vector<float> extractCoordinates(std::string str, int maxIndex);
        static std::vector<int> extractIntCoordinates(std::string& str, int maxIndex);
        static void replaceAll(std::string& str, const std::string& from, const std::string& to); // replaces all instances of [from] in [str] with [to]
        static std::string getStringFromLine(std::string&);
    public:
        static sf::Texture* loadTexture(std::string path);
        static void loadTransform(GameObject* parent, std::string line);
        static void loadSprite(GameObject* parent, std::string line);
        static void loadText(GameObject* parent, std::string line, std::string textStr);
        static void loadTextEditor(GameObject* parent, std::string line, std::string textStr);
        static void loadAnimation(GameObject*, std::string, std::vector<std::string>);
        static void loadButton(GameObject* parent, std::string line);
        static void loadTileController(GameObject* parent, std::string line);
        static void loadTile(GameObject* parent, std::string line);
};