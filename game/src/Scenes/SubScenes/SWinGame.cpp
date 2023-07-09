#include "SSWinGame.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SubScenes::SSWinGame::SSWinGame(MySandBox::State &state, MySandBox::Game::Game &game)
    : MySandBox::Scenes::SubScenes::ASubScene(state, game) {}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Scenes::SubScenes::SSWinGame::~SSWinGame() {}

void MySandBox::Scenes::SubScenes::SSWinGame::events(sf::Event &e)
{
    _game.events(e);
}

void MySandBox::Scenes::SubScenes::SSWinGame::update()
{
    _game.update();
}

void MySandBox::Scenes::SubScenes::SSWinGame::display()
{
    _game.display();
}