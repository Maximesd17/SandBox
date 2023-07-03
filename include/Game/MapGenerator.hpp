#ifndef __SANDBOX_MAP_GENERATOR__
#define __SANDBOX_MAP_GENERATOR__

#include <fstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

/*
** _identifiers:
** - 0 = air
** - G = ground
** - P = platform
** - W = wall
** - B = box
** - S = spawn
** - E = end
*/

namespace SandBox {
    class MapGenerator {
        private:
            std::string const _identifiers = "0GPWBSE";
            std::string _map_file;
            std::vector<std::string> _map;
            sf::Vector2i _spawnPoint;
            sf::Vector2i _endPoint;
            bool _hasAir = false;
            bool _hasGround = false;
            bool _hasSpawn = false;
            bool _hasEnd = false;
            bool _valid = false;
            bool checkIdentifiers(std::string &line);
            void keyPoints(std::string &line);
        public:
            MapGenerator(std::string &filepath);
            std::string getMapFile();
            std::vector<std::string> getMap();
            sf::Vector2i getSpawnPoint();
            sf::Vector2i getEndPoint();
            bool validateMap(std::vector<std::string> &map);
            bool isValid();
            void displayMap(sf::RenderWindow &_window);
            MapGenerator operator=(const MapGenerator &other);
            ~MapGenerator();
    };
}; // namespace SandBox

#endif /*__SANDBOX_MAP_GENERATOR__*/