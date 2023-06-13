/*
** EPITECH PROJECT, 2022
** SandBox
** File description:
** SandBox
*/

#pragma once
#include <memory>
#include "IScene.hpp"
#include "Game.hpp"
#include "State.hpp"
#include "Types.hpp"

namespace SandBox {
    class GameClass {
        public:
            GameClass();
            ~GameClass();
            int loop();
        protected:
        private:
            sf::RenderWindow _window;
            std::map<SandBox::Scenes::Type, std::shared_ptr<SandBox::Scenes::IScene> > _scenes;
            SandBox::Game _game;
            SandBox::State _state;
    };
};