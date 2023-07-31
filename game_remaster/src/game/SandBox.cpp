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

// ressources/map_textures/ for foreach tout les .png dans ce dossier et je m'occupe de push les texture dans la map lol
    const std::string map_resources_folder("./resources/map_textures/"); 
    const std::map<const std::string, const std::string> textures_paths{
        {"AIR", "air.png"},
        {"BOX", "box.png"},
        {"END", "end.png"},
        {"GROUND", "ground.png"},
        {"PLATFORM", "platform.png"},
        {"START", "start.png"},
        {"WALL", "wall.png"},
    };

    for (std::map<const std::string, const std::string>::const_iterator it = textures_paths.begin(); it != textures_paths.end(); it++) {
        _textures[it->second].loadFromFile(map_resources_folder + it->second);
    }
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
        {
            _window.clear(sf::Color::Green);
            this->display_map();
        }
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

void SandBox::set_map(GameMap map)
{
    this->_map = map;
}

GameMap SandBox::getMap() const
{
    return _map;
}


void SandBox::display_map()
{
    for (GameMapObject map_element : _map.getObjects())
    {
        std::cout << "ressources/map_textures/" << map_element.getTexture() << std::endl;
    }

    int x = 1;
    for (GameMapObject map_element : _map.getObjects()) 
    {
        //std::cout << static_cast<int>(obj.getType());
        _window.draw(map_element.getSprite());
        //_textures[map_element.getTexture()]
        if (x >= this->_map.getWidth()) {
            std::cout << std::endl;
            x = 0;
        }

        x++;
    }

}