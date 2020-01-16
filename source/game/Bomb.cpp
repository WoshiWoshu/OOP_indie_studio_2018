/*
** EPITECH PROJECT, 2018
** project_name INDIE
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"

indie_game::Bomb::Bomb(int positionX, int positionY, ID id, int fireUp)
{
    setPosition(positionX, positionY);
    _persoId = id;
    _fireUp = fireUp;
    _timeExpl = 3;
    _blast = false;
    _start = std::chrono::system_clock::now();
    _end = std::chrono::system_clock::now();
    _elapsedSeconds = _end - _start;
}

indie_game::Bomb::~Bomb(){}

bool const indie_game::Bomb::getChrono()
{
    _end = std::chrono::system_clock::now();
    _elapsedSeconds = _end - _start;

    if (_elapsedSeconds.count() < _timeExpl)
        return false;
    return true;
}

std::vector<std::tuple<indie_game::boomberCase, Point, Point>> indie_game::Bomb::blastField()
{
    std::vector<std::tuple<boomberCase, Point, Point>> fieldAction;
    Point tmp;
    std::tuple<boomberCase, Point, Point> newTuple;
    tmp.setXY(_pos.getX(), _pos.getY());
    newTuple = std::make_tuple(BLAST, tmp, tmp);
    fieldAction.push_back(newTuple);

    for (int i = 1; i <= _fireUp; ++i) {
        fieldAction.push_back(fillField(_pos.getX(), _pos.getY() - i));
        fieldAction.push_back(fillField(_pos.getX() - i, _pos.getY()));
        fieldAction.push_back(fillField(_pos.getX() + i, _pos.getY()));
        fieldAction.push_back(fillField(_pos.getX(), _pos.getY() + i));
    }

    return fieldAction;
}

std::tuple<indie_game::boomberCase, Point, Point> fillField(int posX, int posY)
{
    Point tmp;
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;

    tmp.setXY(posX, posY);
    newTuple = std::make_tuple(indie_game::BLAST, tmp, tmp);

    return newTuple;
}