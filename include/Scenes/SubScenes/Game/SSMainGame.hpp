/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SMainGame
*/

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
