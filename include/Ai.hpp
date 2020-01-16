/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_
#include <random>
#include <time.h>
#include "Enemies.hpp"
#include "Output.hpp"

namespace indie_game {
    class Ai {
        public:
            Ai();
            ~Ai();
            const Graph run();
            bool getL1() const { return bot1L; }
            bool getL2() const { return bot2L; }
            void setL1(bool a) { bot1L = a; }
            void setL2(bool a) { bot2L = a; }
            void setEnemy(Point _bot1, Point _bot2);
            void movBot1(Point &p);
            void movBot2(Point &p);
            Point getPBot1()const { return bot1.getPos(); }
            Point getPBot2() const { return bot2.getPos(); }
        private:
            void move();
            bool bot1L;
            bool bot2L;
            Enemies bot1;
            Enemies bot2;
            std::mt19937 gen;
    };
}

#endif /* !AI_HPP_ */