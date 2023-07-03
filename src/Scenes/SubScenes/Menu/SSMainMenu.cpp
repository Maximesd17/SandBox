/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SSMainMenu
*/

#include "SSMainMenu.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/ 
MySandBox::Scenes::SSMainMenu::SSMainMenu(MySandBox::State &state, MySandBox::Game::Game &game) :
    MySandBox::Scenes::AScene(state, game),
    _play_button("Play", sf::Vector2i(800, 450), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()),
    _settings_button("Settings", sf::Vector2i(800, 600), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()),
    _exit_button("Exit", sf::Vector2i(800, 750), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()), _map_path("maps/map.txt")
{
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::Scenes::SSMainMenu::~SSMainMenu()
{
}

/*********update*********/
/* Update function */
/*********update*********/ 
void MySandBox::Scenes::SSMainMenu::update()
{
    sf::RenderWindow &window = _game.getWindow();

    if (_play_button.check(window)) {
        _state.setScene(MySandBox::Scenes::GAME);
        _game.reset();
    }
    if (_settings_button.check(window))
        _state.setSubScene(MySandBox::Scenes::SETTINGS);
    if (_exit_button.check(window))
        _game.getWindow().close();
}

/*********display*********/
/* Display function */
/*********display*********/ 
void MySandBox::Scenes::SSMainMenu::display()
{
    sf::RenderWindow &window = _game.getWindow();

    _play_button.display(window);
    _settings_button.display(window);
    _exit_button.display(window);
}
