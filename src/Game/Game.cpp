/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Game
*/

#include "Game.hpp"
#include <fstream>
#include <iostream>

MySandBox::Game::Game(sf::RenderWindow &window): _window(window)
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
    std::ifstream myfile(_map_path);

    _map.clear();
    if (myfile.is_open()) {
        while(getline(myfile, line)) {
            _map.push_back(line);
        }
        myfile.close();
    }
    for (int i = 0; i < 4; i++) {
        _textures.push_back(std::make_shared<sf::Texture>());
        _textures.back()->loadFromFile("ressouces/sprite_sheet.png", sf::IntRect(i * 32, 0, 32, 32));
        _sprites.push_back(std::make_shared<sf::Sprite>());
        _sprites.back()->setTexture(*_textures.back());
    }
    _t_wall.loadFromFile("ressouces/sprite_sheet.png", sf::IntRect(32, 0, 32, 32));
    _t_spike.loadFromFile("ressouces/sprite_sheet.png", sf::IntRect(64, 0, 32, 32));
    _t_player.loadFromFile("ressouces/sprite_sheet.png", sf::IntRect(96, 0, 32, 32));
    _s_wall.setTexture(_t_wall);
    _s_spike.setTexture(_t_spike);
    _s_player.setTexture(_t_player);

}

void MySandBox::Game::displayMap()
{
    for (size_t i = 0; i < _map.size(); i++) {
        for (size_t j = 0; j < _map[i].size(); j++) {
            _sprites[static_cast<int>(_map[i][j]) - '0']->setPosition(j * 32, i * 32);
            _window.draw(*_sprites[static_cast<int>(_map[i][j]) - '0']);
        }
    }
}

void MySandBox::Game::setMapPath(std::string &mapPath)
{
    _map_path = mapPath;
}

sf::RenderWindow &MySandBox::Game::getWindow() const
{
    return _window;
}

sf::Vector2u MySandBox::Game::getWindowOriginSize() const
{
    return _window_origin_size;
}
