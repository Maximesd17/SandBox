/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SSettingsMenu
*/

#include "SSettingsMenu.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SSettingsMenu::SSettingsMenu(MySandBox::State &state, MySandBox::Game::Game &game) :
    MySandBox::Scenes::AScene(state, game),
    _return_button("Return", sf::Vector2i(800, 450), sf::Vector2f(300, 100),
    _game.getWindowOriginSize())
{
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::Scenes::SSettingsMenu::~SSettingsMenu()
{
}

/*********update*********/
/* Update function      */
/*********update*********/ 
void MySandBox::Scenes::SSettingsMenu::update()
{
    sf::RenderWindow &window = _game.getWindow();

    if (_return_button.check(window))
        _state.setSubScene(MySandBox::Scenes::MAIN);
}

/*********display*********/
/* Display function      */
/*********display*********/ 
void MySandBox::Scenes::SSettingsMenu::display()
{
    sf::RenderWindow &window = _game.getWindow();

    _return_button.display(window);
    _return_button.makeSound();
}
