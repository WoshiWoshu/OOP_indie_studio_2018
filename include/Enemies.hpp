/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** Enemies
*/

#ifndef ENEMIES_HPP_
#define ENEMIES_HPP_
#include "Point.hpp"
 enum inputIA
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };
namespace indie_game {
    class Enemies {
        public:
            Enemies(int id=1, int x = 0, int y=0);
            ~Enemies();
            void move(inputIA in);
            void setAPos(int x, int y);
            void setPos(int x, int y);
            Point getPos() const;
            int getId() const;
            bool getLife() const;

        private:
            int _myId;
            bool _life;
            Point _pos; 

    };
}
#endif /* !ENEMIES_HPP_ */
