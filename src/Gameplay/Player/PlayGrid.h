#pragma once
#include "../../Component.h"

class PlayGrid : public Component
{
    private:

    public:
        using Component::Component;
        void gameStep();
        virtual void update() override;
};