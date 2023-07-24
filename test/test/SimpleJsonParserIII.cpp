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

std::string trim(const std::string& str, const std::string& whitespace = " \t")
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

void parseJson(std::istream& iss, int indent = 0) {
    std::string token;
    while (std::getline(iss, token, ':')) {
        std::string trimmed = removeQuotes(trim(token));
        std::cout << std::string(indent, ' ') << "Key: " << trimmed << "\n";
        std::getline(iss, token, ',');
        trimmed = removeQuotes(trim(token));
        if (trimmed[0] == '{') {
            parseJson(iss, indent + 2);
        } else if (trimmed[0] == '[') {
            std::cout << std::string(indent, ' ') << "Array:\n";
            parseJson(iss, indent + 2);
        } else {
            std::cout << std::string(indent, ' ') << "Value: " << trimmed << "\n";
        }
    }
}

int main(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i]);
        if (!file) {
            std::cerr << "Cannot open file: " << argv[i] << "\n";
            continue;
        }
        parseJson(file);
    }
    return 0;
}
