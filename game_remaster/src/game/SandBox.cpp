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
    _window.create(sf::VideoMode((this->_window_size = sf::VideoMode::getDesktopMode())), "MySandBox");
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
        std::cout << "Initializing: resources/map_textures/" << it->second << std::endl;
        _textures[it->second] = sf::Texture();
        if (!_textures[it->second].loadFromFile(map_resources_folder + it->second))
            std::cerr << "[!!] Texture not loaded: " << map_resources_folder + it->second << std::endl;
        //_window.draw(sf::Sprite(_textures[it->second]));
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
            //_window.clear(sf::Color::Green);
        }
        else
            //_window.clear(sf::Color::Black);

        this->display_map();
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


void SandBox::set_sprite_textures()
{    
    sf::Vector2f scale, pos, size;
    pos = {0, 0};
    size = {(_window_size.width / _map.getWidth()), (_window_size.height / _map.getHeight())};
    for (GameMapObject &map_element : _map.getObjects()) {
        map_element.setSprite(_textures[map_element.getTexture()]);

        scale.x = SCALE_W(_map.getWidth(), _textures[map_element.getTexture()].getSize().x);
        scale.y = SCALE_H(_map.getHeight(), _textures[map_element.getTexture()].getSize().y);
        map_element.getSprite().setScale(scale);
        map_element.getSprite().setPosition(pos);
        if (pos.x >= (_map.getWidth() - 1) * size.x) {
            pos.x = 0;
            pos.y += size.y;
        }
        else
            pos.x += size.x;
    }

}


void SandBox::display_map()
{

    int x = 1;
    for (GameMapObject &map_element : _map.getObjects())
    {
        //map_element.setSprite(_textures[map_element.getTexture()]);

        _window.draw(map_element.getSprite());

        if (x >= this->_map.getWidth()) {
            x = 0;
        }

        x++;
    }

}