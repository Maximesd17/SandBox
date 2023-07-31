/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** Sound.cpp
*/

#include <iostream>
#include "Sound.hpp"

MySandBox::Game::Sound::Sound::Sound(){
    /* Class constructor */
};
MySandBox::Game::Sound::Sound::~Sound(){
    /* Class destructor */
};
void MySandBox::Game::Sound::Sound::loadSound(std::string _fileName){
    /* Method to load file into buffer */
    if(!_buffer.loadFromFile(_fileName))
        std::cout << "Error loading sound file" << std::endl;
};

void MySandBox::Game::Sound::Sound::playSound(){
    /* Method to play sound */
    _sound.setBuffer(_buffer);
    _sound.play();
};

void MySandBox::Game::Sound::Sound::stopSound(){
    /* Method to stop sound playback */
    _sound.stop();
};

void MySandBox::Game::Sound::Sound::noLoop(){
    std::cout << _sound.getLoop() << std::endl;
    _sound.setLoop(false);
};