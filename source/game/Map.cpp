/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** implmentation of map
*/

#include "Map.hpp"

indie_game::Map::Map(int _width, int _height)
{
    DOUBLETILE H(_height);
    std::vector<indie_game::Tile> W(_width, EMPTY);
    for (int i = 0; i < _height; i++)
        H[i] = W;
    height = _height;
    width = _width;
    field = H;
}

indie_game::Map::~Map()
{
}

int indie_game::Map::getWidth() const
{
    return width;
}

int indie_game::Map::getHeight() const
{
    return height;
}

DOUBLETILE indie_game::Map::getField() const
{
    return field;
}

void indie_game::Map::setField(indie_game::boomberCase a, int x, int y)
{
    field[x][y].setTile(a);
}

indie_game::Map indie_game::Map::operator=(indie_game::Map a)
{
    height = a.height;
    width = a.width;
    DOUBLETILE field = a.field;
    return (*this);
}