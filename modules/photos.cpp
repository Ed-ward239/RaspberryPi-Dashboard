#include "../include/http.h"
#include <json/json.h>

void Photos::updateFromGoogleAlbum(const std::string& albumId, const std::string& accessToken) {
    std::vector<std::string> headers = {"Authorization: Bearer " + accessToken};
    std::string url = "https://photoslibrary.googleapis.com/v1/mediaItems:search";
    std::string postBody = "{\"albumId\":\"" + albumId + "\"}";

    CURL* curl = curl_easy_init();
    std::string response;
    struct curl_slist* headerList = nullptr;
    headerList = curl_slist_append(headerList, ("Authorization: Bearer " + accessToken).c_str());
    headerList = curl_slist_append(headerList, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postBody.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headerList);

    Json::Value root;
    Json::CharReaderBuilder builder;
    std::stringstream s(response);
    JSONCPP_STRING errs;
    parseFromStream(builder, s, &root, &errs);

    for (auto& item : root["mediaItems"]) {
        photos.push_back(item["filename"].asString());
    }
}