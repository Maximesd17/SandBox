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

/*********events************/
/* Event handling function */
/*********events************/
void MySandBox::Scenes::SubScenes::SSWinGame::events(sf::Event &e)
{
    // std::cout << "WIN STATE" << std::endl;
    _game.events(e);
}

/*********update*********/
/* Update function */
/*********update*********/ 
void MySandBox::Scenes::SubScenes::SSWinGame::update()
{
    _game.update();
}

/*********display*********/
/* Display function */
/*********display*********/ 
void MySandBox::Scenes::SubScenes::SSWinGame::display()
{
    _game.display();
}