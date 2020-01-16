/*
** EPITECH PROJECT, 2019
** Indie studi
** File description:
** ProceduralGeneration
*/

#include "ProceduralGeneration.hpp"

indie_game::ProceduralGeneration::ProceduralGeneration(int x, int y, int numberPlayer, int numberEnemy)
{
    width = y;
    height = x;
    numEnemy = numberEnemy;
    numPlayer = numberPlayer;
    indie_game::Map a(x, y);
    map = a;
    std::random_device rd;
    std::mt19937 b(rd());
    gen = b;
}

indie_game::ProceduralGeneration::~ProceduralGeneration()
{
}

int indie_game::ProceduralGeneration::getNumberPlayer() const
{
    return numPlayer;
}

int indie_game::ProceduralGeneration::getNumberEnemy() const
{
    return numEnemy;
}

void indie_game::ProceduralGeneration::generatePlayer()
{
    std::uniform_int_distribution<> dis(1, 4);
    int corner = dis(gen);
    if (corner == 1)
        map.setField(indie_game::P1, 0, 0);
    else if(corner == 2)
        map.setField(indie_game::P1, 0, width);
    else if(corner == 3)
        map.setField(indie_game::P1, height, width);
    else
        map.setField(indie_game::P1, height, 0);
    if (numPlayer < 2)
        return;
    else {
        if (corner == 1)
            map.setField(indie_game::P2, height, width);
        else if(corner == 2)
            map.setField(indie_game::P2, height, 0);
        else if(corner == 3)
            map.setField(indie_game::P2, 0, 0);
        else
            map.setField(indie_game::P2, 0, width);
    }
}

void indie_game::ProceduralGeneration::printMap()
{
    DOUBLETILE a = map.getField();
    for (int i = 0; i < height+1; i++) {
        for (int j = 0; j < width+1; j++) {
            if (a[i][j].getTile() == BOMB)
                std::cout<<"|B";
            else if (a[i][j].getTile() == P1)
                std::cout<<"|P";
            else if (a[i][j].getTile() == P2)
                std::cout<<"|2";
            else if (a[i][j].getTile() == E1)
                std::cout<<"|E";
            else if (a[i][j].getTile() == E2)
                std::cout<<"|3";
          else if (a[i][j].getTile() == BBLOCKS)
                std::cout<<"|D";
          else if (a[i][j].getTile() == WALL)
                std::cout<<"|W";
          else if (a[i][j].getTile() == EMPTY)
                std::cout<<"| ";
          else if (a[i][j].getTile() == BONUS_BOMB)
                std::cout<<"|F";
        else if (a[i][j].getTile() == BONUS_SPEED)
                std::cout<<"|L";
          else
            std::cout<<"|S";
        }
        std::cout<<"|"<<std::endl;
    }
}

void indie_game::ProceduralGeneration::generateEnemy()
{
    DOUBLETILE a = map.getField();
        if (a[0][0].getTile() == P1) {
            map.setField(indie_game::E1, height, 0);
            map.setField(indie_game::E2, 0, width);
        }
        else if (a[0][width].getTile() == P1) {
            map.setField(indie_game::E1, height, width);
            map.setField(indie_game::E2, 0, 0);
        }
        else if (a[height][0].getTile() == P1) {
            map.setField(indie_game::E1, height, width);
            map.setField(indie_game::E2, 0, 0);
        }
        else {
            map.setField(indie_game::E1, 0, width);
            map.setField(indie_game::E2, height, 0);
        }

        
}
bool indie_game::ProceduralGeneration::aroundWall(int a, int b)
{
    DOUBLETILE t = map.getField();
    if (t[a][b].getTile() == indie_game::WALL)
        return false;
    else if (t[a+1][b+1].getTile() == indie_game::WALL)
        return false;
    else if (t[a+1][b-1].getTile() == indie_game::WALL)
        return false;
    else if (t[a][b-1].getTile() == indie_game::WALL)
        return false;
    else if (t[a-1][b].getTile() == indie_game::WALL)
        return false;
    else if (t[a-1][b+1].getTile() == indie_game::WALL)
        return false;
    else if (t[a+1][b].getTile() == indie_game::WALL)
        return false;
    else if (t[a][b+1].getTile() == indie_game::WALL)
        return false;
    else if (t[a+1][b-1].getTile() == indie_game::WALL)
        return false;
    else if (t[a-1][b-1].getTile() == indie_game::WALL)
        return false;
    else
        return true;
}

void indie_game::ProceduralGeneration::generateWall()
{
    DOUBLETILE a = map.getField();
    
    int prop = (((height-2) * (width-2))*30)/100;
    int i = 0;
    int x = 2;
    int y = 2;
       while (i < prop) {
        std::uniform_int_distribution<> dis(2, height-2);
        std::uniform_int_distribution<> dis2(2, width-2);
        x = dis(gen);
        y = dis2(gen);
        if (aroundWall(x, y)) {
            map.setField(indie_game::WALL, x, y);
        }
        i++;
    }
}
bool indie_game::ProceduralGeneration::aroundStuff(int a, int b)
{
     DOUBLETILE t = map.getField();
     if (t[a][b].getTile() != indie_game::EMPTY)
        return false;
    if (a == 0 && b == 1)
        return false;
    if (a == 1 && b == 0)
        return false;
    if (a == 1 && b == 1)
        return false;
    if (a == height && b == 1)
        return false;
    if (a == height - 1 && b == 0)
        return false;
    if (a == height - 1 && b == 1)
        return false;
    if (a == 0 && b == width - 1)
        return false;
    if (a == 1 && b == width)
        return false;
    if (a == 1 && b == width - 1)
        return false;
    if (a == height && b == width - 1)
        return false;
    if (a == height - 1 && b == width)
        return false;
    if (a == height - 1 && b == width - 1)
        return false;
    return true;
}
void indie_game::ProceduralGeneration::generateBreakableBlocks()
{
    int prop = (((height-2) * (width-2))*50)/100;
    int i = 0;
    int x = 0;
    int y = 0;
       while (i < prop) {
        std::uniform_int_distribution<> dis(0, height);
        std::uniform_int_distribution<> dis2(0, width);
        x = dis(gen);
        y = dis2(gen);
        if ( aroundStuff(x, y)) {
            map.setField(indie_game::BBLOCKS, x, y);
        }
        i++;
    }
}
indie_game::Map indie_game::ProceduralGeneration::getMap() const
{
    return map;
}
indie_game::Map indie_game::ProceduralGeneration::generateMap()
{
    generatePlayer();
    generateEnemy();
    generateWall();
    generateBreakableBlocks();
    return getMap();
}