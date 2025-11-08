#include "../include/http.h"
#include "../include/env_loader.h"
#include <iostream>
#include <curl/curl.h>

static std::unordered_map<std::string, std::string> ENV = loadEnv();

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

std::string httpGet(const std::string& url, const std::string& tokenKey) {
    CURL* curl;
    CURLcode res;
    std::string response;

    std::string token = ENV[tokenKey]; // tokenKey like "GOOGLE_ACCESS_TOKEN"
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Accept: application/json");

    if (!token.empty()) {
        std::string authHeader = "Authorization: Bearer " + token;
        headers = curl_slist_append(headers, authHeader.c_str());
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return response;
}