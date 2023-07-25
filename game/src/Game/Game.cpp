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

    _game_view.setSize(_window.getSize().x, _window.getSize().y);
    _game_view.setCenter(_window.getSize().x / 2, _window.getSize().y / 2);
    _game_view.setViewport(sf::FloatRect(0, 0, 1, 1));

}

/*********reset*********/
/* Reset function      */
/*********reset*********/
void MySandBox::Game::Game::reset()
{

    std::string mapFile("maps/large.txt");
    _mapGenerator.setMapFile(mapFile);
    _sprite_shit.loadFromFile("resources/player.png");
    _player.setPlayerSprites(_sprite_shit);
    _player.setPosition(_mapGenerator.getSpawnPoint());
    _s_wall.setTexture(_t_wall);
    _s_wall.setScale(2, 2);

}

/*********displayMap*********/
/* Display map function     */
/*********displayMap*********/
void MySandBox::Game::Game::displayMap()
{
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
   // std::cout << _game_state << std::endl;
    std::vector<sf::Vector2f> wallPositions = _mapGenerator.getCollisionPositions();
    _window.setView(_game_view);
    _player.update(wallPositions, _window);
    _game_view.setCenter(_player.getPosition());
    _window.setView(_window.getDefaultView());
    sf::Vector2f endPosition = _mapGenerator.getEndPoint();

    bool hasWin = _player.checkEndPointCollision(endPosition);
    if (hasWin) {
        _game_state = WIN;
    }
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Game::Game::display()
{
    _window.setView(_game_view);
    displayMap();
    displayPlayer();
    _window.setView(_window.getDefaultView());
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
void MySandBox::Game::Game::setGameState(MySandBox::Game::State game_state)
{
    _game_state = game_state;
}