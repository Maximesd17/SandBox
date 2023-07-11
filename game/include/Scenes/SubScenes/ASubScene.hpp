/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** ASubScene
*/

#pragma once

#include "ISubScene.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace MySandBox {
    namespace Scenes {
        namespace SubScenes {
            class ASubScene : public ISubScene {
            public:
                ASubScene(MySandBox::State& state, MySandBox::Game::Game& game);
                ~ASubScene();
                virtual void events(sf::Event& event);
                virtual void update() = 0;
            protected:
                virtual void display() = 0;
                MySandBox::State& _state;
                MySandBox::Game::Game& _game;
            };
        }
    };
};