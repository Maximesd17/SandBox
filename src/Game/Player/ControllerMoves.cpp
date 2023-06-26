/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ControllerMoves
*/

#include "ControllerMoves.hpp"
#include <SFML/Window/Joystick.hpp>

SandBox::Game::Player::ControllerMoves::ControllerMoves()
{
}

SandBox::Game::Player::ControllerMoves::~ControllerMoves()
{
}

int SandBox::Game::Player::ControllerMoves::getLastPlayerMove(sf::Event &event)
{
    if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -50)
        return (1);
    if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 50)
        return (2);
    if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -50)
        return (3);
    if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 50)
        return (4);
    return (0);
}