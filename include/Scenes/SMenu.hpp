/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SMenu
*/
#ifndef ______SMENU_HPP___
#define ______SMENU_HPP___
#pragma once

#include "AScene.hpp"
#include "Button.hpp"
#include <memory>

namespace MySandBox {
    namespace Scenes {
        class SMenu: public MySandBox::Scenes::AScene {
            public:
                SMenu(MySandBox::State &state, MySandBox::Game::Game &game);
                ~SMenu();
                void update();
                void display();
            protected:
            private:
                std::map<MySandBox::Scenes::Type, std::shared_ptr<MySandBox::Scenes::IScene> > _scenes;
        };
    }
};
#endif //______SMENU_HPP___