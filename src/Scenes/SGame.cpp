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

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SGame::SGame(MySandBox::State& state, MySandBox::Game::Game& game) :
    MySandBox::Scenes::AScene(state, game)
{
    _scenes[MySandBox::Scenes::MAIN] = std::make_shared<MySandBox::Scenes::SubScenes::SSMainGame>(_state, _game);
    // _scenes[MySandBox::Scenes::SETTINGS] = std::make_shared<MySandBox::Scenes::SSSettingsMenu>(_state, _game);
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
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            window.close();
            return true;
        }
    }
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
