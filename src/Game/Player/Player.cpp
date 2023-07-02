/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#include "Player.hpp"
#include <math.h>
#include <iostream>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Game::Player::Player::Player()
{
    _speed = 10;
    _gravity = 9.81;
    _jump_height = 150;
    _sprite_index = 0;
    _position = sf::Vector2f(0, 780);
    _jump_frame = 0;
    _jump_speed = 0.1;

    _state = PLAYER_IDLE;
    _direction = PlayerDirection::RIGHT;

    _moves = std::make_shared<Moves::KeyboardMoves>();
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/ 
MySandBox::Game::Player::Player::~Player()
{
}

/*********setPlayerSprites*********/
/* Set player sprites function    */
/*********setPlayerSprites*********/
void MySandBox::Game::Player::Player::setPlayerSprites(std::vector<sf::Texture>& textures)
{
    _sprites.clear();

    for (size_t i = 0; i < textures.size(); i++) {
        _sprites.push_back(sf::Sprite());
        _sprites[i].setTexture(textures[i]);
    }
}

/*********events************/
/* Event handling function */
/*********events************/
void MySandBox::Game::Player::Player::events(sf::Event& event)
{
    _moves->events(event);
}

/*********ApplyGravity*********/
/* Apply gravity function     */
/*********ApplyGravity*********/
void MySandBox::Game::Player::Player::ApplyGravity()
{
    if (_position.y < 780) {
        _position.y += _gravity;
    }
    else {
        _state = PLAYER_IDLE;
    }
}

/*********ApplyJump*********/
/* Apply jump function     */
/*********ApplyJump*********/
void MySandBox::Game::Player::Player::ApplyJump()
{
    if (_jump_frame < _jump_speed * 60) {
        _position.y -= _jump_height / (_jump_speed * 60);
        _jump_frame++;
    } else {
        _state = FALLING;
    }
}

/*********computeYMoves***********/
/* Compute Y-axis moves function */
/*********computeYMoves***********/
void MySandBox::Game::Player::Player::computeYMoves(float directionY)
{
    if (directionY < 0 && _state != JUMPING && _state != FALLING) {
        _state = JUMPING;
        _jump_frame = 0;
    }
    switch (_state) {
        case JUMPING:
            ApplyJump();
            break;
        case FALLING:
            ApplyGravity();
            break;
        default:
            break;
    }
}

/*********computeXMoves***********/
/* Compute X-axis moves function */
/*********computeXMoves***********/
void MySandBox::Game::Player::Player::computeXMoves(float directionX)
{
    _position.x += directionX * _speed;
    if (directionX < 0) {
        _direction = PlayerDirection::LEFT;
        if (_state != JUMPING && _state != FALLING)
            _state = WALKING;
    } else if (directionX > 0) {
        _direction = PlayerDirection::RIGHT;
        if (_state != JUMPING && _state != FALLING)
            _state = WALKING;
    } else if (_state != JUMPING && _state != FALLING)
        _state = PLAYER_IDLE;
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Game::Player::Player::update()
{
    sf::Vector2f direction = _moves->getLastMove();

    computeYMoves(direction.y);
    computeXMoves(direction.x);
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Game::Player::Player::display(sf::RenderWindow& window)
{
    size_t computed_index = floor(_sprite_index / 25);

    if (computed_index >= _sprites.size()) {
        _sprite_index = 0;
        computed_index = 0;
    }
    _sprites[computed_index].setPosition(_position);
    _sprites[computed_index].setScale(3, 3);
    window.draw(_sprites[computed_index]);
    _sprite_index++;
}
