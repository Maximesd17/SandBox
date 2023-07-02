/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** KeyboardMoves
*/

#include "KeyboardMoves.hpp"
#include <SFML/Window/Keyboard.hpp>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Game::Player::Moves::KeyboardMoves::KeyboardMoves()
{
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::Game::Player::Moves::KeyboardMoves::~KeyboardMoves()
{
}

/*********computeDirection*********/
/* Compute direction function     */
/*********computeDirection*********/
void MySandBox::Game::Player::Moves::KeyboardMoves::computeDirection()
{
    sf::Vector2f direction = {0, 0};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;
    _lastMove = direction;
}

/*********events************/
/* Event handling function */
/*********events************/
void MySandBox::Game::Player::Moves::KeyboardMoves::events(sf::Event& event)
{
    computeDirection();
}

/*********getLastMove*********/
/* Get the last move         */
/*********getLastMove*********/
sf::Vector2f MySandBox::Game::Player::Moves::KeyboardMoves::getLastMove()
{
    return _lastMove;
}
