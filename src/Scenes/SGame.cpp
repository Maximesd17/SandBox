/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SGame
*/

#include "SGame.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "SMainGame.hpp"

MySandBox::Scenes::SGame::SGame(MySandBox::State &state, MySandBox::Game &game):
    MySandBox::Scenes::AScene(state, game)
{
    _scenes[MySandBox::Scenes::MAIN] = std::make_shared<MySandBox::Scenes::SMainGame>(_state, _game);
    // _scenes[MySandBox::Scenes::SETTINGS] = std::make_shared<MySandBox::Scenes::SSettingsMenu>(_state, _game);
}

MySandBox::Scenes::SGame::~SGame()
{
}

void MySandBox::Scenes::SGame::update()
{
    _scenes[_state.getSubScene()]->update();
}

void MySandBox::Scenes::SGame::display()
{
    _game.displayMap();
    _scenes[_state.getSubScene()]->display();
}