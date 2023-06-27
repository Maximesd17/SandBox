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

MySandBox::Game::Game::Game(sf::RenderWindow& window) : _window(window)
{
}

MySandBox::Game::Game::~Game()
{
}

void MySandBox::Game::Game::init()
{
    _window_origin_size = _window.getSize();
}

void MySandBox::Game::Game::reset()
{
    std::string line;

    _t_wall.loadFromFile("resources/textures.png", sf::IntRect(0, 0, 64, 64));
    _sprite_shit.loadFromFile("resources/player.png");

    _player.setPlayerSprites(_sprite_shit);
    _s_wall.setTexture(_t_wall);
    _s_wall.setScale(2, 2);
}

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

void MySandBox::Game::Game::displayPlayer()
{
    _player.display(_window);
}

void MySandBox::Game::Game::events(sf::Event& event)
{
    _player.events(event);
}

void MySandBox::Game::Game::update()
{
    _player.update();
}

void MySandBox::Game::Game::display()
{
    displayMap();
    displayPlayer();
}

sf::RenderWindow& MySandBox::Game::Game::getWindow() const
{
    return _window;
}

sf::Vector2u MySandBox::Game::Game::getWindowOriginSize() const
{
    return _window_origin_size;
}
