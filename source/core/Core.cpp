/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Core.cpp
*/

#include "IGraph.hpp"
#include "GraphicalEngine.hpp"
#include "Core.hpp"

IndieStudioCore::Core::Core() {

}

IndieStudioCore::Core::~Core() {

}

void IndieStudioCore::Core::runMainLoop() {
    indie_game::Monitor monitor;
    std::unique_ptr<IGraph> graphEngine(std::make_unique<GraphicalEngine>());

    graphEngine->setUp(monitor);
    graphEngine->loop(monitor);
}
