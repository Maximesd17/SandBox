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
    _game(game),
    _music_volume(
        "Music Volume",
        sf::Vector2i(
            position.x + size.x / 2 - 300 / 2,
            position.y
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
            position.y + 150
        ),
        sf::Vector2f(300, 50),
        game.getWindowOriginSize(),
        0,
        100,
        50,
        true
    )
{
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

    _music_volume.display(window);
    _sound_volume.display(window);
}