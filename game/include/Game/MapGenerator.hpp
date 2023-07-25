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
    public:
        MapGenerator();
        MapGenerator(std::string& filepath);
        void setKeyPoints();
        std::string getMapFile();
        std::vector<std::string> getMap();
        sf::Vector2f getSpawnPoint();
        sf::Vector2f getEndPoint();
        std::vector<sf::Vector2f> getCollisionPositions();
        bool validateMap(std::vector<std::string>& map);
        bool isValid();
        void displayMap(sf::RenderWindow& _window);
        void setMapFile(std::string& filepath);
        void clear();
        MapGenerator operator=(const MapGenerator& other);
        ~MapGenerator();
    private:
        std::string const _identifiers = "0GPWBSE";
        std::string _map_file;
        std::vector<std::string> _map;
        sf::Vector2f _spawnPoint;
        sf::Vector2f _endPoint;
        std::vector<sf::Vector2f> _collisionPositions;
        bool checkIdentifiers(std::string& line);
        void keyPoints(std::string& line);

        bool _hasAir;
        bool _hasGround;
        bool _hasSpawn;
        bool _hasEnd;
        bool _valid;

        sf::Texture _airTexture;
        sf::Texture _groundTexture;
        sf::Texture _plateformTexture;
        sf::Texture _wallTexture;
        sf::Texture _boxTexture;
        sf::Texture _spawnTexture;
        sf::Texture _endTexture;

        std::vector<sf::Sprite> _tiles;
    };
}; // namespace SandBox

#endif /*__SANDBOX_MAP_GENERATOR__*/