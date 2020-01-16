#ifndef _MONITOR_HPP_
#define _MONITOR_HPP_

#include <memory>
#include <time.h>
#include "Ai.hpp"
#include "Output.hpp"
#include "GraphicalInput.hpp"
#include "Bomb.hpp"
#include "ProceduralGeneration.hpp"

namespace indie_game
{
    class Monitor
    {
        public:
            Monitor();
            DOUBLETILE create();
            ~Monitor();
            Graph run(IndieStudioGraphicalEngine::GraphicalInput input);
            inline Map getMap(void) { return _mapProcedure; };
            void printMap();
        private:
            Player _p1;
            Player _p2;
            std::vector<Bomb> _bombAct;
            Map _mapProcedure;
            DOUBLETILE _map;
            Graph _blastSave;
            Ai _enemy;
            bool _over;
            boomberCase _gameOv;

            void setPlayer();
            boomberCase genBonus();
            Graph manageEnemy(Graph moveEnemy);
            Graph gameOver();
            Graph manageGover(Graph moveE);
            bool checkMoveEnemy(boomberCase cas);
            Graph destroyBlock(Graph blast);
            Graph controlBlast(Graph blast);
            boomberCase checkTile(Player &p, IndieStudioGraphicalEngine::input in);
            Graph checkBomb();
            Graph makeChangeState(Player &p1, Player &p2, IndieStudioGraphicalEngine::GraphicalInput input);
            Graph moveP1andP2(Player &p1, Player &p2, IndieStudioGraphicalEngine::GraphicalInput input);
            Graph moveP(Player &p, IndieStudioGraphicalEngine::input in);
            std::tuple<boomberCase, Point, Point> setBomb(Player &p);
            std::tuple<boomberCase, Point, Point> movePlayer(Player &p, IndieStudioGraphicalEngine::input in);
            std::tuple<boomberCase, Point, Point> moveCas(Player &p, IndieStudioGraphicalEngine::input &in, boomberCase cas);
            std::tuple<boomberCase, Point, Point> enemyCas(Player &p);
            boomberCase imgToDisplay(boomberCase cas, Player &p);
            bool checkMove(Player &p, IndieStudioGraphicalEngine::input in);
    };
}

#endif
