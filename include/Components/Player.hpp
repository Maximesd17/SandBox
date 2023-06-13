/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#pragma once

namespace MySandBox {
    namespace Components {
        class Player {
            public:
                Player();
                ~Player();
                void update();
                void display();
                void computeMoves();
            protected:
            private:
                int _speed = 1;
                int _gravity = 9.81;
                bool _isJumping = false;
        };
    }
};
