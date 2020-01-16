/*
** EPITECH PROJECT, 2018
** project_name INDIE
** File description:
** Player.cpp
*/

#include "Player.hpp"

indie_game::Player::Player(int positionX, int positionY)
{
    _life = true;
    setPosition(positionX, positionY);
    _bonusFireUp = 1;
    _bonusSpeed = 1;
    _nbBombs = 1;
    _bombsActived = 0;
}

indie_game::Player::~Player(){}

bool indie_game::Player::setBomb()
{
    if ((_bombsActived < _nbBombs) && _life) {
        _bombsActived += 1;
        return true;
    }
    return false;
}

bool const indie_game::Player::getBonusWallPass()
{
    _end = std::chrono::system_clock::now();
    _elapsedSeconds = _end - _start;

    if (_elapsedSeconds.count() < 3)
        return true;
    return false;
}

void indie_game::Player::move(IndieStudioGraphicalEngine::input &in)
{
    switch (in) {
        case IndieStudioGraphicalEngine::UP:
            setPosition(_pos.getX() - 1, _pos.getY());
            _lastPos = IndieStudioGraphicalEngine::UP;
            break;
        case IndieStudioGraphicalEngine::DOWN:
            setPosition(_pos.getX() + 1, _pos.getY());
            _lastPos = IndieStudioGraphicalEngine::DOWN;
            break;
        case IndieStudioGraphicalEngine::RIGHT:
            setPosition(_pos.getX(), _pos.getY() + 1);
            _lastPos = IndieStudioGraphicalEngine::RIGHT;
            break;
        case IndieStudioGraphicalEngine::LEFT:
            setPosition(_pos.getX(), _pos.getY() - 1);
            _lastPos = IndieStudioGraphicalEngine::LEFT;
            break;
    }
}