/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SSMainGame
*/

#include "SSMainGame.hpp"

MySandBox::Scenes::SubScenes::SSMainGame::SSMainGame(MySandBox::State &state, MySandBox::Game::Game &game):
    MySandBox::Scenes::SubScenes::ASubScene(state, game)
{
}

MySandBox::Scenes::SubScenes::SSMainGame::~SSMainGame()
{
}

void MySandBox::Scenes::SubScenes::SSMainGame::events(sf::Event &Event)
{
    _game.events(Event);
}

void MySandBox::Scenes::SubScenes::SSMainGame::update()
{
    _game.update();
}

void MySandBox::Scenes::SubScenes::SSMainGame::display()
{
    _game.display();
}
