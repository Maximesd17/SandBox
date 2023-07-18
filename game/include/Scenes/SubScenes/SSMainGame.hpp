/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SMainGame
*/

#ifndef ______SMAINGAME_HPP___
#define ______SMAINGAME_HPP___

#pragma once

#include "Game.hpp"
#include "ASubScene.hpp"

namespace MySandBox {
    namespace Scenes {
        namespace SubScenes {
            class SSMainGame : public ASubScene {
            public:
                SSMainGame(MySandBox::State& state, Game::Game& game);
                ~SSMainGame();
                void events(sf::Event &event);
                void update();
                void display();
            protected:
            private:
            };
        };
    };
};

#endif //______SMAINGAME_HPP___