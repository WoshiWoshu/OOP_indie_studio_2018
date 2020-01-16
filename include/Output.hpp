/*
** EPITECH PROJECT, 2019
** Indie studio
** File description:
** output file
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include <tuple>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Tile.hpp"


using Graph = std::vector<std::tuple<indie_game::boomberCase, Point, Point>>;

class Output {
public:
  Output();
  ~Output();
  Graph getOut() const;
  void setOut(Graph t);
private:
  Graph out;
};
#endif 
