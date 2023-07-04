/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SSMainGame
*/

#include "SSMainGame.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SubScenes::SSMainGame::SSMainGame(MySandBox::State& state, MySandBox::Game::Game& game)
    : MySandBox::Scenes::SubScenes::ASubScene(state, game)
{
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::Scenes::SubScenes::SSMainGame::~SSMainGame()
{
}

/*********events************/
/* Event handling function */
/*********events************/ 
void MySandBox::Scenes::SubScenes::SSMainGame::events(sf::Event& Event)
{
    _game.events(Event);
}

/*********update*********/
/* Update function */
/*********update*********/ 
void MySandBox::Scenes::SubScenes::SSMainGame::update()
{
    _game.update();
    if (_game.getGameState() == MySandBox::Game::State::WIN) {
        _state.setSubScene(MySandBox::Scenes::WIN);
        _game.reset();
    }
}

/*********display*********/
/* Display function */
/*********display*********/ 
void MySandBox::Scenes::SubScenes::SSMainGame::display()
{
    _game.display();
}
