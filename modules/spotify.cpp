#include "../headers/spotify.h"
#include "../include/env_loader.h"
#include "../include/http.h"
#include "json.h"
#include <iostream>

static std::unordered_map<std::string, std::string> ENV = loadEnv();

void Spotify::fetchCurrentlyPlaying() {
    std::string apiUrl = ENV["SPOTIFY_API"] + std::string("/me/player/currently-playing");
    std::string response = httpGet(apiUrl, "SPOTIFY_ACCESS_TOKEN");
    auto json = parseJSON(response);

    if (json.isMember("item")) {
        std::string track = json["item"]["name"].asString();
        std::string artist = json["item"]["artists"][0]["name"].asString();
        std::cout << "🎵 Now Playing: " << track << " - " << artist << std::endl;
    } else {
        std::cout << "No track currently playing." << std::endl;
    }
}