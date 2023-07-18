/*
** EPITECH PROJECT, 2023
** SandBox
** File description:
** SettingsEditor
*/

#include "Components/SettingsEditor.hpp"
#include <iostream>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Components::SettingsEditor::SettingsEditor(Game::Game& game, sf::Vector2i position, sf::Vector2f size) :
    AScrollableView(sf::FloatRect(0, 0, size.x, size.y)),
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
    )
{
    bgTexture.loadFromFile("resources/bg.png");
    background.setTexture(bgTexture);
    background.setPosition(150, 0);
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
    this->AScrollableView::update();
    sf::RenderWindow& window = _game.getWindow();

    setView(window);
    _music_volume.check(window);
    _sound_volume.check(window);
    window.setView(window.getDefaultView());

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