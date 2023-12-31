/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SMainMenu
*/

#ifndef ______SMAINMENU_HPP___
#define ______SMAINMENU_HPP___
#pragma once

#include "AScene.hpp"
#include "Button.hpp"

namespace MySandBox {
    namespace Scenes {
        class SMainMenu: public MySandBox::Scenes::AScene {
            public:
                SMainMenu(MySandBox::State &state, MySandBox::Game::Game &game);
                ~SMainMenu();
                void update();
                void display();
            protected:
            private:
                MySandBox::Components::Button _play_button;
                MySandBox::Components::Button _settings_button;
                MySandBox::Components::Button _exit_button;
                std::string _map_path;
        };
    };
};

#endif //______SMAINMENU_HPP___