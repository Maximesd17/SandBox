#include "JsonParser.hpp"

// No implementation for set methods as requested in the header file.

// Implementations for private helper methods and constructors

// Constructors and destructor for GameMapObject
// Assuming you have a constructor for GameMapObject that takes type and texture as parameters.

// The constructor for GameMap
// Assuming you have a constructor for GameMap that takes width, height, and mapObjects as parameters.

// Implementation for the parse_type function
// This is required for the JsonParser to parse the "type" field from the JSON and convert it into GameMapObject::Types.

GameMapObject::Types JsonParser::parse_type(const std::string& type) const {
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

// Implementation for the add_objects_from_json function
// This function is a private helper that recursively adds GameMapObjects to the objects vector.

void JsonParser::add_objects_from_json(const json& j, std::vector<GameMapObject>& objects) const {
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

// Implementation for the parse function
// This function parses the JSON string and constructs the GameMap based on the JSON data.

GameMap JsonParser::parse(const std::string& json_string) const {
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


JsonData JsonParser::parse_simple(const std::string& json_string) const {
        return JsonData(json::parse(json_string));
    }