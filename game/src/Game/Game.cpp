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

    int texture_ratio = _window.getSize().y * _default_texture_size;

    _texture_size = round(texture_ratio / 1080);
}

/*********reset*********/
/* Reset function      */
/*********reset*********/
void MySandBox::Game::Game::reset()
{
    std::string mapFile("maps/large.txt");
    _mapGenerator.setMapFile(mapFile, _texture_size);
    _sprite_shit.loadFromFile("resources/player.png");
    _player.setPlayerSprites(_sprite_shit);
    sf::FloatRect rect = _mapGenerator.getSpawnPoint();
    _player.setPosition(sf::Vector2f(rect.left, rect.top));
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
}

/**********updateViewPosition*********/
/* update the position of the camera */
/**********updateViewPosition*********/
void MySandBox::Game::Game::updateViewPosition()
{
    sf::Vector2f new_pos = _player.getPosition();
    sf::Vector2f player_pos = _player.getPosition();

    if (new_pos.x < _window.getSize().x / 2)
        new_pos.x = _window.getSize().x / 2;
    if (new_pos.x > _mapGenerator.getMapSize().x - _window.getSize().x / 2)
        new_pos.x = _mapGenerator.getMapSize().x - _window.getSize().x / 2;

    if (new_pos.y < _window.getSize().y / 2)
        new_pos.y = _window.getSize().y / 2;
    if (new_pos.y > _mapGenerator.getMapSize().y - _window.getSize().y / 2)
        new_pos.y = _mapGenerator.getMapSize().y - _window.getSize().y / 2;

    _window.setView(_game_view);
    _game_view.setCenter(new_pos);
    _window.setView(_window.getDefaultView());
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Game::Game::update()
{
    updateViewPosition();
    _player.update(_mapGenerator.getCollisionBlocks(), _mapGenerator.getMapSize());

    bool hasWin = _player.checkEndPointCollision(_mapGenerator.getEndPoint());

    if (hasWin) _game_state = WIN;
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