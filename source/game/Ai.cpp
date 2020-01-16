/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** AI
*/

#include "Ai.hpp"
#include <iostream>
indie_game::Ai::Ai()
{
    std::random_device rd;
    std::mt19937 b(rd());
    gen = b;
    bot1L = true;
    bot2L = true;
}

indie_game::Ai::~Ai()
{
}

void indie_game::Ai::setEnemy(Point _bot1, Point _bot2)
{
    indie_game::Enemies bot(1, _bot1.getX(), _bot1.getY());
    indie_game::Enemies bo(2, _bot2.getX(), _bot2.getY());
    bot1 = bot;
    bot2 = bo;
}

void indie_game::Ai::movBot1(Point &p)
{
    bot1.setPos(p.getX(), p.getY());
}

void indie_game::Ai::movBot2(Point &p)
{
    bot2.setPos(p.getX(), p.getY());
}
 
void indie_game::Ai::move()
{
    std::uniform_int_distribution<> dis(1, 4);
    srand (time(NULL));
    int direction = (rand() % (4 - 1 + 1)) + 1;//dis(gen);
    //std::cout<<direction<<std::endl;
     if (bot1L) {
        switch(direction) {
            case 1:
                bot1.move(UP);
                break;
            case 2:
                bot1.move(RIGHT);
                break;
            case 3:
                bot1.move(DOWN);
                break;
            case 4:
                bot1.move(LEFT);
        }
     }
    direction = (rand() % (4 - 1 + 1)) + 1;//dis(gen);
    if (bot2L) {
    switch(direction) {
            case 1:
                bot2.move(UP);
                break;
            case 2:
                bot2.move(RIGHT);
                break;
            case 3:
                bot2.move(DOWN);
                break;
            case 4:
                bot2.move(LEFT);
        }
    }
}

const Graph indie_game::Ai::run()
{
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;
    std::tuple<indie_game::boomberCase, Point, Point> newTuple2;
    Graph state;
    Point old_state = bot1.getPos();
    Point old_state2 = bot2.getPos();
    move();
    if(bot1L) {
        newTuple = std::make_tuple(E1, old_state, bot1.getPos());
        state.push_back(newTuple);
    }

    if (bot2L) {
        newTuple2 = std::make_tuple(E2, old_state2, bot2.getPos());
        state.push_back(newTuple2);
    }    
    return state;
}