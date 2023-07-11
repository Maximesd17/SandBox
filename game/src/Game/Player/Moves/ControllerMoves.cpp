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

    // // TESTS START //

    // unsigned int buttons = gamepad.getButtonCount(0);            
    // std::cout << buttons << std::endl;

    // if(sf::Joystick::isButtonPressed(0, 0) == 1)
    //     std::cout << "Button " + std::to_string(0) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 1) == 1)
    //     std::cout << "Button " + std::to_string(1) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 2) == 1)
    //     std::cout << "Button " + std::to_string(2) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 3) == 1)
    //     std::cout << "Button " + std::to_string(3) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 4) == 1)
    //     std::cout << "Button " + std::to_string(4) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 5) == 1)
    //     std::cout << "Button " + std::to_string(5) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 6) == 1)
    //     std::cout << "Button " + std::to_string(6) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 7) == 1)
    //     std::cout << "Button " + std::to_string(7) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 8) == 1)
    //     std::cout << "Button " + std::to_string(8) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 9) == 1)
    //     std::cout << "Button " + std::to_string(9) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 10) == 1)
    //     std::cout << "Button " + std::to_string(10) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 11) == 1)
    //     std::cout << "Button " + std::to_string(11) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 12) == 1)
    //     std::cout << "Button " + std::to_string(12) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 13) == 1)
    //     std::cout << "Button " + std::to_string(13) + " is being pressed" << std::endl;
    // if(sf::Joystick::isButtonPressed(0, 14) == 1)
    //     std::cout << "Button " + std::to_string(14) + " is being pressed" << std::endl;

    // // TESTS END //



}

void MySandBox::Game::Player::Moves::ControllerMoves::events(sf::Event &event)
{
    computeDirection();
}

sf::Vector2f MySandBox::Game::Player::Moves::ControllerMoves::getLastMove()
{
    return _lastMove;
}