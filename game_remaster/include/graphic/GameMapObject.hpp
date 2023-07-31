    #ifndef ______GAMEMAPOBJECT_HPP___
    #define ______GAMEMAPOBJECT_HPP___

    #include "GameSprite.hpp"

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

    class GameMapObject : GameSprite
    {
        public:
        enum class Types {
            AIR,
            WATER,
            GROUND,
            PLATFORM,
            MUD,
            WALL,
            BOX
        };

        private:
            Types _type = Types::AIR;
            bool _isCheckpoint = false;
            bool _isSpawn = false;
            bool _isEnd = false;
            sf::Vector2f _position;
            std::string _texture;

        public:
            GameMapObject();
            ~GameMapObject();

            Types getType() const;
            bool isCheckpoint() const;
            bool isSpawn() const;
            bool isEnd() const;
            sf::Vector2f getPosition() const;
            std::string getTexture() const;

            void setType(Types);
            void setCheckpoint();
            void setSpawn();
            void setEnd();
            void setPosition(sf::Vector2f);
            void setTexture(std::string);
            using GameSprite::getSprite;

            void display(sf::RenderWindow& window) override;
    };

    #endif //______GAMEMAPOBJECT_HPP___


