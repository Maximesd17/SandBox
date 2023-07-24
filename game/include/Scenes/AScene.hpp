/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** AScene
*/

#ifndef ______ASCENE_HPP___
#define ______ASCENE_HPP___


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

#endif //______ASCENE_HPP___