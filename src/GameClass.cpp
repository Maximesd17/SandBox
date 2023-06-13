/*
** EPITECH PROJECT, 2022
** SandBox
** File description:
** GameClass
*/

#include "GameClass.hpp"
#include "SMenu.hpp"
#include "SGame.hpp"
#include <iostream>

SandBox::GameClass::GameClass(): _game(_window)
{
    _window.create(sf::VideoMode(1920, 1080), "SandBox");
    _window.setFramerateLimit(60);
    _game.init();
    _scenes[SandBox::Scenes::MENU] = std::make_shared<SandBox::Scenes::SMenu>(_state, _game);
    _scenes[SandBox::Scenes::GAME] = std::make_shared<SandBox::Scenes::SGame>(_state, _game);
}

SandBox::GameClass::~GameClass()
{
}

int SandBox::GameClass::loop()
{
    while (_window.isOpen()) {
        _window.clear(sf::Color::Black);
        if (_scenes[_state.getScene()]->events())
            break;
        _scenes[_state.getScene()]->update();
        _scenes[_state.getScene()]->display();
        _window.display();
    }
    return 0;
}