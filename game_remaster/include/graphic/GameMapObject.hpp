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


#include <string>
#include <map>
#include <sstream>

template<typename K, typename V>
class SimpleJsonParser {
public:
    std::map<K, V> parse(const std::string& json) {
        std::map<K, V> result;

        std::istringstream jsonStream(json);
        char c;

        K key;
        V value;

        while (jsonStream >> c) {
            if (c == '{' || c == ',' || c == ':') {
                continue;
            } else if (c == '}') {
                break;
            } else if (c == '"') {
                if (key.empty()) {
                    std::getline(jsonStream, key, '"');
                } else {
                    std::getline(jsonStream, value, '"');
                    result[key] = value;

                    key.clear();
                    value.clear();
                }
            }
        }

        return result;
    }