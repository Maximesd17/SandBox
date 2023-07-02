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
                    void events(sf::Event& event) override;
                    sf::Vector2f getLastMove() override;
                protected:
                    void computeDirection() override;
                private:
                    sf::Vector2f _lastMove;
                };
            }
        }
    }
}