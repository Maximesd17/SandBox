#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

// Forward declarations
template<typename T>
class JsonValue;

using JsonPair = std::pair<std::string, JsonValue<std::string>>;
using JsonObject = std::map<std::string, JsonValue<std::string>>;
using JsonArray = std::vector<JsonValue<std::string>>;

// Template to represent different JSON values
template<typename T>
class JsonValue {
    public:
        JsonValue(T value) : value_(value) {}
        T getValue() { return value_; }
        void print();
    private:
        T value_;
};

// Overload print for different types
template<>
void JsonValue<std::string>::print() {
    std::cout << value_ << std::endl;
}

template<>
void JsonValue<JsonArray>::print() {
    for (auto& value : value_) {
        value.print();
    }
}

template<>
void JsonValue<JsonObject>::print() {
    for (auto& pair : value_) {
        std::cout << pair.first << ": ";
        pair.second.print();
    }
}

// JSON parsing logic
class JsonParser {
    public:
        static JsonObject parse(std::string json);
        static JsonPair parsePair(std::string json);
        static JsonArray parseArray(std::string json);
};

JsonObject JsonParser::parse(std::string json) {
    JsonObject jsonObject;
    size_t position = 1;
    while (position < json.length() - 1) {
        JsonPair pair = parsePair(json.substr(position));
        jsonObject.insert(pair);
        position = json.find(',', position) + 1;
        if (position == std::string::npos) break;
    }
    return jsonObject;
}

JsonPair JsonParser::parsePair(std::string json) {
    size_t colonPosition = json.find(':');
    std::string key = json.substr(1, colonPosition - 2);
    std::string value = json.substr(colonPosition + 1);
    if (value[0] == '{') {
        return {key, JsonValue<JsonObject>(parse(value))};
    } else if (value[0] == '[') {
        return {key, JsonValue<JsonArray>(parseArray(value))};
    } else {
        return {key, JsonValue<std::string>(value.substr(1, value.find(',') - 2))};
    }
}

JsonArray JsonParser::parseArray(std::string json) {
    JsonArray jsonArray;
    size_t position = 1;
    while (position < json.length() - 1) {
        if (json[position] == '{') {
            size_t end = json.find('}', position);
            jsonArray.push_back(JsonValue<JsonObject>(parse(json.substr(position, end - position + 1))));
            position = end + 1;
        } else {
            size_t end = json.find(',', position);
            if (end == std::string::npos) end = json.length() - 1;
            jsonArray.push_back(JsonValue<std::string>(json.substr(position, end - position)));
            position = end + 1;
        }
        if (json[position] == ',') position++;
    }
    return jsonArray;
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string json((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
    JsonValue<JsonObject> root(JsonParser::parse(json));
    root.print();
    return 0;
}
