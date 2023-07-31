#include "SSWinGame.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SubScenes::SSWinGame::SSWinGame(MySandBox::State &state, MySandBox::Game::Game &game)
    : MySandBox::Scenes::SubScenes::ASubScene(state, game),
    _restart_button("Restart", sf::Vector2i(800, 300), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()),
    _return_button("Main Menu", sf::Vector2i(800, 450), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()) {}

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
    sf::RenderWindow &window = _game.getWindow();

    _restart_button.display(window);
    _return_button.display(window);
    if (_restart_button.check(window)){
        _state.setScene(MySandBox::Scenes::GAME);
        _game.setGameState(MySandBox::Game::PENDING);
        _game.reset();
    }
    if (_return_button.check(window)){
        _state.setScene(MySandBox::Scenes::MENU);
        _state.setSubScene(MySandBox::Scenes::MAIN);
        _game.setGameState(MySandBox::Game::PENDING);
    }
    //_game.update();
}

/*********display*********/
/* Display function */
/*********display*********/
void MySandBox::Scenes::SubScenes::SSWinGame::display()
{
    sf::RenderWindow &window = _game.getWindow();
    _return_button.display(window);
    _return_button.makeSound();
}