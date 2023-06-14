/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#include "Player.hpp"
#include <math.h>

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

void MySandBox::Component::Player::setPlayerSprites(std::vector<sf::Texture> &textures)
{
    _sprites.clear();

    for (size_t i = 0; i < textures.size(); i++)
    {
        _sprites.push_back(sf::Sprite());
        _sprites[i].setTexture(textures[i]);
    }
}

void MySandBox::Component::Player::update()
{
}

void MySandBox::Component::Player::display(sf::RenderWindow &window)
{
    size_t computed_index = floor(_sprite_index / 25);

    if (computed_index >= _sprites.size()) {
        _sprite_index = 0;
        computed_index = 0;
    }
    _sprites[computed_index].setPosition(100, 100);
    _sprites[computed_index].setScale(3, 3);
    window.draw(_sprites[computed_index]);
    _sprite_index++;
}