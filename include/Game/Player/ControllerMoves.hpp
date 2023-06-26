/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ControllerMoves
*/

#pragma once

#include "IMoves.hpp"

namespace SandBox {
    namespace Game {
        namespace Player {
            class ControllerMoves : public IMoves {
            public:
                ControllerMoves();
                ~ControllerMoves();
                int getLastPlayerMove(sf::Event &event);
            protected:
            private:
            };
        }
    }
}