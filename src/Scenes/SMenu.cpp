/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SMenu
*/

#include "SMenu.hpp"
#include "SSMainMenu.hpp"
#include "SSSettingsMenu.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SMenu::SMenu(MySandBox::State& state, MySandBox::Game::Game& game) :
    MySandBox::Scenes::AScene(state, game)
{
    _scenes[MySandBox::Scenes::MAIN] = std::make_shared<MySandBox::Scenes::SubScenes::SSMainMenu>(_state, _game);
    _scenes[MySandBox::Scenes::SETTINGS] = std::make_shared<MySandBox::Scenes::SubScenes::SSSettingsMenu>(_state, _game);
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Scenes::SMenu::~SMenu()
{
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Scenes::SMenu::update()
{
    _scenes[_state.getSubScene()]->update();
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Scenes::SMenu::display()
{
    _scenes[_state.getSubScene()]->display();
}