#include "Time.h"

const float Time::_tick = 0.02; // time between ticks
const float Time::_frame = 0.016667; // time between frames
float Time::_deltaTime = 0.016667;
float Time::_fixedDeltaTime = 0.02;
float Time::lastTick = 0.0;
float Time::lastFrame = 0.0;
float Time::timeSpeed = 1.0; // time speed multiplier

sf::Clock Time::clock;

float Time::time()
{
    return clock.getElapsedTime().asSeconds();
}

float Time::fixedDeltaTime()
{
    return _fixedDeltaTime;
}

float Time::deltaTime()
{
    return _deltaTime;
}

bool Time::nextTick()
{
    float t = clock.getElapsedTime().asSeconds();
    bool x = t - lastTick >= _tick;
    if(x)
    {
        _fixedDeltaTime = 0.9 * _fixedDeltaTime + 0.1 * (t - lastTick);
        lastTick = t;
    }
    return x;
}

bool Time::nextFrame()
{
    float t = clock.getElapsedTime().asSeconds();
    bool x = t - lastFrame >= _frame;
    if(x)
    {
        _deltaTime = 0.9 * _deltaTime + 0.1 * (t - lastFrame);
        lastFrame = t;
    }
    return x;
}