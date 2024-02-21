#include "ObjectLoader.h"
#include "../Gameplay/Player/PlayerController.h"

void ObjectLoader::loadPlayer(GameObject* parent)
{
    PlayerController* controller = new PlayerController();
    parent->addComponent(controller);
}