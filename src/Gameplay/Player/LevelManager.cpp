#include "LevelManager.h"
#include "../../SceneManager.h"
#include <string>

const int LevelManager::maxLevel = 1;
int LevelManager::currentLevel = 1;

void LevelManager::loadNext()
{
    if(++currentLevel <= maxLevel)
    {
        SceneManager::queueLoading("Levels/level" + std::to_string(currentLevel) + ".scene");
    }
    else
    {
        currentLevel = 1;
        SceneManager::queueLoading("main.scene");
    }
}