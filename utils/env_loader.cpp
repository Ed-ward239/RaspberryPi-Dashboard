#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cstdlib>

std::unordered_map<std::string, std::string> loadEnv(const std::string& path = ".env") {
    std::unordered_map<std::string, std::string> env;
    std::ifstream file(path);
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        // Trim spaces
        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);

        env[key] = value;

        // Optionally set system env vars
        setenv(key.c_str(), value.c_str(), 1);
    }

    return env;
}