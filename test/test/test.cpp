#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp> // Include SFML graphics header

enum class Types {
    AIR,
    WATER,
    GROUND,
    PLATFORM,
    MUD,
    WALL,
    BOX
};

class GameMapObject {
private:
    Types type = Types::AIR;
    bool _isCheckpoint = false;
    bool _isSpawn = false;
    bool _isEnd = false;
    sf::Vector2f position;
    std::string texture;

public:
    GameMapObject() = default;
    ~GameMapObject() = default;

    Types getType() const { return type; }
    bool isCheckpoint() const { return _isCheckpoint; }
    bool isSpawn() const { return _isSpawn; }
    bool isEnd() const { return _isEnd; }
    sf::Vector2f getPosition() const { return position; }
    std::string getTexture() const { return texture; }

    void setType(Types t) { type = t; }
    void setCheckpoint(bool checkpoint) { _isCheckpoint = checkpoint; }
    void setSpawn(bool spawn) { _isSpawn = spawn; }
    void setEnd(bool end) { _isEnd = end; }
    void setPosition(sf::Vector2f pos) { position = pos; }
    void setTexture(const std::string& tex) { texture = tex; }
};


