/*
** EPITECH PROJECT, 2023
** SandBox
** File description:
** SettingsEditor
*/

#ifndef SETTINGSEDITOR_HPP_
#define SETTINGSEDITOR_HPP_

#include "Game.hpp"
#include "Range.hpp"

namespace MySandBox {
    namespace Components {
        class SettingsEditor {
        public:
            SettingsEditor(Game::Game &game, sf::Vector2i position, sf::Vector2f size);
            ~SettingsEditor();
            void update();
            void display();
        protected:
        private:
            Game::Game &_game;
            Components::Range _music_volume;
            Components::Range _sound_volume;
        };
    }
}

#endif /* !SETTINGSEDITOR_HPP_ */
