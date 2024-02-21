#include "ObjectLoader.h"
#include "../GameObject/SceneChanger.h"
#include <iostream>

const char BUTTON_SCENECHANGER = 'c';

void ObjectLoader::loadButton(GameObject* parent, std::string line)
{
    try
    {
        char c = line[0];
        line.erase(0, 2);
        switch(c)
        {
            case BUTTON_SCENECHANGER:
                SceneChanger* button = new SceneChanger();
                button->setScene(line);
                parent->addComponent(button);
                break;
        }
        // std::cout << "Loaded a button\n";
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}