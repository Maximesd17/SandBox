/*
** EPITECH PROJECT, 2023
** SandBox
** File description:
** Sounds
*/

#pragma once

#include <SFML/Audio/SoundBuffer.hpp>

namespace MySandBox
{
    namespace Game
    {
        namespace Sounds
        {
            class Sound
            {
            public:
                Sound();
                ~Sound();
                explicit Sound(const sf::SoundBuffer);
            };
        }   
    }
}


