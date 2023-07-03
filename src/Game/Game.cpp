/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Game
*/

#include "Game.hpp"
#include <fstream>
#include <iostream>
#include <memory>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Game::Game::Game(sf::RenderWindow& window) : _window(window)
{
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::Game::Game::~Game()
{
}

/*********init**************/
/* Initialization function */
/*********init**************/
void MySandBox::Game::Game::init()
{
    _window_origin_size = _window.getSize();
}

/*********reset*********/
/* Reset function      */
/*********reset*********/
void MySandBox::Game::Game::reset()
{
    std::string line;

    _t_wall.loadFromFile("resources/map_textures/wall.png", sf::IntRect(0, 0, 64, 64));
    _sprite_shit.loadFromFile("resources/player.png");

    _player.setPlayerSprites(_sprite_shit);
    _s_wall.setTexture(_t_wall);
    _s_wall.setScale(2, 2);
}

/*********displayMap*********/
/* Display map function     */
/*********displayMap*********/
void MySandBox::Game::Game::displayMap()
{
/*
    sf::Vector2u size = _window.getSize();
    sf::Vector2u pos = sf::Vector2u(0, size.y - 64 * 2);

    for (size_t i = 0; i < size.x / 64; ++i) {
        _s_wall.setPosition(pos.x, pos.y);
        _window.draw(_s_wall);
        pos.x += 64;
    }*/

    std::ifstream mapFile("maps/small.txt");
    std::vector<std::string> mapData;
    std::string line;
    while (std::getline(mapFile, line)) {
        mapData.push_back(line);
    }


    mapFile.close();

    std::vector<sf::Sprite> tiles;

    sf::Texture airTexture;
    airTexture.loadFromFile("resources/map_textures/air.png");

    sf::Texture groundTexture;
    groundTexture.loadFromFile("resources/map_textures/ground.png");

    sf::Texture plateformTexture;
    plateformTexture.loadFromFile("resources/map_textures/plateform.png");

    sf::Texture wallTexture;
    wallTexture.loadFromFile("resources/map_textures/wall.png");

    sf::Texture boxTexture;
    boxTexture.loadFromFile("resources/map_textures/box.png");

    sf::Texture spawnTexture;
    spawnTexture.loadFromFile("resources/map_textures/start.png");

    sf::Texture endTexture;
    endTexture.loadFromFile("resources/map_textures/end.png");

       for (size_t y = 0; y < mapData.size(); ++y) {
        const std::string& line = mapData[y];
        for (size_t x = 0; x < line.size(); ++x) {
            char ch = line[x];

            sf::Sprite tileSprite;

            switch (ch) {
                case '0':
                    tileSprite.setTexture(airTexture);
                    break;
                case 'G':
                    tileSprite.setTexture(groundTexture);
                    break;
                case 'P':
                    tileSprite.setTexture(plateformTexture);
                    break;
                case 'W':
                    tileSprite.setTexture(wallTexture);
                    break;
                case 'B':
                    tileSprite.setTexture(boxTexture);
                    break;
                case 'S':
                    tileSprite.setTexture(spawnTexture);
                    tileSprite.setPosition(x * 32 * 4, y * 32 * 4);
                    break;
                case 'E':
                    tileSprite.setTexture(endTexture);
                    break;

                default:
                    continue;
            }

            tileSprite.setScale(4, 4);

            tileSprite.setPosition(x * 32 * 4, y * 32 * 4);

            tiles.push_back(tileSprite);

        }
    }
    for (const sf::Sprite& tile : tiles) {
    _window.draw(tile);
    }
}

/*********displayPlayer*********/
/* Display player function     */
/*********displayPlayer*********/
void MySandBox::Game::Game::displayPlayer()
{
    _player.display(_window);
}

/*********events************/
/* Event handling function */
/*********events************/
void MySandBox::Game::Game::events(sf::Event& event)
{
    _player.events(event);
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Game::Game::update()
{
    _player.update();
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Game::Game::display()
{
    displayMap();
    displayPlayer();
}

/*********getWindow**********/
/* Get the window reference */
/*********getWindow**********/
sf::RenderWindow& MySandBox::Game::Game::getWindow() const
{
    return _window;
}

/*********getWindowOriginSize*********/
/* Get the original window size      */
/*********getWindowOriginSize*********/
sf::Vector2u MySandBox::Game::Game::getWindowOriginSize() const
{
    return _window_origin_size;
}
