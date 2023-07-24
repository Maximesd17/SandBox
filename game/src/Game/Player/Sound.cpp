/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** Sound.cpp
*/

#include "Sound.hpp"
#include "SandBox.hpp"

MySandBox::Game::Sound::Sound::Sound(){
    /* Class constructor */
};
MySandBox::Game::Sound::Sound::~Sound(){
    /* Class destructor */
};
void MySandBox::Game::Sound::Sound::playSound(std::string fileName){
    /* Method to load file into buffer then play said sound */

    sf::Sound _sound;
    sf::SoundBuffer _buffer;

    _buffer.loadFromFile(fileName);
    _sound.setBuffer(_buffer);
    _sound.play();

};
void MySandBox::Game::Sound::Sound::stopSound(){
    /* Method to stop sound playback */

    _sound.stop();
    
};