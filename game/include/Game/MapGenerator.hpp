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
        MapGenerator(std::string& filepath, int texture_size);
        ~MapGenerator();

        sf::FloatRect getSpawnPoint();
        sf::FloatRect getEndPoint();
        sf::Vector2f getMapSize();

        std::string getMapFile();
        std::vector<std::string> getMap();
        std::vector<sf::FloatRect> getCollisionBlocks();

        MapGenerator operator=(const MapGenerator& other);
        bool validateMap(std::vector<std::string>& map);
        bool isValid();

        void setKeyPoints();
        void displayMap(sf::RenderWindow& _window);
        void setMapFile(std::string& filepath, int texture_size);
        void clear();
    private:

        bool checkIdentifiers(std::string& line);
        void keyPoints(std::string& line);

        bool _hasAir;
        bool _hasGround;
        bool _hasSpawn;
        bool _hasEnd;
        bool _valid;
        int _texture_size;

        sf::Texture _airTexture;
        sf::Texture _groundTexture;
        sf::Texture _plateformTexture;
        sf::Texture _wallTexture;
        sf::Texture _boxTexture;
        sf::Texture _spawnTexture;
        sf::Texture _endTexture;
        sf::FloatRect _spawnPoint;
        sf::FloatRect _endPoint;

        std::vector<sf::FloatRect> _collisionBlocks;
        std::string const _identifiers = "0GPWBSE";
        std::string _map_file;
        std::vector<std::string> _map;
        std::vector<sf::Sprite> _tiles;
    };
}; // namespace SandBox

#endif /*__SANDBOX_MAP_GENERATOR__*/