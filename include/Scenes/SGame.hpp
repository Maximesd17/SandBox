/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SGame
*/

#pragma once

#include "ASubScene.hpp"
#include "AScene.hpp"
#include <memory>

namespace MySandBox {
    namespace Scenes {
        class SGame: public MySandBox::Scenes::AScene {
            public:
                SGame(MySandBox::State &state, MySandBox::Game::Game &game);
                ~SGame();
                bool events() override;
                void update() override;
                void display() override;
            protected:
            private:
                std::map<MySandBox::Scenes::Type, std::shared_ptr<MySandBox::Scenes::SubScenes::ISubScene> > _scenes;
        };
    }
};