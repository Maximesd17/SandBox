/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** MySandBox
*/

#pragma once
#include <memory>
#include "IScene.hpp"
#include "Game.hpp"
#include "State.hpp"
#include "Types.hpp"

namespace MySandBox {
    class SandBox {
        public:
            SandBox();
            ~SandBox();
            int loop();
        protected:
        private:
            sf::RenderWindow _window;
            std::map<MySandBox::Scenes::Type, std::shared_ptr<MySandBox::Scenes::IScene> > _scenes;
            MySandBox::Game _game;
            MySandBox::State _state;
    };
};