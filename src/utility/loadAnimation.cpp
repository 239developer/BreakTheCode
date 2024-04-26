#include "ObjectLoader.h"
#include "../GameObject/AnimationComponent.h"
#include <iostream>

void ObjectLoader::loadAnimation(GameObject* parent, std::string line, std::vector<std::string> lines)
{
    AnimationComponent* component = new AnimationComponent();
    std::string atlasPath = line.substr(0, line.find_first_of(" "));
    sf::Image* image(new sf::Image());
    try
    {
        image->loadFromFile("../assets/atlases/" + atlasPath);
        std::cout << "Loaded atlas: [" << atlasPath << "]\n";
        std::vector<sf::IntRect> textureBounds;
        std::vector<int> timecodes;

        for(std::string str : lines)
        {
            std::vector<float> v = extractCoordinates(str, 4);
            sf::IntRect rect((int)v[1], (int)v[2], (int)v[3], (int)v[4]);
            int timecode = (int)v[0];
            textureBounds.push_back(rect);
            timecodes.push_back(timecode);
        }

        component->setAnimation(image, textureBounds, timecodes);
        std::vector<float> v = extractCoordinates(line.substr(line.find_first_of(" "), std::string::npos), 1);   // extracts just 2 coordinates representing position
        const sf::Vector2f pos(v[0], v[1]);
        component->getSprite()->setPosition(pos);
        component->setLoop(true);
        parent->addComponent(component);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}