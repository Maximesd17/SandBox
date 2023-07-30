#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <variant>

struct JsonValue;
typedef std::map<std::string, JsonValue> JsonObject;
typedef std::vector<JsonValue> JsonArray;

struct JsonValue {
    std::variant<std::string, JsonArray, JsonObject> value;
};

class JsonParser {
public:
    JsonValue parse(const std::string& str) {
        std::istringstream iss(str);
        return parse(iss);
    }

    void print(const JsonValue& data) {
        print(data, 0);
    }

private:
    JsonValue parse(std::istream& is) {
        char ch;
        is >> ch;
        if (ch == '{') {
            JsonObject m = parseMap(is);
            return {m};
        } else if (ch == '[') {
            JsonArray v = parseVector(is);
            return {v};
        } else {
            std::string value = parseString(is);
            return {value};
        }
    }

    JsonArray parseVector(std::istream& is) {
        JsonArray v;
        char ch;
        while (is >> ch && ch != ']') {
            if (ch == ',') {
                continue;
            }
            is.putback(ch);
            v.push_back(parse(is));
        }
        return v;
    }

JsonObject parseMap(std::istream& is) {
    JsonObject m;
    std::string key;
    char ch;
    bool isKey = true; // Flag to track whether we are parsing a key or a value
    while (is >> ch && ch != '}') {
        if (ch == ',') {
            continue;
        }
        if (ch == '"') {
            if (isKey) {
                key = parseString(is);
                is >> ch; // : skip
                isKey = false; // The next string will be a value
            } else {
                m[key] = parse(is);
                isKey = true; // The next string will be a key
            }
        }
    }
    return m;
}

std::string parseString(std::istream& is) {
    std::string str;
    char ch;
    bool escaped = false; // Flag to handle escaped quotes
    while (is >> ch) {
        if (ch == '\\' && !escaped) { // Escape character
            escaped = true;
            continue;
        }
        if (ch == '"' && !escaped) { // End of the string
            break;
        }
        str.push_back(ch);
        escaped = false; // Reset escape flag
    }
    return str;
}

    void print(const JsonValue& data, int indent) {
        std::string ind(indent * 2, ' ');
        if (std::holds_alternative<JsonObject>(data.value)) {
            std::cout << "{\n";
            for (const auto& kv : std::get<JsonObject>(data.value)) {
                std::cout << ind << kv.first << ": ";
                print(kv.second, indent + 1);
                std::cout << "\n";
            }
            std::cout << ind << "}";
        } else if (std::holds_alternative<JsonArray>(data.value)) {
            std::cout << "[\n";
            for (const auto& item : std::get<JsonArray>(data.value)) {
                std::cout << ind;
                print(item, indent + 1);
                std::cout << "\n";
            }
            std::cout << ind << "]";
        } else {
            std::cout << std::get<std::string>(data.value);
        }
    }
};

int main(int argc, char** argv) {
    JsonParser parser;
    for (int i = 1; i < argc; ++i) {
        std::ifstream ifs(argv[i]);
        std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
        JsonValue data = parser.parse(str);
        parser.print(data);
        std::cout << "\n";
    }
    return 0;
}
