/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SGame
*/

#include "SGame.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "SSMainGame.hpp"

MySandBox::Scenes::SGame::SGame(MySandBox::State &state, MySandBox::Game::Game &game):
    MySandBox::Scenes::AScene(state, game)
{
    _scenes[MySandBox::Scenes::MAIN] = std::make_shared<MySandBox::Scenes::SubScenes::SSMainGame>(_state, _game);
    // _scenes[MySandBox::Scenes::SETTINGS] = std::make_shared<MySandBox::Scenes::SSettingsMenu>(_state, _game);
}

MySandBox::Scenes::SGame::~SGame()
{
}


bool MySandBox::Scenes::SGame::events()
{
    sf::Event Event;
    sf::RenderWindow &window = _game.getWindow();

    while (window.pollEvent(Event)) {
        if (Event.type == sf::Event::Closed) {
            window.close();
            return true;
        }
    }
    _scenes[_state.getSubScene()]->events(Event);
    return false;
}

void MySandBox::Scenes::SGame::update()
{
    _scenes[_state.getSubScene()]->update();
}

void MySandBox::Scenes::SGame::display()
{
    _scenes[_state.getSubScene()]->display();
}