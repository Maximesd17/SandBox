/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SSSettingsMenu
*/

#include "SSSettingsMenu.hpp"
#include <iostream>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SubScenes::SSSettingsMenu::SSSettingsMenu(MySandBox::State& state, MySandBox::Game::Game& game) :
    MySandBox::Scenes::SubScenes::ASubScene(state, game),
    _settings_editor(_game, sf::Vector2i(0, 300), sf::Vector2f(_game.getWindowOriginSize().x, _game.getWindowOriginSize().y - 200)),
    _return_button("Return", sf::Vector2i(800, _game.getWindowOriginSize().y - 150), sf::Vector2f(300, 100),
        _game.getWindowOriginSize())
{
    _font.loadFromFile("./resources/fonts/roboto.ttf");
    _title.setString("Settings");
    _title.setFont(_font);
    _title.setCharacterSize(100);
    _title.setFillColor(sf::Color::White);
    sf::Vector2f text_size = sf::Vector2f(_title.getLocalBounds().width, _title.getLocalBounds().height);
    _title.setPosition(_game.getWindowOriginSize().x / 2 - text_size.x / 2, 50);
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Scenes::SubScenes::SSSettingsMenu::~SSSettingsMenu()
{
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Scenes::SubScenes::SSSettingsMenu::update()
{
    sf::RenderWindow& window = _game.getWindow();

    if (_return_button.check(window))
        _state.setSubScene(MySandBox::Scenes::MAIN);
    _settings_editor.update();
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Scenes::SubScenes::SSSettingsMenu::display()
{
    sf::RenderWindow& window = _game.getWindow();

    window.draw(_title);
    _settings_editor.display();
    _return_button.display(window);
}
