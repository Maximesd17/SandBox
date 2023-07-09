/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** IPlayerMovements
*/
#ifndef ______IPLAYERMOVEMENTS_HPP___
#define ______IPLAYERMOVEMENTS_HPP___

#pragma once

#include <SFML/Window/Event.hpp>

namespace MySandBox {
    namespace Game {
        namespace Player {
            namespace Moves {
                class IMoves {
                public:
                    virtual ~IMoves() {};
                    virtual void events(sf::Event& event) = 0;
                    virtual sf::Vector2f getLastMove() = 0;
                protected:
                    virtual void computeDirection() = 0;
                private:
                };
            }
        }
    }
}

#endif //______IPLAYERMOVEMENTS_HPP___