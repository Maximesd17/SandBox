/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** KeyboardMoves
*/

#pragma once

#include "IMoves.hpp"

namespace MySandBox {
    namespace Game {
        namespace Player {
            namespace Moves {
                class KeyboardMoves : public IMoves {
                public:
                    KeyboardMoves();
                    ~KeyboardMoves();
                    void events(sf::Event& event);
                    sf::Vector2f getLastMove();
                protected:
                private:
                    void computeDirection();
                    sf::Vector2f _lastMove;
                };
            }
        }
    }
}