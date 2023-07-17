/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "KeyboardMoves.hpp"
#include "ControllerMoves.hpp"
#include "Sound.hpp"

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
            LEFT,
            RIGHT
        };
        enum PlayerControlledBy {
            JOYSTICK,
            KEYBOARD
        };
        namespace Player {
            class Player {
            public:
                Player();
                ~Player();
                void setPlayerSounds();
                void setPlayerSprites(std::vector<sf::Texture>&);
                void update();
                void events(sf::Event&);
                void display(sf::RenderWindow&);

            protected:
            private:
                int _speed;
                double _gravity;
                int _jump_height;
                size_t _jump_frame;
                double _jump_speed;
                bool _is_moves_manual_changed;

                std::map<PlayerControlledBy, std::shared_ptr<MySandBox::Game::Player::Moves::IMoves> > _moves;
                sf::Vector2f _position;
                size_t _sprite_index;
                std::vector<sf::Sprite> _sprites;
                PlayerState _state;
                PlayerDirection _direction;
                PlayerControlledBy _controlled_by;
                MySandBox::Game::Sound::Sound _walking_sound;
                MySandBox::Game::Sound::Sound _jumping_sound;
            };
        }
    }
};
