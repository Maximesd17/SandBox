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
sf::Sound MySandBox::Game::Sound::Sound::loadSound(std::string _fileName){
    /* Method to load file into buffer */
    _buffer.loadFromFile(_fileName);
    _sound.setBuffer(_buffer);

    return _sound;
};

void MySandBox::Game::Sound::Sound::playSound(){
    /* Method to play sound */
    _sound.play();
};

void MySandBox::Game::Sound::Sound::stopSound(){
    /* Method to stop sound playback */
    _sound.stop();
};