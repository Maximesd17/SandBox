#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "GameMapObject.hpp"
std::vector<GameMapObject> parseVCBLFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<GameMapObject> mapObjects;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return mapObjects;
    }

    std::string line;
    int width = 0, height = 0;

    // Parse width and height from the first line
    if (std::getline(file, line)) {
        std::istringstream dimensions(line);
        char discard;
        dimensions >> discard >> width >> discard >> height;
    }

    // Loop through the rest of the file and create GameMapObject instances
    int x = 0, y = 0;
    while (std::getline(file, line)) {
        std::istringstream attributes(line);

        std::string attribute;
        while (std::getline(attributes, attribute, ';')) {
            std::istringstream attrStream(attribute);

            std::string key, value;
            std::getline(attrStream, key, ':');
            std::getline(attrStream, value);

            if (key == "type") {
                GameMapObject mapObject;
                if (value == "AIR")
                    mapObject.setType(GameMapObject::Types::AIR);
                else if (value == "WATER")
                    mapObject.setType(GameMapObject::Types::WATER);
                else if (value == "GROUND")
                    mapObject.setType(GameMapObject::Types::GROUND);
                else if (value == "PLATFORM")
                    mapObject.setType(GameMapObject::Types::PLATFORM);
                else if (value == "MUD")
                    mapObject.setType(GameMapObject::Types::MUD);
                else if (value == "WALL")
                    mapObject.setType(GameMapObject::Types::WALL);
                else if (value == "BOX")
                    mapObject.setType(GameMapObject::Types::BOX);

                mapObjects.push_back(mapObject);
            } else if (key == "x-size") {
                int xSize = std::stoi(value);
                for (int i = 0; i < xSize; ++i) {
                    GameMapObject mapObject;
                    mapObject.setType(GameMapObject::Types::AIR);
                    mapObject.setPosition(sf::Vector2f(x + i, y));
                    mapObject.setTexture("texture/" + value + "_" + value + ".png");
                    mapObjects.push_back(mapObject);
                }

                // Update the x coordinate for the next object
                x += xSize;
                if (x >= width) {
                    x = 0;
                    y++;
                }
            } else if (key == "start") {
                if (value == "True") {
                    // Assume the "start" attribute applies to the last added object
                    if (!mapObjects.empty()) {
                        mapObjects.back().setSpawn();
                    }
                }
            } else if (key == "end") {
                if (value == "True") {
                    // Assume the "end" attribute applies to the last added object
                    if (!mapObjects.empty()) {
                        mapObjects.back().setEnd();
                    }
                }
            }
        }
    }

    file.close();
    return mapObjects;
}

int main() {
    std::string filename = "small.vbcl";
    std::vector<GameMapObject> mapObjects = parseVCBLFile(filename);

    // Now, you can use the vector of GameMapObject instances as you need
    // For example, print some information about each object:
    for (const GameMapObject& obj : mapObjects) {
        std::cout << "Type: " << static_cast<int>(obj.getType()) << ", Texture: " << obj.getTexture()
                  << ", Position: (" << obj.getPosition().x << ", " << obj.getPosition().y << ")\n";
    }

    return 0;
}
