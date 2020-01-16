/*
** EPITECH PROJECT, 2019
** Indie_studio
** File description:
** Interface for game
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_
#include "Output.hpp"
#include "Input.hpp"

class IGame {
	public:
		~IGame();
        GRAPH run(Input in); 

};

#endif /* !IGAME_HPP_ */
