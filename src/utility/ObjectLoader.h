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
        static std::vector<float> extractCoordinates(std::string const & str, std::size_t k, int count);
        static void replaceAll(std::string& str, const std::string& from, const std::string& to); // replaces all instances of [from] in [str] with [to]
    public:
        static void loadTransform(GameObject* parent, std::string line);
        static void loadSprite(GameObject* parent, std::string line);
        static void loadText(GameObject* parent, std::string line, std::string textStr);
        static void loadTextEditor(GameObject* parent, std::string line, std::string textStr);
        static void loadAnimation(GameObject*, std::string, std::vector<std::string>);
        static void loadButton(GameObject* parent, std::string line);
        // static void loadPlayGrid(GameObject* parent, std::vector<std::string>);
};