/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ControllerMoves
*/

#include "ControllerMoves.hpp"
#include <SFML/Window/Joystick.hpp>


/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Game::Player::Moves::ControllerMoves::ControllerMoves()
{
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::Game::Player::Moves::ControllerMoves::~ControllerMoves()
{
}

void MySandBox::Game::Player::Moves::ControllerMoves::computeDirection(sf::Event &event)
{
    // TODO @lasamo: implementer les directions avec la manette reage le fichier keyboardMoves

}

void MySandBox::Game::Player::Moves::ControllerMoves::events(sf::Event &event)
{
}

sf::Vector2f MySandBox::Game::Player::Moves::ControllerMoves::getLastMove()
{
    return _lastMove;
}