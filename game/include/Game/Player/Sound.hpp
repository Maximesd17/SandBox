/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** Sound.hpp
*/

#ifndef SOUND_HPP
#define SOUND_HPP

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>

namespace MySandBox {
    namespace Game {
        namespace Sound {
            class Sound {
                public:
                    Sound();
                    ~Sound();
                    void loadSound(std::string _fileName);
                    void playSound();
                    void stopSound();
                private:
                    std::string fileName;
                    sf::Sound _sound;
                    sf::SoundBuffer _buffer;
            };
        }
    }
};

#endif // SOUND_HPP