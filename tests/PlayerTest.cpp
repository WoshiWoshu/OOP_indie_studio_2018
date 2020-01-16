/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** PlayerTest.cpp
*/

#include "Player.hpp"
#include <criterion/criterion.h>

//Test position
Test(Player, getPosition)
{
    indie_game::Player bomber(5,5);
    cr_assert(bomber.getPosition().getX() == 5 && bomber.getPosition().getY() == 5);
    IndieStudioGraphicalEngine::input in;

    //UP
    in = IndieStudioGraphicalEngine::UP;
    bomber.move(in);
    cr_assert(bomber.getPosition().getX() == 4 && bomber.getPosition().getY() == 5);

    //Down
    in = IndieStudioGraphicalEngine::DOWN;
    bomber.move(in);
    cr_assert(bomber.getPosition().getX() == 5 && bomber.getPosition().getY() == 5);

    //Left
    in = IndieStudioGraphicalEngine::LEFT;
    bomber.move(in);
    cr_assert(bomber.getPosition().getX() == 5 && bomber.getPosition().getY() == 4);

    //Right
    in = IndieStudioGraphicalEngine::RIGHT;
    bomber.move(in);
    cr_assert(bomber.getPosition().getX() == 5 && bomber.getPosition().getY() == 5);
}

//Test life
Test(Player, getLife)
{
    indie_game::Player bomber(5,5);
    cr_assert(bomber.getLife() == true);
    bomber.setLife();
    cr_assert(bomber.getLife() == false);
}

//Test number of bombs
Test(Player, getNbBombs)
{
    indie_game::Player bomber(5,5);
    cr_assert(bomber.getNbBombs() == 1);
    bomber.setBonusBomb();
    cr_assert(bomber.getNbBombs() == 2);
}

//Test fireUpBonus
Test(Player, getBonusFireUp)
{
    indie_game::Player bomber(5,5);
    cr_assert(bomber.getBonusFireUp() == 1);
    bomber.setBonusFireUp();
    cr_assert(bomber.getBonusFireUp() == 2);
}

//Test speedBonus
Test(Player, getBonusSpeed)
{
    indie_game::Player bomber(5,5);
    cr_assert(bomber.getBonusSpeed() == 1);
    bomber.setBonusSpeed();
    cr_assert(bomber.getBonusSpeed() == 2);
}