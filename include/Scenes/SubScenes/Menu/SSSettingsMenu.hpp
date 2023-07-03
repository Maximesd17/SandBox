/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SSMainMenu
*/

#pragma once

#include "Range.hpp"
#include "SMenu.hpp"

namespace MySandBox {
    namespace Scenes {
        class SSSettingsMenu : public MySandBox::Scenes::AScene {
        public:
            SSSettingsMenu(MySandBox::State& state, MySandBox::Game::Game& game);
            ~SSSettingsMenu();
            void update();
            void display();
        protected:
        private:
            MySandBox::Component::Range _volume_range;
            MySandBox::Component::Button _return_button;
        };
    };
};