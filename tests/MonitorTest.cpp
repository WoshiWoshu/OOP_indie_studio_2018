/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** MonitorTest.cpp
*/

#include "Monitor.hpp"
#include <criterion/criterion.h>

//Test putBomb
Test(Monitor, putbomb)
{
    indie_game::Monitor mymonit;
    std::chrono::time_point<std::chrono::system_clock> _start;
    std::chrono::time_point<std::chrono::system_clock> _end;
    std::chrono::duration<double> _elapsedSeconds;
    IndieStudioGraphicalEngine::GraphicalInput input;

    /* input.setP1(IndieStudioGraphicalEngine::PUTBOMB);
    //input.setP2(IndieStudioGraphicalEngine::RIGHT);
    Output::Graph gameState = mymonit.run(input); */
    //cr_assert(std::get<0>(gameState.front()) == indie_game::P1);

    //input.setP1(IndieStudioGraphicalEngine::RIGHT);
    //gameState = mymonit.run(input);
    //std::cout << std::get<0>(gameState.front()) << std::endl;
    /* std::cout << "before" << std::endl;
    std::cout << "X : " << std::get<1>(gameState.back()).getX() << std::endl;
    std::cout << "Y : " << std::get<1>(gameState.back()).getY() << std::endl; */
    /* cr_assert(std::get<0>(gameState.front()) == indie_game::BOMB);
    _start = std::chrono::system_clock::now();
    _end = std::chrono::system_clock::now();

    while (_elapsedSeconds.count() < 3) {
        _end = std::chrono::system_clock::now();
        _elapsedSeconds = _end - _start;
    } */

    //input.setP1(IndieStudioGraphicalEngine::RIGHT);
    /* input.setP1(IndieStudioGraphicalEngine::PUTBOMB);
    gameState = mymonit.run(input);
    for (size_t i = 0; i < gameState.size(); ++i)
        std::cout << std::get<0>(gameState[i]) << std::endl; */
    /* std::cout << "after" << std::endl;
    std::cout << "X : " << std::get<2>(gameState.back()).getX() << std::endl;
    std::cout << "Y : " << std::get<2>(gameState.back()).getY() << std::endl;
    std::cout << "Player1" << std::endl;
    std::cout << "X : " << std::get<2>(gameState.front()).getX() << std::endl;
    std::cout << "Y : " << std::get<2>(gameState.front()).getY() << std::endl; */
    //cr_assert(std::get<0>(gameState.front()) == indie_game::BLAST);
}