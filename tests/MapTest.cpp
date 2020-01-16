/*
** EPITECH PROJECT, 2019
** Indie_studio
** File description:
** MapTest
*/

#include "Map.hpp"
#include "Player.hpp"
#include <criterion/criterion.h>

Test(Map, getWidth)
{
    indie_game::Map a(10,12);
    cr_assert(a.getWidth() == 10);
}

Test(Map, getHeight)
{
    indie_game::Map a(10,12);
    cr_assert(a.getHeight() == 12);
}

Test(Map, setField)
{
    indie_game::Map a(10,12);
    a.setField(indie_game::P1, 1, 1);
    DOUBLETILE b = a.getField();
    cr_assert(b[1][1].getTile() == indie_game::P1);
}

Test(Map, equalMap)
{
     indie_game::Map a(10,12);
     indie_game::Map b(8,10);
     a = b;
     cr_assert(a.getHeight() == b.getHeight());
}

