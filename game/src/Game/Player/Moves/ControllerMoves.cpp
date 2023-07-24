/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ControllerMoves
*/

#include "ControllerMoves.hpp"
#include <SFML/Window/Joystick.hpp>
#include <iostream>

MySandBox::Game::Player::Moves::ControllerMoves::ControllerMoves()
{
}

MySandBox::Game::Player::Moves::ControllerMoves::~ControllerMoves()
{
}

void MySandBox::Game::Player::Moves::ControllerMoves::computeDirection()
{
    sf::Vector2f direction = sf::Vector2f(0, 0);
    sf::Joystick gamepad;

    if (gamepad.getAxisPosition(0, gamepad.PovX) != 0) // Left - Right
        direction.x += (gamepad.getAxisPosition(0, gamepad.PovX) / 100);
    if (gamepad.getAxisPosition(0, gamepad.X) < -1 || gamepad.getAxisPosition(0, gamepad.X) > 1) // Left - Right
        direction.x += (gamepad.getAxisPosition(0, gamepad.X) / 100);
    if(gamepad.isButtonPressed(0, 1) == 1)
        direction.y -= 1;

    _lastMove = direction;
}

void MySandBox::Game::Player::Moves::ControllerMoves::events(sf::Event &event)
{
    computeDirection();
}

sf::Vector2f MySandBox::Game::Player::Moves::ControllerMoves::getLastMove()
{
    return _lastMove;
}