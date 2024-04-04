#pragma once

class LevelManager
{
    private:
        static const int maxLevel;
        static int currentLevel;
    public:
        static void loadNext();
        LevelManager() = delete;
};