/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SSMainMenu
*/

#pragma once

#include "Range.hpp"
#include "Game.hpp"
#include "ASubScene.hpp"
#include "SettingsEditor.hpp"

namespace MySandBox {
    namespace Scenes {
        namespace SubScenes {
            class SSSettingsMenu : public ASubScene {
            public:
                SSSettingsMenu(MySandBox::State& state, MySandBox::Game::Game& game);
                ~SSSettingsMenu();
                void events(sf::Event& event);
                void update();
                void display();
            protected:
            private:
                sf::Text _title;
                sf::Font _font;
                MySandBox::Components::SettingsEditor _settings_editor;
                MySandBox::Components::Button _return_button;
            };
        }
    };
};