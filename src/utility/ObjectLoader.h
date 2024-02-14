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
        SceneManager* manager = nullptr;
        std::vector<float> extractCoordinates(std::string const & str, std::size_t k, int count);
        void replaceAll(std::string& str, const std::string& from, const std::string& to); // replaces all instances of [from] in [str] with [to]
    public:
        void setManager(SceneManager*);
        void loadSprite(GameObject* parent, std::string line);
        void loadText(GameObject* parent, std::string line, std::string textStr);
        void loadTextEditor(GameObject* parent, std::string line, std::string textStr);
        void loadAnimation(GameObject*, std::string, std::vector<std::string>);
        void loadButton(GameObject* parent, std::string line);
};