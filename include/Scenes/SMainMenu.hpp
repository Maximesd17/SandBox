/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SMainMenu
*/

#pragma once

#include "AScene.hpp"
#include "Button.hpp"

namespace MySandBox {
    namespace Scenes {
        class SMainMenu: public MySandBox::Scenes::AScene {
            public:
                SMainMenu(MySandBox::State &state, MySandBox::Game &game);
                ~SMainMenu();
                void update();
                void display();
            protected:
            private:
                MySandBox::Component::Button _play_button;
                MySandBox::Component::Button _settings_button;
                MySandBox::Component::Button _exit_button;
                std::string _map_path;
        };
    };
};