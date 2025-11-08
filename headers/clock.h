#pragma once
#include <string>

class Clock {
public:
    Clock() = default;
    void render(int y, int x); // Draw current time (HH:MM:SS)
};