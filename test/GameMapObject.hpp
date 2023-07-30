    #ifndef GAMEMAPOBJECT_HPP
    #define GAMEMAPOBJECT_HPP

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

    class GameMapObject : public GameSpriteObject
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

        GameMapObject();
        ~GameMapObject() = default;

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
        // Implement the display function to satisfy the pure virtual function in GameSpriteObject.
        void display(sf::RenderWindow& window) override {
            // Your implementation to display the GameMapObject here
        }



    private:
        Types _type = Types::AIR;
        bool _isCheckpoint = false;
        bool _isSpawn = false;
        bool _isEnd = false;
        sf::Vector2f _position;
        std::string _texture;    
    };

    #endif // GAMEMAPOBJECT_HPP
