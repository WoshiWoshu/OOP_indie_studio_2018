/*
** EPITECH PROJECT, 2019
** Indie_studio
** File description:
** implementation Tile
*/

#include "Tile.hpp"

indie_game::Tile::Tile(indie_game::boomberCase a): inside(a), onFire(false)
{
}

indie_game::Tile::~Tile()
{
}

indie_game::boomberCase indie_game::Tile::getTile() const
{
    return inside;
}

void indie_game::Tile::setTile(indie_game::boomberCase a)
{
    inside = a;
}

bool indie_game::Tile::getOnfire() const
{
    return onFire;
}

void indie_game::Tile::setOnFire(bool a)
{
    onFire = a;
}


