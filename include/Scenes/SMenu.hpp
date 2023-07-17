/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SMenu
*/

#pragma once

#include "AScene.hpp"
#include "ASubScene.hpp"
#include <memory>

namespace MySandBox {
    namespace Scenes {
        class SMenu: public MySandBox::Scenes::AScene {
            public:
                SMenu(MySandBox::State &state, MySandBox::Game::Game &game);
                ~SMenu();
                bool events();
                void update();
                void display();
            protected:
            private:
                std::map<MySandBox::Scenes::Type, std::shared_ptr<MySandBox::Scenes::SubScenes::ISubScene> > _scenes;
        };
    }
};