/*
** EPITECH PROJECT, 2019
** indie_studio
** File description:
** Output
*/

#include "Output.hpp"

Output::Output()
{
}

Output::~Output()
{
}

Graph Output::getOut() const
{
    return out;
}

void Output::setOut(Graph t)
{
    out = t;
}