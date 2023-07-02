/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#include "Player.hpp"
#include <math.h>
#include <iostream>
#include <cmath>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Game::Player::Player::Player()
{
    _speed = 10;
    _gravity = 9.81;
    _jump_height = 150;
    _position = sf::Vector2f(0, 835);
    _idle_frame = 0;
    _idle_speed = 1 * 60; // 60 = default frame rate
    _jump_frame = 0;
    _jump_speed = 0.1 * 60; // 60 = default frame rate

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
void MySandBox::Game::Player::Player::setPlayerSprites(sf::Texture& sprite_shit)
{
    _player.setTexture(sprite_shit);
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
    if (_position.y < 835) {
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
    if (_jump_frame < _jump_speed) {
        _position.y -= _jump_height / _jump_speed;
        _jump_frame++;
    }
    else {
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
void MySandBox::Game::Player::Player::setIdleFrame()
{
    if (_idle_frame >= _idle_speed) _idle_frame = 0;

    const int frame_to_display = floor(4 / _idle_speed * _idle_frame);

    _player.setTextureRect({ 40 * frame_to_display, 0 + 58 * (int)_direction, 40, 58 });
    _idle_frame++;
}

void MySandBox::Game::Player::Player::setWalkingFrame()
{
    _player.setTextureRect({ 0, 0 + 58 * (int)_direction, 40, 58 });
}

void MySandBox::Game::Player::Player::setJumpingFrame()
{
    const int frame_to_display = floor(4 / _jump_speed * _jump_frame);

    _player.setTextureRect({ 40 * frame_to_display, 116 + 58 * (int)_direction, 40, 58 });
}

void MySandBox::Game::Player::Player::setFallingFrame()
{
    _player.setTextureRect({ 120, 116 + 58 * (int)_direction, 40, 58 });
}

void MySandBox::Game::Player::Player::setAttackingFrame()
{
    std::cout << "setAttackingFrame" << std::endl;
}

void MySandBox::Game::Player::Player::setDeadFrame()
{
    std::cout << "setDeadFrame" << std::endl;
}

void MySandBox::Game::Player::Player::display(sf::RenderWindow& window)
{
    _sprite_index++;
    switch (_state) {
    case PLAYER_IDLE:
        setIdleFrame();
        break;
    case WALKING:
        setWalkingFrame();
        break;
    case JUMPING:
        setJumpingFrame();
        break;
    case FALLING:
        setFallingFrame();
        break;
    case ATTACKING:
        setAttackingFrame();
        break;
    case DEAD:
        setDeadFrame();
        break;
    default:
        break;
    }
    _player.setPosition(_position);
    _player.setScale(5, 5);
    window.draw(_player);
}
