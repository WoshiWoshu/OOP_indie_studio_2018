/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** BombTest.cpp
*/
#include "Bomb.hpp"
#include <criterion/criterion.h>


//Test chrono
Test(Bomb, getChrono)
{
    indie_game::Player p(5,5);
    indie_game::Bomb b(5, 5, p.getID());
    while (b.getChrono() != true)
        continue;
    cr_assert((int)b.getElapsed() == 3);
}

//Test position
Test(Bomb, getPos)
{
    indie_game::Player p(5,8);
    indie_game::Bomb b(5, 8, p.getID());
    cr_assert(b.getPos().getX() == 5 && b.getPos().getY() == 8);
}

//Test blasField
Test(Bomb, blastField)
{
    //fireUp 1
    indie_game::Player p(5,5);
    indie_game::Bomb b(5, 5, p.getID());
    
    //main tile
    cr_assert(std::get<1>(b.blastField()[0]).getX() == 5);
    cr_assert(std::get<1>(b.blastField()[0]).getY() == 5);
    //left tile (y-1)
    cr_assert(std::get<1>(b.blastField()[1]).getX() == 5);
    cr_assert(std::get<1>(b.blastField()[1]).getY() == 4);
    //up tile (x-1)
    cr_assert(std::get<1>(b.blastField()[2]).getX() == 4);
    cr_assert(std::get<1>(b.blastField()[2]).getY() == 5);
    //down tile (x+1)
    cr_assert(std::get<1>(b.blastField()[3]).getX() == 6);
    cr_assert(std::get<1>(b.blastField()[3]).getY() == 5);
    //right tile (y+1)
    cr_assert(std::get<1>(b.blastField()[4]).getX() == 5);
    cr_assert(std::get<1>(b.blastField()[4]).getY() == 6);

    /* //fireUp 2
    indie_game::Bomb b2(5, 5, 2);
    //main tile
    cr_assert(b2.blastField()[0].getX() == 5);
    cr_assert(b2.blastField()[0].getY() == 5);
    //left tile (y-1)
    cr_assert(b2.blastField()[1].getX() == 5);
    cr_assert(b2.blastField()[1].getY() == 4);
    //up tile (x-1)
    cr_assert(b2.blastField()[2].getX() == 4);
    cr_assert(b2.blastField()[2].getY() == 5);
    //down tile (x+1)
    cr_assert(b2.blastField()[3].getX() == 6);
    cr_assert(b2.blastField()[3].getY() == 5);
    //right tile (y+1)
    cr_assert(b2.blastField()[4].getX() == 5);
    cr_assert(b2.blastField()[4].getY() == 6);
    //left tile (y-2)
    cr_assert(b2.blastField()[5].getX() == 5);
    cr_assert(b2.blastField()[5].getY() == 3);
    //up tile (x-2)
    cr_assert(b2.blastField()[6].getX() == 3);
    cr_assert(b2.blastField()[6].getY() == 5);
    //down tile (x+2)
    cr_assert(b2.blastField()[7].getX() == 7);
    cr_assert(b2.blastField()[7].getY() == 5);
    //right tile (y+2)
    cr_assert(b2.blastField()[8].getX() == 5);
    cr_assert(b2.blastField()[8].getY() == 7); */
}