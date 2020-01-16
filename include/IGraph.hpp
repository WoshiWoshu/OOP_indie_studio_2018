/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** IGraph.hpp
*/

#pragma once

#include "Monitor.hpp"

class IGraph {
public:
    virtual ~IGraph() = default;
    virtual void setUp(indie_game::Monitor &monitor) = 0;
    virtual void loop(indie_game::Monitor &monitor) = 0;
};
