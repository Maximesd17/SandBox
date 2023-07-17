/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#include "Player.hpp"
#include <math.h>
#include <iostream>
#include <SFML/Window/Joystick.hpp>
#include "SandBox.hpp"
#include "Sound/Sound.hpp"

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
    
    _controlled_by = KEYBOARD;
    _is_moves_manual_changed = false;
    _moves[JOYSTICK] = std::make_shared<Moves::ControllerMoves>();
    _moves[KEYBOARD] = std::make_shared<Moves::KeyboardMoves>();
}

MySandBox::Game::Player::Player::~Player()
{
}


void MySandBox::Game::Player::Player::setPlayerSounds(){
    MySandBox::Game::Sound::Sound _walking_sound;
    MySandBox::Game::Sound::Sound _jumping_sound;
    _walking_sound.LoadSound("resources/sounds/footsteps.wav");
    _jumping_sound.LoadSound("resources/sounds/jump.wav");
}

void MySandBox::Game::Player::Player::setPlayerSprites(std::vector<sf::Texture>& textures)
{
    _sprites.clear();

    for (size_t i = 0; i < textures.size(); i++) {
        _sprites.push_back(sf::Sprite());
        _sprites[i].setTexture(textures[i]);
    }
}

void MySandBox::Game::Player::Player::events(sf::Event& event)
{
    if (sf::Joystick::isConnected(0) && !_is_moves_manual_changed) {
        std::cout << "GAMEPAD CONNECTED" << std::endl;
        _controlled_by = JOYSTICK;
    } else {
        std::cout << "GAMEPAD DISCONNECTED" << std::endl;
        _controlled_by = KEYBOARD;
    }
    _moves[_controlled_by]->events(event);
}

void MySandBox::Game::Player::Player::update()
{
    sf::Vector2f direction = _moves[_controlled_by]->getLastMove();
    MySandBox::Game::Sound::Sound _jump_sound;

    if (direction.y < 0 && _state != JUMPING && _state != FALLING) {
        _state = JUMPING;
        _jump_frame = 0;
    }
    if (_state == JUMPING) {
        _position.y -= _jump_height / (_jump_speed * 60);
        _jump_frame++;
        if (_jump_frame >= _jump_speed * 60)
            _state = FALLING;
    }
    if (_position.y < 780 && _state == FALLING) {
        _position.y += _gravity;
    }
    if (_position.y >= 780) {
        if (direction.y == 0 && direction.x == 0)
            _state = PLAYER_IDLE;
        _position.y = 780;
    }


    _position.x += direction.x * _speed;
    if (direction.x < 0)
        _direction = PlayerDirection::LEFT;
    else if (direction.x > 0)
        _direction = PlayerDirection::RIGHT;
    if (direction.x != 0 && _state != JUMPING && (_state != FALLING || _position.y >= 780))
        _state = WALKING;
    else if (direction.x == 0 && _state == PLAYER_IDLE)
        _state = PLAYER_IDLE;



    switch (_state) {
    case PLAYER_IDLE:
        std::cout << "idle" << std::endl;
        break;
    case WALKING:
        std::cout << "walking" << std::endl;
        _walking_sound.PlaySound();
        break;
    case JUMPING:
        std::cout << "jumping" << std::endl;
        _jump_sound.PlaySound();
        break;
    case FALLING:
        std::cout << "falling" << std::endl;
        break;
    case ATTACKING:
        std::cout << "attacking" << std::endl;
        break;
    case DEAD:
        std::cout << "dead" << std::endl;
        break;
    default:
        break;
    }
}

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