#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

template<typename T>
class JSONParser {
public:
    T parse(const std::string& json) {
        index_ = 0;
        json_ = json;
        return parseValue();
    }

    T parseFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        std::string json;
        std::string line;
        while (std::getline(file, line)) {
            json += line;
        }
        file.close();

        return parse(json);
    }

    void print(const T& parsed) const {
        printValue(parsed);
    }

private:
    T parseValue() {
        char currentChar = peekNextChar();
        if (currentChar == '{') {
            return parseObject();
        }
        else if (currentChar == '[') {
            return parseArray();
        }
        else {
            return parsePair();
        }
    }

    std::map<std::string, T> parseObject() {
        std::map<std::string, T> result;
        consumeChar('{');
        while (peekNextChar() != '}') {
            auto key = parseValue();
            consumeChar(':');
            auto value = parseValue();
            result.emplace(std::move(key), std::move(value));
            skipWhitespace();
            if (peekNextChar() == ',') {
                consumeChar(',');
            }
        }
        consumeChar('}');
        return result;
    }

    std::vector<T> parseArray() {
        std::vector<T> result;
        consumeChar('[');
        while (peekNextChar() != ']') {
            result.push_back(parseValue());
            skipWhitespace();
            if (peekNextChar() == ',') {
                consumeChar(',');
            }
        }
        consumeChar(']');
        return result;
    }

    std::pair<std::string, T> parsePair() {
        std::string key = parseString();
        skipWhitespace();
        consumeChar(':');
        T value = parseValue();
        return std::make_pair(std::move(key), std::move(value));
    }

    std::string parseString() {
        consumeChar('"');
        std::string result;
        while (peekNextChar() != '"') {
            result.push_back(peekNextChar());
            index_++;
        }
        consumeChar('"');
        return result;
    }

    char peekNextChar() {
        skipWhitespace();
        return json_[index_];
    }

    void consumeChar(char expectedChar) {
        skipWhitespace();
        if (json_[index_] != expectedChar) {
            throw std::runtime_error("Unexpected character: " + std::string(1, json_[index_]));
        }
        index_++;
    }

    void skipWhitespace() {
        while (index_ < json_.size() && std::isspace(json_[index_])) {
            index_++;
        }
    }

    void printValue(const T& value) const {
        if constexpr (std::is_same<T, std::string>::value) {
            std::cout << "\"" << value << "\"";
        }
        else if constexpr (std::is_same<T, double>::value) {
            std::cout << value;
        }
        else if constexpr (std::is_same<T, std::map<std::string, T>>::value) {
            std::cout << "{";
            bool first = true;
            for (const auto& pair : value) {
                if (!first) {
                    std::cout << ",";
                }
                std::cout << "\"" << pair.first << "\":";
                printValue(pair.second);
                first = false;
            }
            std::cout << "}";
        }
        else if constexpr (std::is_same<T, std::vector<T>>::value) {
            std::cout << "[";
            bool first = true;
            for (const auto& element : value) {
                if (!first) {
                    std::cout << ",";
                }
                printValue(element);
                first = false;
            }
            std::cout << "]";
        }
    }

    size_t index_ = 0;
    std::string json_;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input_file.json>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    JSONParser<std::map<std::string, std::variant<std::string, double, std::map<std::string, std::variant<std::string, double>>, std::vector<std::variant<std::string, double>>>>> parser;
    try {
        auto parsed = parser.parseFile(filename);
        parser.print(parsed);
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
