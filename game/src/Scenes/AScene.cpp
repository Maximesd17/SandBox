/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** AScene
*/

#include "AScene.hpp"

#include <iostream>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/ 
MySandBox::Scenes::AScene::AScene(State &state, Game::Game &game) : _state(state), _game(game)
{
}

/*********Destructor*********/
/* This destroy the object  */
/*********Destructor*********/ 
MySandBox::Scenes::AScene::~AScene()
{
}

/***********events**********/
/* Event handling function */
/***********events**********/ 
bool MySandBox::Scenes::AScene::events()
{
  sf::Event event;
  sf::RenderWindow &window = _game.getWindow();

  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
      window.close();
      return true;
    }
  }
  return false;
}
