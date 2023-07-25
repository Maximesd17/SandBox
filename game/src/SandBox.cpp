/*
** EPITECH PROJECT, 2023
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
    _window.create(sf::VideoMode(sf::VideoMode::getDesktopMode()), "MySandBox");
    _framerate = 60;
    _window.setFramerateLimit(_framerate);
    _font.loadFromFile("resources/fonts/roboto.ttf");
    _fps.setFont(_font);
    _fps.setCharacterSize(30);
    _fps.setPosition(0, 0);
    _fps.setFillColor(sf::Color::Red);
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
        _fps.setString(std::to_string(static_cast<int>(1 / _deltaTime.getElapsedTime().asSeconds())));
        _deltaTime.restart();
        return true;
    }
    return false;
}

/*****Main loop of the sandbox*****/
/*  the main loop of the game     */
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
        _window.draw(_fps);
        _window.display();
    }
    return 0;
}

