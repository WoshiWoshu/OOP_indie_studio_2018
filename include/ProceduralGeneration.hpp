/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** generation of the map
*/

#ifndef PROCEDURAL_GENERATION_HPP_
#define PROCEDURAL_GENERATION_HPP_
#include "Map.hpp"
#include "Include.hpp"
namespace indie_game {
    class ProceduralGeneration {
	    public:
		    ProceduralGeneration(int x = 40, int y = 25, int numberPlayer = 2, int numberEnemy = 2);
		    ~ProceduralGeneration();
            void printMap();
            Map generateMap();
            int getNumberPlayer() const;
            int getNumberEnemy() const;
            Map getMap() const;
	    private:
            int width;
            int height;
            int numPlayer;
            int numEnemy;
            Map map;
            std::mt19937 gen;
            void generatePlayer();
            void generateWall();
            void generateBreakableBlocks();
            void generateEnemy();
            bool aroundWall(int a, int b);
            bool aroundStuff(int a, int b);
    };
}

#endif
