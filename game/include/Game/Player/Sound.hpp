/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** Sound.hpp
*/

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
                    void playSound(std::string fileName);
                    void stopSound();
                private:
                    sf::Sound _sound;
                    sf::SoundBuffer _buffer;
            };
        }
    }
};
