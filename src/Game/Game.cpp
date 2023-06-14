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

MySandBox::Game::Game(sf::RenderWindow &window) : _window(window)
{
}

MySandBox::Game::~Game()
{
}

void MySandBox::Game::init()
{
    _window_origin_size = _window.getSize();
}

void MySandBox::Game::reset()
{
    std::string line;

    _t_wall.loadFromFile("resources/textures.png", sf::IntRect(0, 0, 64, 64));
    for (size_t i = 0; i < 4; ++i)
    {
        _t_player.push_back(sf::Texture());
        _t_player[i].loadFromFile("resources/player.png", sf::IntRect(40 * i, 0, 40, 58));
    }
    _player.setPlayerSprites(_t_player);
    _s_wall.setTexture(_t_wall);
    _s_wall.setScale(2, 2);
}

void MySandBox::Game::displayMap()
{
    sf::Vector2u size = _window.getSize();
    sf::Vector2u pos = sf::Vector2u(0, size.y - 64 * 2);

    for (size_t i = 0; i < size.x / 64; ++i)
    {
        _s_wall.setPosition(pos.x, pos.y);
        _window.draw(_s_wall);
        pos.x += 64;
    }
}

void MySandBox::Game::displayPlayer()
{
    _player.display(_window);
}

sf::RenderWindow &MySandBox::Game::getWindow() const
{
    return _window;
}

sf::Vector2u MySandBox::Game::getWindowOriginSize() const
{
    return _window_origin_size;
}
