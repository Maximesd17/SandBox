/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** AScene
*/

#include "AScene.hpp"

MySandBox::Scenes::AScene::AScene(State &state, Game::Game &game): _state(state), _game(game)
{
}

MySandBox::Scenes::AScene::~AScene()
{
}

bool MySandBox::Scenes::AScene::events()
{
    sf::Event Event;
    sf::RenderWindow &window = _game.getWindow();

    while (window.pollEvent(Event)) {
        if (Event.type == sf::Event::Closed) {
            window.close();
            return true;
        }
    }
    return false;
}
