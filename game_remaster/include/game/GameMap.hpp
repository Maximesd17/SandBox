#ifndef ___GAMEMAP_HPP___
#define ___GAMEMAP_HPP___

#include <iostream>
#include "GameMapObject.hpp"



class GameMap {
public:
    GameMap(int width, int height, std::vector<GameMapObject> objects);
    void display() const;

private:
    int width_;
    int height_;
    std::vector<GameMapObject> objects_;
};



#endif //___GAMEMAP_HPP___