#pragma once
#include "../../GameObject/GameObject.h"
#include "../Engine/Transform.h"

class PlayerController : public Component
{
    private:
        Transform* transform;
    public:
        using Component::Component;
        virtual void setParent(GameObject*) override;
        void fixedUpdate();
};