/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>



namespace MySandBox {
    namespace Component {
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
        class Player {
            public:
                Player();
                ~Player();
                void setPlayerSprites(std::vector<sf::Texture>&);
                void update();
                void display(sf::RenderWindow&);
            protected:
            private:
                int _speed;
                double _gravity;
                int _jump_height;
                size_t _sprite_index;
                std::vector<sf::Sprite> _sprites;
                PlayerState _state;
                PlayerDirection _direction;
        };
    }
};
