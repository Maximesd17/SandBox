/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** IPlayerMovements
*/

#pragma once

#include <SFML/Window/Event.hpp>

namespace SandBox {
    namespace Game {
        namespace Player {
            class IMoves {
            public:
                virtual ~IMoves() {};
                virtual int getLastPlayerMove(sf::Event &event) = 0;
            protected:
            private:
            };
        }
    }
}