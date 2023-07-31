/*
** EPITECH PROJECT, 2023
** SandBox
** File description:
** SettingsEditor
*/

#include "SettingsEditor.hpp"
#include <iostream>
#include <vector>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Components::SettingsEditor::SettingsEditor(Game::Game& game, sf::Vector2i position, sf::Vector2f size) :
    AScrollableView(sf::Vector2f(size.x, size.y), game.getWindowOriginSize(), false),
    _game(game),
    _music_volume(
        "Music Volume",
        sf::Vector2i(
            size.x / 2 - 600 / 2,
            150
        ), sf::Vector2f(600, 70),
        game.getWindowOriginSize()
    ),
    _sound_volume(
        "Sound Volume",
        sf::Vector2i(
            size.x / 2 - 600 / 2,
            400
        ),
        sf::Vector2f(600, 70),
        game.getWindowOriginSize()
    ),
    _fps(
        "FPS",
        sf::FloatRect(
            size.x / 2 - 600 / 2,
            650,
            600,
            70
        ),
        game.getWindowOriginSize(),
        1
    )

{
    std::vector<std::string> list;
    list.push_back("30");
    list.push_back("60");
    list.push_back("120");
    list.push_back("240");
    _fps.setList(list);
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
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    this->checkScrollbar(mouse_pos);
    this->AScrollableView::update();

    setView(window);
    _music_volume.check(window);
    _sound_volume.check(window);
    _fps.check(window);
    window.setView(window.getDefaultView());

}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Components::SettingsEditor::display()
{
    sf::RenderWindow& window = _game.getWindow();

    this->AScrollableView::display(window);
    setView(window);
    _music_volume.display(window);
    _sound_volume.display(window);
    _fps.display(window);
    window.setView(window.getDefaultView());
}