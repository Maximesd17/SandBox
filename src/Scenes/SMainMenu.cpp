/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SMainMenu
*/

#include "SMainMenu.hpp"

MySandBox::Scenes::SMainMenu::SMainMenu(MySandBox::State &state, MySandBox::Game &game):
    MySandBox::Scenes::AScene(state, game),
    _play_button("Play", sf::Vector2i(800, 450), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()),
    _settings_button("Settings", sf::Vector2i(800, 600), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()),
    _exit_button("Exit", sf::Vector2i(800, 750), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()), _map_path("maps/map.txt")
{
}

MySandBox::Scenes::SMainMenu::~SMainMenu()
{
}

void MySandBox::Scenes::SMainMenu::update()
{
    sf::RenderWindow &window = _game.getWindow();

    if (_play_button.check(window)) {
        _state.setScene(MySandBox::Scenes::GAME);
        _game.setMapPath(_map_path);
        _game.reset();
    }
    if (_settings_button.check(window))
        _state.setSubScene(MySandBox::Scenes::SETTINGS);
    if (_exit_button.check(window))
        _game.getWindow().close();
}

void MySandBox::Scenes::SMainMenu::display()
{
    sf::RenderWindow &window = _game.getWindow();

    _play_button.display(window);
    _settings_button.display(window);
    _exit_button.display(window);
}