#ifndef ___JSONPARSER_HPP___
#define ___JSONPARSER_HPP___

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include "JsonData.hpp"
#include "GameMap.hpp"
#include "GameMapObject.hpp"

using json = nlohmann::json;

class JsonParser {
public:
    JsonData parse_simple(const std::string& json_string) const;

    GameMap parse(const std::string& json_string) const;

private:
    void add_objects_from_json(const json& j, std::vector<GameMapObject>& objects) const;

    GameMapObject::Types parse_type(const std::string& type) const;
};

#endif // ___JSONPARSER_HPP___
