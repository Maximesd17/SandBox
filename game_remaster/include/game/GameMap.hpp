#ifndef ___GAMEMAP_HPP___
#define ___GAMEMAP_HPP___

#include <iostream>
#include "GameMapObject.hpp"



class GameMap {
public:
    GameMap() = default;
    GameMap(int width, int height, std::vector<GameMapObject> objects);
    void display() const;

    std::vector<GameMapObject> getObjects();
    int getWidth() const;
    int getHeight() const;

private:
    int width_;
    int height_;
    std::vector<GameMapObject> _objects;
};



#endif //___GAMEMAP_HPP___