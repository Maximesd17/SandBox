#ifndef ______GAMEMAPOBJECT_HPP___
#define ______GAMEMAPOBJECT_HPP___

#include "GameSpriteObject.hpp"

/*
** _identifiers:
** - 0 = air
** - G = ground
** - P = platform
** - W = wall
** - B = box
** - S = WATER
** - E = MUD
*/

class GameMapObject : GameSpriteObject
{
private:
    enum class Types {
        AIR,
        WATER,
        GROUND,
        PLATFORM,
        MUD,
        WALL,
        BOX
    };

public:
    Types type = Types::AIR;
    bool isCheckpoint = false;
    bool isSpawn = false;
    bool isEnd = false;
    sf::Vector2f position;
    std::string texture;

    GameMapObject() = default;
    ~GameMapObject() = default;

};

#endif //______GAMEMAPOBJECT_HPP___
