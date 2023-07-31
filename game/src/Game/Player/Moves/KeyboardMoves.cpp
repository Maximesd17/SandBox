/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** KeyboardMoves
*/

#include "KeyboardMoves.hpp"
#include <SFML/Window/Keyboard.hpp>

MySandBox::Game::Player::Moves::KeyboardMoves::KeyboardMoves()
{
    jumping_sf.loadSound("resources/sounds/jump.wav");
    walking_sf.loadSound("resources/sounds/footsteps.wav");
}

MySandBox::Game::Player::Moves::KeyboardMoves::~KeyboardMoves()
{
}

void MySandBox::Game::Player::Moves::KeyboardMoves::computeDirection()
{
    sf::Vector2f direction = sf::Vector2f(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        direction.y -= 1;
        jumping_sf.playSound();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        direction.y += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        direction.x -= 1;
        walking_sf.playSound();
        walking_sf.stopSound();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        direction.x += 1;
        walking_sf.playSound();
        walking_sf.stopSound();
    }
    _lastMove = direction;
}

void MySandBox::Game::Player::Moves::KeyboardMoves::events(sf::Event &event)
{
    computeDirection();
}

sf::Vector2f MySandBox::Game::Player::Moves::KeyboardMoves::getLastMove()
{
    return _lastMove;
}