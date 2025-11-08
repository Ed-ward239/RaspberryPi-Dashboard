#pragma once
#include <string>

class Weather {
private:
    std::string city;
    std::string apiKey;
    float temperature;
    std::string description;

public:
    Weather();            // Constructor automatically reads from .env
    void update();         // Fetch new data from API
    void render(int y, int x);  // Draw on ncurses dashboard
    void fetchAndRender(); // Used for simple console test mode
};