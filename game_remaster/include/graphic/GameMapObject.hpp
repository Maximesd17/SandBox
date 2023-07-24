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
    enum types {
            AIR,
            WATER,
            GROUND,
            PLATFORM,
            MUD,
            WALL,
            BOX
        };


    public:
        types _type = types::AIR;
        bool _isCheckpoint = false;
        bool _isSpawn = false;
        bool _isEnd = false;
        sf::Vector2f _position;
        std::string _texture;

        GameMapObject();
        ~GameMapObject();

        types getType() const;
        bool isCheckpoint() const;
        bool isSpawn() const;
        bool isEnd() const;
        sf::Vector2f getPosition() const;

        void setType(types);
        void setCheckpoint();
        void setSpawn();
        void setEnd();
        void setPosition(sf::Vector2f);

};

#endif //______GAMEMAPOBJECT_HPP___
