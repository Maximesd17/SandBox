/*
**  Epitech Pre-MSC 2023
**  End Year Project - Sandbox
*/

#include "MapGenerator.hpp"
#include "unistd.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

SandBox::MapGenerator::MapGenerator()
{
    _hasAir = false;
    _hasGround = false;
    _hasSpawn = false;
    _hasEnd = false;
    _valid = false;

    _airTexture.loadFromFile("resources/map_textures/air.png");
    _groundTexture.loadFromFile("resources/map_textures/ground.png");
    _plateformTexture.loadFromFile("resources/map_textures/plateform.png");
    _wallTexture.loadFromFile("resources/map_textures/wall.png");
    _boxTexture.loadFromFile("resources/map_textures/box.png");
    _spawnTexture.loadFromFile("resources/map_textures/start.png");
    _endTexture.loadFromFile("resources/map_textures/end.png");
}

SandBox::MapGenerator::MapGenerator(std::string& filepath, int texture_size)
{
    _hasAir = false;
    _hasGround = false;
    _hasSpawn = false;
    _hasEnd = false;
    _valid = false;

    _texture_size = texture_size;
    std::cout << "Texture size: " << _texture_size << std::endl;

    _airTexture.loadFromFile("resources/map_textures/air.png");
    _groundTexture.loadFromFile("resources/map_textures/ground.png");
    _plateformTexture.loadFromFile("resources/map_textures/plateform.png");
    _wallTexture.loadFromFile("resources/map_textures/wall.png");
    _boxTexture.loadFromFile("resources/map_textures/box.png");
    _spawnTexture.loadFromFile("resources/map_textures/start.png");
    _endTexture.loadFromFile("resources/map_textures/end.png");

    std::ifstream fs;
    std::string buf;

    _map_file = filepath;
    fs.open(_map_file, std::ios::in);
    if (!fs.is_open()) {
        std::cerr << "Error on opening file '" << _map_file << "'." << std::endl;
        return;
    }
    while (std::getline(fs, buf))
        _map.push_back(buf);
    fs.close();
    validateMap(_map);
    setKeyPoints();
}

/***************clear***************/
/*clear all value from MapGenerator*/
/***************clear***************/
void SandBox::MapGenerator::clear()
{
    _hasAir = false;
    _hasGround = false;
    _hasSpawn = false;
    _hasEnd = false;
    _valid = false;

    _map_file.clear();
    _map.clear();
    _spawnPoint = sf::FloatRect();
    _endPoint = sf::FloatRect();
    _collisionBlocks.clear();
}

void SandBox::MapGenerator::setMapFile(std::string& filepath, int texture_size)
{
    clear();
    std::ifstream fs;
    std::string buf;

    _map_file = filepath;
    _texture_size = texture_size;

    fs.open(_map_file, std::ios::in);
    if (!fs.is_open()) {
        std::cerr << "Error on opening file '" << _map_file << "'." << std::endl;
        return;
    }
    while (std::getline(fs, buf))
        _map.push_back(buf);
    fs.close();
    validateMap(_map);
    setKeyPoints();
}

std::string SandBox::MapGenerator::getMapFile()
{
    return _map_file;
}

std::vector<std::string> SandBox::MapGenerator::getMap()
{
    return _map;
}

bool SandBox::MapGenerator::isValid()
{
    return _valid;
}

bool SandBox::MapGenerator::validateMap(std::vector<std::string>& map)
{
    size_t line_length = 0;

    if (!(map.size() > 0))
        return false;
    _valid = true;
    line_length = map.at(0).length();
    for (size_t i = 0; i < map.size(); i++) {
        std::string current = map.at(i);
        if (!checkIdentifiers(current))
            _valid = false;
        if (current.length() != line_length) {
            std::cerr << "[" << _map_file << "] Map size inconsistency at line "
                << i << std::endl;
            _valid = false;
        };
        keyPoints(current);
    }
    if (!(_hasSpawn && _hasEnd)) {
        std::cerr << "[" << _map_file << "] Spawn: " << _hasSpawn << "\tEnd: " << _hasEnd << std::endl;
        _valid = false;
    }
    if (!(_hasAir && _hasGround)) {
        std::cerr << "[" << _map_file << "] Map doesn't have Air/Ground. It's not playable !" << std::endl;
        _valid = false;
    }
    return _valid;
}

