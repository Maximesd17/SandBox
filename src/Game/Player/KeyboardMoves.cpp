/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** KeyboardMoves
*/

#include "KeyboardMoves.hpp"
#include <SFML/Window/Keyboard.hpp>

SandBox::Game::Player::KeyboardMoves::KeyboardMoves()
{
}

SandBox::Game::Player::KeyboardMoves::~KeyboardMoves()
{
}

int SandBox::Game::Player::KeyboardMoves::getLastPlayerMove(sf::Event &event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return (1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return (2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return (3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return (4);
    return (0);
}