/*
** EPITECH PROJECT, 2018
** project_name INDIE
** File description:
** Player.hpp
*/

#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Include.hpp"
#include "Point.hpp"
#include "GraphicalInput.hpp"

namespace indie_game
{
    enum ID
    {
        PLAYER1,
        PLAYER2,
        ENEMY1,
        ENEMY2,
    };
    class Player
    {
        public:
            Player(int positionX = 5, int positionY = 5);
            ~Player();
            void move(IndieStudioGraphicalEngine::input &in);
            inline Point getPosition() const { return _pos; }
            inline bool getLife() const { return _life; }
            inline int getNbBombs() const { return _nbBombs; }
            inline int getBonusFireUp() const { return _bonusFireUp; }
            inline int getBonusSpeed() const { return _bonusSpeed; }
            bool const getBonusWallPass();
            inline int getBombsAct() const { return _bombsActived; }
            inline ID getID() const { return _myId; }
            inline IndieStudioGraphicalEngine::input getLastPos() const { return _lastPos; }
            inline void setBonusFireUp() { _bonusFireUp += 1; }
            inline void setBonusBomb() { _nbBombs += 1; }
            inline void setBonusSpeed() { _bonusSpeed += 1; }
            inline void setBonusWallPass() { _start = std::chrono::system_clock::now(); }
            inline void setLife() { _life = false; }
            inline void setID(ID _id) { _myId = _id; }
            bool setBomb();
            inline void decActBombs() { _bombsActived -= 1; }
            inline void setPosition(const int x, const int y) {
                _pos.setX(x);
                _pos.setY(y);
            }
        private:
            ID _myId;
            bool _life;
            Point _pos;
            int _bonusFireUp;
            int _bonusSpeed;
            int _nbBombs;
            int _bombsActived;
            IndieStudioGraphicalEngine::input _lastPos;
            std::chrono::time_point<std::chrono::system_clock> _start;
            std::chrono::time_point<std::chrono::system_clock> _end;
            std::chrono::duration<double> _elapsedSeconds;
    };
}

#endif
