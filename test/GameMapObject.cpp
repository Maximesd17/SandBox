#include "GameMapObject.hpp"

// Implement the member functions of GameMapObject here.

GameMapObject::GameMapObject() = default;

GameMapObject::Types GameMapObject::getType() const {
    return _type;
}

bool GameMapObject::isCheckpoint() const {
    return _isCheckpoint;
}

bool GameMapObject::isSpawn() const {
    return _isSpawn;
}

bool GameMapObject::isEnd() const {
    return _isEnd;
}

sf::Vector2f GameMapObject::getPosition() const {
    return _position;
}

std::string GameMapObject::getTexture() const {
    return _texture;
}

void GameMapObject::setType(Types type) {
    _type = type;
}

void GameMapObject::setCheckpoint() {
    _isCheckpoint = true;
}

void GameMapObject::setSpawn() {
    _isSpawn = true;
}

void GameMapObject::setEnd() {
    _isEnd = true;
}

void GameMapObject::setPosition(sf::Vector2f position) {
    _position = position;
}

void GameMapObject::setTexture(std::string texture) {
    _texture = texture;
}