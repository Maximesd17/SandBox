/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ASubScene
*/

#include "ASubScene.hpp"

MySandBox::Scenes::SubScenes::ASubScene::ASubScene(
    MySandBox::State& state, MySandBox::Game::Game& game
) : _state(state), _game(game)
{
}

MySandBox::Scenes::SubScenes::ASubScene::~ASubScene()
{
}

void MySandBox::Scenes::SubScenes::ASubScene::events(sf::Event& event)
{
    return;
}
