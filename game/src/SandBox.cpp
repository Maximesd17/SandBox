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

/*********Constructor*********/
/* This create a windows     */
/* using SFML lib and        */
/* init the scenes of game   */ 
/*********Constructor*********/ 
MySandBox::SandBox::SandBox() : _game(_window)
{
    _window.create(sf::VideoMode(1920, 1080), "MySandBox");
    _framerate = 60;
    _window.setFramerateLimit(_framerate);
    _game.init();
    _scenes[MySandBox::Scenes::MENU] = std::make_shared<MySandBox::Scenes::SMenu>(_state, _game);
    _scenes[MySandBox::Scenes::GAME] = std::make_shared<MySandBox::Scenes::SGame>(_state, _game);
}


/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::SandBox::~SandBox()
{
}


/**********checkElapsedTime***********/
/* Check if enough time has elapsed  */
/* based on the desired framerate    */
/**********checkElapsedTime***********/
bool MySandBox::SandBox::checkElapsedTime()
{
    if (_deltaTime.getElapsedTime().asMilliseconds() > 1000 / _framerate ||
        _deltaTime.getElapsedTime().asMilliseconds() <= 0) {
        _deltaTime.restart();
        return true;
    }
    return false;
}

/*****Main loop of the sandbox*****/
/*  a loop to cach actions        */
/*****Main loop of the sandbox*****/
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

