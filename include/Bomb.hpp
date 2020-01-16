/*
** EPITECH PROJECT, 2018
** project_name INDIE
** File description:
** Bomb.hpp
*/

#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include "Include.hpp"
#include "Point.hpp"
#include "Player.hpp"
#include "Tile.hpp"

namespace indie_game
{
    class Bomb
    {
        public:
            Bomb(int positionX, int positionY, ID id, int fireUp = 1);
            ~Bomb();
            std::vector<std::tuple<boomberCase, Point, Point>> blastField();
            bool const getChrono();
            ID getPersoId() const { return _persoId; }
            inline double getElapsed() const { return _elapsedSeconds.count(); }
            inline Point getPos() const { return _pos; }
            inline void setBlast() {  _blast = true; }
            inline bool getBlast() { return _blast; }
        private:
            Point _pos;
            ID _persoId;
            int _fireUp;
            int _timeExpl;
            bool _blast;
            std::chrono::time_point<std::chrono::system_clock> _start;
            std::chrono::time_point<std::chrono::system_clock> _end;
            std::chrono::duration<double> _elapsedSeconds;
            inline void setPosition(const int x, const int y) {
                _pos.setX(x);
                _pos.setY(y);
            }
    };
}

std::tuple<indie_game::boomberCase, Point, Point> fillField(int posX, int posY);

#endif
