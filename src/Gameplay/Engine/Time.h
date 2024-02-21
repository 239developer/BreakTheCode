#pragma once
#include <SFML/Graphics.hpp>

class Time
{
    private:
        static sf::Clock clock;
        static const float _tick; // time between ticks
        static const float _frame; // time between frames
        static float _deltaTime;
        static float _fixedDeltaTime;
        static float lastTick;
        static float lastFrame;
    public:
        static float timeSpeed; // time speed multiplier
        static float fixedDeltaTime();
        static float deltaTime();
        static bool nextTick();
        static bool nextFrame();
        Time() = delete;
};