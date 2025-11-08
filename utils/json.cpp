#include "../include/json.h"
#include <sstream>

Json::Value parseJSON(const std::string& json) {
    Json::Value root;
    Json::CharReaderBuilder builder;
    std::stringstream s(json);
    JSONCPP_STRING errs;
    parseFromStream(builder, s, &root, &errs);
    return root;
}