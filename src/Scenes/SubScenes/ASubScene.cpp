/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ASubScene
*/

#include "ASubScene.hpp"

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Scenes::SubScenes::ASubScene::ASubScene(MySandBox::State& state, MySandBox::Game::Game& game)
    : _state(state), _game(game)
{
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::Scenes::SubScenes::ASubScene::~ASubScene()
{
}

/*********events************/
/* Event handling function */
/*********events************/ 
void MySandBox::Scenes::SubScenes::ASubScene::events(sf::Event& event)
{
    return;
}

