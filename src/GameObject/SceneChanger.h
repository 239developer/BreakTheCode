#pragma once
#include <string>
#include "Button.h"

class SceneChanger : public Button
{
    private:
        std::string sceneFileName;
    public:
        using Button::Button;
        void onPress();
        void setScene(std::string);
};