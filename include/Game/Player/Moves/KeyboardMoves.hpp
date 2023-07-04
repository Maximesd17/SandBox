/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** KeyboardMoves
*/

#ifndef ______KEYBOARDMOVES_HPP___
#define ______KEYBOARDMOVES_HPP___

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
                    void computeDirection();
                private:
                    sf::Vector2f _lastMove;
                };
            }
        }
    }
}
#endif //______KEYBOARDMOVES_HPP___