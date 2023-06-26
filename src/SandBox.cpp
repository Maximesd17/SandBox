/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SandBox
*/

#include "SandBox.hpp"
#include "SMenu.hpp"
#include "SGame.hpp"
#include <iostream>

MySandBox::SandBox::SandBox(): _game(_window)
{
    _window.create(sf::VideoMode(1920, 1080), "MySandBox");
    _framerate = 60;
    _window.setFramerateLimit(_framerate);
    _game.init();
    _scenes[MySandBox::Scenes::MENU] = std::make_shared<MySandBox::Scenes::SMenu>(_state, _game);
    _scenes[MySandBox::Scenes::GAME] = std::make_shared<MySandBox::Scenes::SGame>(_state, _game);
}

MySandBox::SandBox::~SandBox()
{
}

bool MySandBox::SandBox::checkElapsedTime()
{
    if (_deltaTime.getElapsedTime().asMilliseconds() > 1000 / _framerate ||
        _deltaTime.getElapsedTime().asMilliseconds() <= 0) {
        _deltaTime.restart();
        return true;
    }
    return false;
}

int MySandBox::SandBox::loop()
{
    while (_window.isOpen()) {
        if (!checkElapsedTime())
            continue;
        _window.clear(sf::Color::Black);
        if (_scenes[_state.getScene()]->events())
            break;
        _scenes[_state.getScene()]->update();
        _scenes[_state.getScene()]->display();
        _window.display();
    }
    return 0;
}