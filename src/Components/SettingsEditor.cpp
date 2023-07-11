/*
** EPITECH PROJECT, 2023
** SandBox
** File description:
** SettingsEditor
*/

#include "SettingsEditor.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Components::SettingsEditor::SettingsEditor(Game::Game& game, sf::Vector2i position, sf::Vector2f size) :
    AScrollableView(sf::FloatRect(position.x, position.y, size.x, size.y)),
    _game(game),
    _music_volume(
        "Music Volume",
        sf::Vector2i(
            position.x + size.x / 2 - 300 / 2,
            position.y + 150
        ),        sf::Vector2f(300, 50),
        game.getWindowOriginSize(),
        0,
        100,
        50,
        true
    ),
    _sound_volume(
        "Sound Volume",
        sf::Vector2i(
            position.x + size.x / 2 - 300 / 2,
            position.y + 300
        ),
        sf::Vector2f(300, 50),
        game.getWindowOriginSize(),
        0,
        100,
        50,
        true
    ),
    background(sf::Vector2f(size.x, size.y))
{
    background.setFillColor(sf::Color::Green);
    background.setPosition(0, 0);
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Components::SettingsEditor::~SettingsEditor()
{

}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Components::SettingsEditor::update()
{
    sf::RenderWindow& window = _game.getWindow();

    _music_volume.check(window);
    _sound_volume.check(window);
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Components::SettingsEditor::display()
{
    sf::RenderWindow& window = _game.getWindow();

    setView(window);
    window.draw(background);
    _music_volume.display(window);
    _sound_volume.display(window);
    window.setView(window.getDefaultView());
}