/*
** EPITECH PROJECT, 2023
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
    std::string mapFile("maps/collisions.txt");
    _mapGenerator = SandBox::MapGenerator(mapFile);
    _mapGenerator.displayMap(_window);

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
    winningCondition();
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Game::Game::update()
{
    std::vector<sf::Vector2f> wallPositions = _mapGenerator.getCollisionPositions();
    _player.update(wallPositions);
    sf::Vector2f endPosition = _mapGenerator.getEndPoint();

    bool hasWin = _player.checkEndPointCollision(endPosition);
    if (hasWin)
    {
        _game_state = WIN;
    }
    

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

/************winningCondition************/
/* Check for winning condition.         */
/* If player position reaches end point */
/* it return True. Otherwise, false     */
/************winningCondition************/
void MySandBox::Game::Game::winningCondition()
{
    sf::Vector2f pos = _player.getPosition();
    sf::Vector2f endPoint = _mapGenerator.getEndPoint();
    // sf::FloatRect playerBound = _player.get

    /*Temporary values before having access to real values*/
    int textures_size = 40;
    endPoint = sf::Vector2f(endPoint.x * textures_size, endPoint.y * textures_size);
    /*---------------------*/

    //std::cout << "Player: " << pos.x << ";" << pos.y << std::endl;
    //std::cout << "Endpoint: " << endPoint.x << ";" << endPoint.y << std::endl;
    /*
    ** Requires player size to check all boundaries.
    ** ATM, checking only player's origin 0;0 position
    */

   /*
    if ((size_t)pos.x >= endPoint.x &&
        (size_t)pos.x <= endPoint.x + textures_size &&
        (size_t)pos.y >= endPoint.y - textures_size &&
        (size_t)pos.y <= endPoint.y) {
        _game_state = WIN;
    } */
}

/*********getGameState*********/
/* Get game state function    */
/*********setGameState*********/
MySandBox::Game::State MySandBox::Game::Game::getGameState() const
{
    return _game_state;
}

/*********setGameState*********/
/* Set game state function    */
/*********setGameState*********/
void MySandBox::Game::Game::setGameState(MySandBox::Game::State &game_state)
{
    _game_state = game_state;
}