#include "Scenes/SubScenes/SSPauseGame.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SubScenes::SSPauseGame::SSPauseGame(MySandBox::State &state, MySandBox::Game::Game &game)
    : MySandBox::Scenes::SubScenes::ASubScene(state, game),
        _button_continue("Continue",
                        sf::Vector2i(_game.getWindow().getSize().x / 2 - button_width / 2, _game.getWindow().getSize().y / 2 - menu_height / 2 + 10),
                        sf::Vector2f(button_width, button_height),
                        game.getWindowOriginSize()),
        _button_menu("Menu",
                        sf::Vector2i(_game.getWindow().getSize().x / 2 - button_width / 2, _game.getWindow().getSize().y / 2 - menu_height / 2 + 10 + button_height + 10),
                        sf::Vector2f(button_width, button_height),
                        game.getWindowOriginSize()),
        _button_exit("Exit",
                        sf::Vector2i(_game.getWindow().getSize().x / 2 - button_width / 2, _game.getWindow().getSize().y / 2 - menu_height / 2 + 10 + (button_height + 10) * 2),
                        sf::Vector2f(button_width, button_height),
                        game.getWindowOriginSize())
{
    uint window_x = _game.getWindow().getSize().x;
    uint window_y = _game.getWindow().getSize().y;

    _pause_background_rect.setFillColor(sf::Color(0, 0, 0, 102)); //0, 0, 0, 0.4
    _pause_background_rect.setPosition(0, 0);
    _pause_background_rect.setSize(sf::Vector2f(window_x, window_y));
    _pause_menu_rect.setFillColor(sf::Color::Black);
    _pause_menu_rect.setPosition(window_x / 2 - menu_width / 2, window_y / 2 - menu_height / 2);
    _pause_menu_rect.setSize(sf::Vector2f(menu_width, menu_height));
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Scenes::SubScenes::SSPauseGame::~SSPauseGame() {}

/*********events************/
/* Event handling function */
/*********events************/
void MySandBox::Scenes::SubScenes::SSPauseGame::events(sf::Event &e)
{
}

/*********update*********/
/* Update function */
/*********update*********/ 
void MySandBox::Scenes::SubScenes::SSPauseGame::update()
{
    sf::RenderWindow& window = _game.getWindow();

    if (_button_continue.check(window)) {
        window.setKeyRepeatEnabled(true);
        _state.setSubScene(MAIN);
    }
    if (_button_menu.check(window)) {
        window.setKeyRepeatEnabled(true);
        _state.setScene(MENU);
        _state.setSubScene(MAIN);
    }
    if (_button_exit.check(window))
        _game.getWindow().close();
}

/*********display*********/
/* Display function */
/*********display*********/ 
void MySandBox::Scenes::SubScenes::SSPauseGame::display()
{
    //  std::cout << "GAME PAUSE DISPLAY" << std::endl;
    sf::RenderWindow &window = _game.getWindow();

    _game.display();
    window.draw(_pause_background_rect);
    window.draw(_pause_menu_rect);
    _button_continue.display(window);
    _button_menu.display(window);
    _button_exit.display(window);
    _button_continue.makeSound();
    _button_menu.makeSound();
    _button_exit.makeSound();
}