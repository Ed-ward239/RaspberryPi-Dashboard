#pragma once
#include <string>

class Spotify {
private:
    std::string accessToken;
    std::string currentTrack;
    std::string currentArtist;

public:
    Spotify();                   // Constructor loads token from .env
    void update();               // Refresh now-playing info
    void render(int y, int x);   // Draw to ncurses dashboard
    void fetchCurrentlyPlaying();// Used in console test mode
};