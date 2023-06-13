/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#include "Player.hpp"

MySandBox::Component::Player::Player()
{
    _speed = 1;
    _gravity = 9.81;
    _jump_height = 10;
    _sprite_index = 0;
    _state = PlayerState::PLAYER_IDLE;
    _direction = PlayerDirection::RIGHT;
}

MySandBox::Component::Player::~Player()
{
}

void MySandBox::Component::Player::setPlayerSprites(std::vector<sf::Texture> textures)
{
    for (auto &texture : textures) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        _sprites.push_back(sprite);
    }
}

void MySandBox::Component::Player::update()
{
}

void MySandBox::Component::Player::display()
{
}