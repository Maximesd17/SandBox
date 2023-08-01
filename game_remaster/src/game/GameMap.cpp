#include "GameMap.hpp"

void GameMap::display() const
{
    std::cout << "Height is " << height_ << "\nWidth is " << width_ << std::endl;
    int x = 1;
    for (const GameMapObject& obj : _objects) {
        std::cout << static_cast<int>(obj.getType());

        if (x >= width_) {
            std::cout << '\n';
            x = 0;
        }

        x++;
    }
}

GameMap::GameMap(int width, int height, std::vector<GameMapObject> objects)
    : width_(width), height_(height), _objects(std::move(objects))
    {

    }

std::vector<GameMapObject> &GameMap::getObjects()
{
    return _objects;
}

int GameMap::getWidth() const
{
    return width_;
}

int GameMap::getHeight() const
{
    return height_;
}