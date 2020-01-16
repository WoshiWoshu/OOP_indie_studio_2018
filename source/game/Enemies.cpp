/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** Enemies
*/

#include "Enemies.hpp"
indie_game::Enemies::Enemies(int id, int x, int y): _myId(id), _life(true)
{
    Point a(x, y);
    _pos = a;
}

indie_game::Enemies::~Enemies()
{
}

int indie_game::Enemies::getId() const
{
    return _myId;
}

bool indie_game::Enemies::getLife() const
{
    return _life;
}

Point indie_game::Enemies::getPos() const
{
    return _pos;
}

void indie_game::Enemies::setPos(int x, int y)
{
    _pos.setXY(x, y);
}

void indie_game::Enemies::setAPos(int x, int y)
{
    Point pos = getPos();
    setPos(pos.getX() + x, pos.getY() + y);
}

void indie_game::Enemies::move(inputIA in)
{
    switch (in)
    {
    case UP:
        setAPos(1, 0);
        break;
    case RIGHT:
        setAPos(0, 1);
    case DOWN:
        setAPos(-1, 0);
        break;
    case LEFT:
        setAPos(0, -1);
    
    default:
        break;
    }
}
