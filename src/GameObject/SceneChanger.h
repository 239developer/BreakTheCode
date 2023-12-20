#pragma once
#include <string>
#include "Button.h"

class SceneChanger : public Button
{
    private:
        std::string sceneFileName;
    public:
        using Button::Button;
        void setScene(std::string);
        void press() override;
};