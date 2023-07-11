/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SMainMenu
*/

#pragma once

#include "SMenu.hpp"

namespace MySandBox {
    namespace Scenes {
        class SSettingsMenu: public MySandBox::Scenes::AScene {
            public:
                SSettingsMenu(MySandBox::State &state, MySandBox::Game::Game &game);
                ~SSettingsMenu();
                void update();
                void display();
            protected:
            private:
                MySandBox::Component::Button _return_button;
        };
    };
};