#include "SSWinGame.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SubScenes::SSWinGame::SSWinGame(MySandBox::State &state, MySandBox::Game::Game &game)
    : MySandBox::Scenes::SubScenes::ASubScene(state, game),
    _username("Type your Username", sf::Vector2i(750, 150), sf::Vector2f(400, 100),
    _game.getWindowOriginSize()),
    _validate_username("OK", sf::Vector2i(900, 300), sf::Vector2f(100, 50),
    _game.getWindowOriginSize()),
    _restart_button("Restart", sf::Vector2i(800, 450), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()),
    _return_button("Main Menu", sf::Vector2i(800, 600), sf::Vector2f(300, 100),
    _game.getWindowOriginSize()){
    }

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Scenes::SubScenes::SSWinGame::~SSWinGame() {}

/*********events************/
/* Event handling function */
/*********events************/
void MySandBox::Scenes::SubScenes::SSWinGame::events(sf::Event &e)
{
    _game.events(e);
    _username.handleEvent(e);
}

/*********update*********/
/* Update function */
/*********update*********/
void MySandBox::Scenes::SubScenes::SSWinGame::update()
{
    sf::RenderWindow &window = _game.getWindow();

    _username.display(window);
    _validate_username.display(window);
    _restart_button.display(window);
    _return_button.display(window);

    if (_validate_username.check(window)){
        if (_game.getWritedTimer()==false)
        {
            _game.writeWinTime(_game.getFinalTimer(), _username.getText());
            _game.setWritedTimer(true);
        }
    }
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
}