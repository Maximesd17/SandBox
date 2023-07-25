/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SGame
*/

#include "SGame.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "SSMainGame.hpp"
#include "SSWinGame.hpp"
#include "SSPauseGame.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SGame::SGame(MySandBox::State& state, MySandBox::Game::Game& game) :
    MySandBox::Scenes::AScene(state, game)
{
    _scenes[MySandBox::Scenes::MAIN] = std::make_shared<MySandBox::Scenes::SubScenes::SSMainGame>(_state, _game);
    _scenes[MySandBox::Scenes::WIN] = std::make_shared<MySandBox::Scenes::SubScenes::SSWinGame>(_state, _game);
    _scenes[MySandBox::Scenes::PAUSE] = std::make_shared<MySandBox::Scenes::SubScenes::SSPauseGame>(_state, _game);
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Scenes::SGame::~SGame()
{
}

/*********events************/
/* Event handling function */
/*********events************/
bool MySandBox::Scenes::SGame::events()
{
    sf::Event event;
    sf::RenderWindow& window = _game.getWindow();

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return true;
        if (event.key.code == sf::Keyboard::Escape && event.type == sf::Event::KeyPressed) {
            if (_state.getSubScene() == MAIN) {
                window.setKeyRepeatEnabled(false);
                _state.setSubScene(MySandBox::Scenes::PAUSE);
                return false;
            }
            if (_state.getSubScene() == PAUSE) {
                window.setKeyRepeatEnabled(true);
                _state.setSubScene(MySandBox::Scenes::MAIN);
                return false;
            }
        }
    }
    //Should refacto scenes "events" method to return bool
    _scenes[_state.getSubScene()]->events(event);
    return false;
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Scenes::SGame::update()
{
    _scenes[_state.getSubScene()]->update();
}

/*********display*********/
/*   Display function    */
/*********display*********/
void MySandBox::Scenes::SGame::display()
{
    _scenes[_state.getSubScene()]->display();
}
