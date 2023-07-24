#include "SandBox.hpp"

/*********Constructor*********/
/* This create a windows     */
/* using SFML lib and        */
/* init the scenes of game   */
/*********Constructor*********/
SandBox::SandBox() 
:   _event_manager(this->_window, this->_camera, this->_entities),
    _framerate(60)
{
    _window.create(sf::VideoMode(sf::VideoMode::getDesktopMode()), "MySandBox");
    _window.setFramerateLimit(_framerate);

}


/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
SandBox::~SandBox()
{
}

/*****Main loop of the sandbox*****/
/*  a loop to cach actions        */
/*****Main loop of the sandbox*****/
void SandBox::loop()
{
    while (_window.isOpen()) 
    {
        if (this->_event_manager.fetchEvent()) 
            _window.clear(sf::Color::Green);
        else           
            _window.clear(sf::Color::Black);
        _window.display();
    }
}


/*****Main loop of the sandbox*****/
/*  a loop to cach actions        */
/*****Main loop of the sandbox*****/
void SandBox::start()
{
    this->loop();
}

