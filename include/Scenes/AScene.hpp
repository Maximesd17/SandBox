/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** AScene
*/

#pragma once

#include "IScene.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace MySandBox {
    namespace Scenes {
        class AScene : public IScene {
            public:
                AScene(MySandBox::State &state, MySandBox::Game::Game &game);
                ~AScene();
                virtual bool events();
                virtual void update() = 0;
            protected:
                virtual void display() = 0;
                MySandBox::State &_state;
                MySandBox::Game::Game &_game;
        };
    };
};