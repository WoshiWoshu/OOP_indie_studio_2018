/*
** EPITECH PROJECT, 2019
** Indie_studio
** File description:
** map part
*/

#ifndef MAP_HPP_
#define MAP_HPP_
#include "Include.hpp"
#include "Tile.hpp"
#define DOUBLETILE  std::vector<std::vector<indie_game::Tile>>
namespace indie_game
{
    class Map {
        public:
            Map(int _width = 50, int _height = 50);
            ~Map();
            DOUBLETILE getField() const;
            void setField(boomberCase a, int x, int y);
            int getHeight() const;
            int getWidth() const;
            Map operator=(Map a);
            

        private:
            int width;
            int height;
            DOUBLETILE field;

    };    
} // namespace indie


#endif /* !MAP_HPP_ */
