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
#include <cmath>
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
    _fontClock.loadFromFile("resources/fonts/button.ttf");
    _textClock.setFont(_fontClock);
    _textClock.setCharacterSize(30);
    _textClock.setPosition(20, 50);
    _textClock.setFillColor(sf::Color::Black);
}

/*********reset*********/
/* Reset function      */
/*********reset*********/
void MySandBox::Game::Game::reset()
{
    std::string mapFile("maps/collisions.txt");
    _mapGenerator.setMapFile(mapFile);
    _sprite_shit.loadFromFile("resources/player.png");
    _player.setPlayerSprites(_sprite_shit);
    _player.setPosition(_mapGenerator.getSpawnPoint());
    _clock.restart();
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
    sf::Time elapsedTime = _clock.getElapsedTime();
    _textClock.setString(std::to_string(round(elapsedTime.asSeconds())));
    std::vector<sf::Vector2f> wallPositions = _mapGenerator.getCollisionPositions();
    _player.update(wallPositions);
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
    displayMap();
    displayPlayer();
    _window.draw(_textClock);
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