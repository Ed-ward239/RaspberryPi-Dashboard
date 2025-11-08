#include "../headers/weather.h"
#include "../include/env_loader.h"
#include "../include/http.h"
#include "json.h"
#include <iostream>

static std::unordered_map<std::string, std::string> ENV = loadEnv();

void Weather::fetchAndRender() {
    std::string baseUrl = ENV["WEATHER_API"];
    std::string apiKey  = ENV["WEATHER_API_KEY"];
    std::string city    = ENV["WEATHER_CITY"];

    std::string url = baseUrl + "?q=" + city + "&appid=" + apiKey + "&units=metric";

    std::string response = httpGet(url, "");
    auto json = parseJSON(response);

    if (json.isMember("main")) {
        std::cout << "Weather in " << city << ": " << json["main"]["temp"].asFloat() << "°C" << std::endl;
    } else {
        std::cout << "Failed to fetch weather data." << std::endl;
    }
}