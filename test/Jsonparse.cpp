#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include "GameMapObject.hpp"

using json = nlohmann::json;

class JsonData {
public:
    JsonData(const json& j) : j_(j) {}

    void print() const {
        print_recursive(j_, 0);
    }

private:
    static void print_recursive(const json& j, int indent) {
        std::string indent_str(indent * 2, ' ');

        if (j.is_array()) {
            std::cout << indent_str << "[\n";

            for (const auto& element : j) {
                print_recursive(element, indent + 1);
            }

            std::cout << indent_str << "]\n";
        } else if (j.is_object()) {
            std::cout << indent_str << "{\n";

            for (const auto& element : j.items()) {
                std::cout << indent_str << "  \"" << element.key() << "\": ";
                print_recursive(element.value(), indent + 1);
            }

            std::cout << indent_str << "}\n";
        } else {
            std::cout << indent_str << j << "\n";
        }
    }

    json j_;
};

class GameMap {
public:
    GameMap(int width, int height, std::vector<GameMapObject> objects)
        : width_(width), height_(height), objects_(std::move(objects)) {}

    void display() const {
        std::cout << "Height is " << height_ << "\nWidth is " << width_ << std::endl;
        int x = 1;
        for (const GameMapObject& obj : objects_) {
            std::cout << static_cast<int>(obj.getType());

            if (x >= width_) {
                std::cout << '\n';
                x = 0;
            }

            x++;
        }
    }

private:
    int width_;
    int height_;
    std::vector<GameMapObject> objects_;
};

class JsonParser {
public:

    JsonData parse_simple(const std::string& json_string) const {
        return JsonData(json::parse(json_string));
    }

GameMap parse(const std::string& json_string) const {
    auto jsonData = json::parse(json_string);

    std::vector<GameMapObject> mapObjects;
    int width = 0;
    int height = 0;

    // check if jsonData itself is an array
    if (jsonData.is_array()) {
        for (const auto& obj : jsonData) {
            // check if the element of jsonData array is an array
            if (obj.is_array()) {
                for (const auto& element : obj) {
                    // check if the element of the inner array is an object
                    if (element.is_object()) {
                        if (element.contains("width") && element.contains("height")) {
                            width = element["width"].get<int>();
                            height = element["height"].get<int>();
                        } else {
                            add_objects_from_json(element, mapObjects);
                        }
                    } else if (element.is_array()) {
                        for (const auto& innerElement : element) {
                            add_objects_from_json(innerElement, mapObjects);
                        }
                    }
                }
            } else if (obj.is_object()) {
                add_objects_from_json(obj, mapObjects);
            }
        }
    }

    return GameMap(width, height, mapObjects);
}


private:
    void add_objects_from_json(const json& j, std::vector<GameMapObject>& objects) const {
        if (j.is_object()) {
            if (j.contains("x-size") && j.contains("type") && j.contains("texture")) {
                // Create a GameMapObject for each x-size
                for (int i = 0; i < j["x-size"].get<int>(); ++i) {
                    GameMapObject obj;
                    obj.setType(parse_type(j["type"].get<std::string>()));
                    obj.setTexture(j["texture"].get<std::string>());
                    if (j.contains("start")) {
                        obj.setSpawn();
                    }
                    if (j.contains("end")) {
                        obj.setEnd();
                    }
                    objects.push_back(obj);
                }
            }
        } else if (j.is_array()) {
            for (const auto& element : j) {
                add_objects_from_json(element, objects);
            }
        }
    }

    GameMapObject::Types parse_type(const std::string& type) const {
        if (type == "AIR") {
            return GameMapObject::Types::AIR;
        } else if (type == "WATER") {
            return GameMapObject::Types::WATER;
        } else if (type == "GROUND") {
            return GameMapObject::Types::GROUND;
        } else if (type == "PLATFORM") {
            return GameMapObject::Types::PLATFORM;
        } else if (type == "MUD") {
            return GameMapObject::Types::MUD;
        } else if (type == "WALL") {
            return GameMapObject::Types::WALL;
        } else if (type == "BOX") {
            return GameMapObject::Types::BOX;
        }
        // Default type is AIR
        return GameMapObject::Types::AIR;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <path_to_json_file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cout << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    JsonParser parser;

    // JsonData jsonData = parser.parse_simple(json);
    // jsonData.print();

    GameMap map = parser.parse(json);

    // Display the map
    map.display();

    return 0;
}
