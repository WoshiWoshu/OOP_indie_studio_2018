/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** GraphicalInput.hpp
*/

#include "Output.hpp"

#ifndef __GRAPHICALINPUT_HPP__
#define __GRAPHICALINPUT_HPP__

namespace IndieStudioGraphicalEngine
{
    enum input
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        PUTBOMB,
        NOP
    };
    class GraphicalInput
    {
        private:
            bool isMenu;
            int w;
            int h;
            int levelDifficulty;
            input P1;
            input P2;

        public:
            GraphicalInput() { P1 = NOP; P2 = NOP; }
            ~GraphicalInput() {};
            inline void setIsMenu(bool change) {isMenu = change;}
            inline void setW(int change) {w = change;}
            inline void setH(int change) {h = change;}
            inline void setLevelDifficulty(int change) {levelDifficulty = change;}
            inline void setP1(input change) {P1 = change;}
            inline void setP2(input change) {P2 = change;}
            inline bool getIsMenu() const {return isMenu;}
            inline int getW() const {return w;}
            inline int getH() const {return h;}
            inline int getLevelDifficulty() const {return levelDifficulty;}
            inline input getP1() const {return P1;}
            inline input getP2() const {return P2;}
    };
}

#endif //OOP_INDIE_STUDIO_2018_GRAPHICALINPUT_HPP
