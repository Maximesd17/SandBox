/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SGame
*/

#pragma once

#include "AScene.hpp"
#include <memory>

namespace MySandBox {
    namespace Scenes {
        class SGame: public MySandBox::Scenes::AScene {
            public:
                SGame(MySandBox::State &state, MySandBox::Game &game);
                ~SGame();
                bool events() override;
                void update() override;
                void display() override;
            protected:
            private:
                std::map<MySandBox::Scenes::Type, std::shared_ptr<MySandBox::Scenes::IScene> > _scenes;
        };
    }
};