#ifndef ___JSONDATA_HPP___
#define ___JSONDATA_HPP___

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <vector>

using json = nlohmann::json;
class JsonData {
public:
    JsonData(const json& j);

    void print() const;

    void writeToFile(const std::string& filename) const;

private:
    static void print_recursive(const json& j, int indent);
    json j_;
};

#endif //___JSONDATA_HPP___
