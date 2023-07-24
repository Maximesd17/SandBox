#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class JsonPair {
public:
    std::string key;
    std::string value;

    JsonPair(const std::string& key, const std::string& value)
        : key(key), value(value) {}
};

std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return "";

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::string removeQuotes(const std::string& input) {
    std::string output;
    for (char c : input) {
        if (c != '\"') output += c;
    }
    return output;
}

// This is a very basic "parser", it will fail on any non-trivial JSON input
std::vector<JsonPair> parseJson(const std::string& line) {
    std::vector<JsonPair> result;
    std::istringstream iss(line);
    std::string token;
    std::string currentKey;
    while (std::getline(iss, token, ':')) {
        std::string trimmed = trim(token);
        if (currentKey.empty()) {
            currentKey = removeQuotes(trimmed);
        } else {
            result.push_back(JsonPair(currentKey, trimmed));
            currentKey.clear();
        }
    }
    return result;
}

int main(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i]);
        std::string line;
        while (std::getline(file, line)) {
            auto pairs = parseJson(line);
            for (const auto& pair : pairs) {
                std::cout << "Key: " << pair.key << ", Value: " << pair.value << std::endl;
            }
        }
    }
    return 0;
}
