/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SSSettingsMenu
*/

#include "SSSettingsMenu.hpp"
#include <iostream>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SSSettingsMenu::SSSettingsMenu(MySandBox::State& state, MySandBox::Game::Game& game) :
    MySandBox::Scenes::AScene(state, game),
    _volume_range("Volume", sf::Vector2i(800, 200), sf::Vector2f(300, 50),
        _game.getWindowOriginSize(), 0, 100, 50),
    _return_button("Return", sf::Vector2i(800, 450), sf::Vector2f(300, 100),
        _game.getWindowOriginSize())
{
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Scenes::SSSettingsMenu::~SSSettingsMenu()
{
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Scenes::SSSettingsMenu::update()
{
    sf::RenderWindow& window = _game.getWindow();

    if (_return_button.check(window))
        _state.setSubScene(MySandBox::Scenes::MAIN);
    _volume_range.check(window);
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Scenes::SSSettingsMenu::display()
{
    sf::RenderWindow& window = _game.getWindow();

    std::cout << _volume_range.getValue() << std::endl;
    _return_button.display(window);
    _volume_range.display(window);
}