/*
** Identifiers are the characters allowed in our maps.
** If there are any other characters than those specified,
** it's an error and map is invalid !
*/
bool SandBox::MapGenerator::checkIdentifiers(std::string& line)
{
    bool res = true;
    for (size_t c = 0; c < line.length(); c++) {
        char ch = line.at(c);
        if (_identifiers.find(ch) == std::string::npos) {
            std::cerr << "[" << _map_file << "] Character '" << ch << "' is not a valid Identifier." << std::endl;
            res = false;
        }
    }
    return res;
}

/*
** Checks if there is some Air and Ground.
** If not one of them, it's considered as not playable.
** Checks for 'S' identifier for spawn and 'E' identifier for end points.
** There must be exactly 1 "S" and 1 "E". No more, no less.
*/
void SandBox::MapGenerator::keyPoints(std::string& line)
{
    for (size_t c = 0; c < line.length(); c++) {
        char ch = line.at(c);
        switch (ch) {
        case '0':
            _hasAir = true;
            break;
        case 'G':
            _hasGround = true;
            break;
        case 'S':
            if (_hasSpawn) {
                std::cerr << "[" << _map_file << "] Map has several Spawn points." << std::endl;
                _valid = false;
            }
            _hasSpawn = true;
            break;
        case 'E':
            if (_hasEnd) {
                std::cerr << "[" << _map_file << "] Map has several End points." << std::endl;
                _valid = false;
            }
            _hasEnd = true;
            break;
        default:
            break;
        }
    }
}

SandBox::MapGenerator::~MapGenerator()
{
}

void SandBox::MapGenerator::setKeyPoints()
{
    for (size_t y = 0; y < _map.size(); ++y) {
        const std::string& line = _map[y];
        for (size_t x = 0; x < line.size(); ++x) {
            char ch = line[x];

            sf::Sprite tileSprite;

            switch (ch) {
            case '0':
                tileSprite.setTexture(_airTexture);
                break;
            case 'G':
                tileSprite.setTexture(_groundTexture);
                _collisionBlocks.push_back(sf::FloatRect(x * _texture_size, y * _texture_size, _texture_size, _texture_size));
                break;
            case 'P':
                tileSprite.setTexture(_plateformTexture);
                _collisionBlocks.push_back(sf::FloatRect(x * _texture_size, y * _texture_size, _texture_size, _texture_size));
                break;
            case 'W':
                tileSprite.setTexture(_wallTexture);
                _collisionBlocks.push_back(sf::FloatRect(x * _texture_size, y * _texture_size, _texture_size, _texture_size));
                break;
            case 'B':
                tileSprite.setTexture(_boxTexture);
                _collisionBlocks.push_back(sf::FloatRect(x * _texture_size, y * _texture_size, _texture_size, _texture_size));
                break;
            case 'S':
                tileSprite.setTexture(_spawnTexture);
                _spawnPoint = sf::FloatRect(x * _texture_size, y * _texture_size, _texture_size, _texture_size);
                break;
            case 'E':
                tileSprite.setTexture(_endTexture);
                _endPoint = sf::FloatRect(x * _texture_size, y * _texture_size, _texture_size, _texture_size);
                break;
            default:
                continue;
            }
            tileSprite.setPosition(x * _texture_size, y * _texture_size);
            tileSprite.scale((float)_texture_size / 40, (float)_texture_size / 40);
            _tiles.push_back(tileSprite);
        }
    }
}

void SandBox::MapGenerator::displayMap(sf::RenderWindow& _window)
{
    for (const sf::Sprite& tile : _tiles) {
        _window.draw(tile);
    }
}

sf::FloatRect SandBox::MapGenerator::getSpawnPoint()
{
    return _spawnPoint;
}

sf::FloatRect SandBox::MapGenerator::getEndPoint()
{
    return _endPoint;
}

sf::Vector2f SandBox::MapGenerator::getMapSize()
{
    return sf::Vector2f(_map[0].length() * _texture_size, _map.size() * _texture_size);
}

std::vector<sf::FloatRect> SandBox::MapGenerator::getCollisionBlocks()
{
    return _collisionBlocks;
}

SandBox::MapGenerator SandBox::MapGenerator::operator=(const SandBox::MapGenerator& other)
{
    if (this == &other)
        return *this;
    this->_map_file = std::move(other._map_file);
    this->_map = std::vector<std::string>(other._map);
    this->_spawnPoint = sf::FloatRect(other._spawnPoint);
    this->_endPoint = sf::FloatRect(other._endPoint);
    this->_hasAir = other._hasAir;
    this->_hasGround = other._hasGround;
    this->_hasSpawn = other._hasSpawn;
    this->_hasEnd = other._hasEnd;
    this->_valid = other._valid;
    return *this;
}