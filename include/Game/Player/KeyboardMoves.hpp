/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** KeyboardMoves
*/

#pragma once

#include "IMoves.hpp"

namespace SandBox {
    namespace Game {
        namespace Player {
            class KeyboardMoves : public IMoves {
            public:
                KeyboardMoves();
                ~KeyboardMoves();
                int getLastPlayerMove(sf::Event &event);
            protected:
            private:
            };
        }
    }
}