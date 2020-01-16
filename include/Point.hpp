/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** point
*/

#ifndef POINT_HPP_
#define POINT_HPP_

//#include "Include.hpp"

class Point {
	public:
		Point(int _x = 0, int _y = 0) {x = _x; y = _y;}
		~Point() {}
        inline int getX() const { return x; }
        inline int getY() const { return y; }
        inline void setX(int new_x) { x = new_x; }
        inline void setY(int new_Y) { y = new_Y; }
        inline void setXY(int new_X, int new_Y) {
            x = new_X;
            y = new_Y;
        }
        /* inline Point operator=(Point a) {
            x = a.x;
            y = a.y;
            return (*this);
        } */
	private:
        int x;
        int y;
};

#endif /* !POINT_HPP_ */
