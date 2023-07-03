/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "KeyboardMoves.hpp"
#include "ControllerMoves.hpp"

namespace MySandBox {
    namespace Game {
        enum PlayerState {
            PLAYER_IDLE,
            WALKING,
            JUMPING,
            FALLING,
            ATTACKING,
            DEAD
        };
        enum PlayerDirection {
            RIGHT,
            LEFT,
        };
        namespace Player {
            class Player {
            public:
                Player();
                ~Player();
                void setPlayerSprites(sf::Texture&);
                void update();
                void events(sf::Event&);
                void display(sf::RenderWindow&);
                void computeYMoves(float directionY);
                void computeXMoves(float directionX);
                void ApplyGravity();
                void ApplyJump();
            protected:
            private:
                void setIdleFrame();
                void setWalkingFrame();
                void setJumpingFrame();
                void setFallingFrame();
                void setAttackingFrame();
                void setDeadFrame();

                int _speed;
                double _gravity;
                int _jump_height;
                size_t _jump_frame;
                double _jump_speed;
                size_t _idle_frame;
                double _idle_speed;

                std::shared_ptr<MySandBox::Game::Player::Moves::IMoves> _moves;
                sf::Vector2f _position;
                size_t _sprite_index;
                sf::Sprite _player;
                PlayerState _state;
                PlayerDirection _direction;
            };
        }
    }
};