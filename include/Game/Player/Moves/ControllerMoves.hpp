/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ControllerMoves
*/

#pragma once

#include "IMoves.hpp"

namespace MySandBox {
    namespace Game {
        namespace Player {
            namespace Moves {
                class ControllerMoves : public IMoves {
                public:
                    ControllerMoves();
                    ~ControllerMoves();
                    void events(sf::Event& event);
                    sf::Vector2f getLastMove();
                protected:
                private:
                    void computeDirection(sf::Event& event);
                    sf::Vector2f _lastMove;
                };
            }
        }
    }
}