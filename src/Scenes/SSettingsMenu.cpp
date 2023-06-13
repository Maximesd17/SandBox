/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SSettingsMenu
*/

#include "SSettingsMenu.hpp"

MySandBox::Scenes::SSettingsMenu::SSettingsMenu(MySandBox::State &state, MySandBox::Game &game):
    MySandBox::Scenes::AScene(state, game),
    _return_button("Return", sf::Vector2i(800, 450), sf::Vector2f(300, 100),
    _game.getWindowOriginSize())
{
}

MySandBox::Scenes::SSettingsMenu::~SSettingsMenu()
{
}

void MySandBox::Scenes::SSettingsMenu::update()
{
    sf::RenderWindow &window = _game.getWindow();

    if (_return_button.check(window))
        _state.setSubScene(MySandBox::Scenes::MAIN);
}

void MySandBox::Scenes::SSettingsMenu::display()
{
    sf::RenderWindow &window = _game.getWindow();

    _return_button.display(window);
}