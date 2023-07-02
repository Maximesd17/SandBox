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

    _t_wall.loadFromFile("resources/textures.png", sf::IntRect(0, 0, 64, 64));
    for (size_t i = 0; i < 4; ++i) {
        _t_player.push_back(sf::Texture());
        _t_player[i].loadFromFile("resources/player.png", sf::IntRect(40 * i, 0, 40, 58));
    }
    _player.setPlayerSprites(_t_player);
    _s_wall.setTexture(_t_wall);
    _s_wall.setScale(2, 2);
}

/*********displayMap*********/
/* Display map function     */
/*********displayMap*********/
void MySandBox::Game::Game::displayMap()
{
    sf::Vector2u size = _window.getSize();
    sf::Vector2u pos = sf::Vector2u(0, size.y - 64 * 2);

    for (size_t i = 0; i < size.x / 64; ++i) {
        _s_wall.setPosition(pos.x, pos.y);
        _window.draw(_s_wall);
        pos.x += 64;
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
