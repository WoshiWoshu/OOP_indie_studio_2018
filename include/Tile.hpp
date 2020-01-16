/*
** EPITECH PROJECT, 2019
** Indie_Studio
** File description:
** Tile obkect
*/

#ifndef TILE_HPP_
#define TILE_HPP_
namespace indie_game {
    enum boomberCase
    {
        BOMB,
        P1,
        P2,
        P_DEAD,
        P_MWP,
        P_GETBONUS_SPPED,
        P_GETBONUS_BOMB,
        P_GETBONUS_FIREUP,
        P_GETBONUS_WALL_PASS,
        E1,
        E2,
        WALL,
        BONUS_BOMB,
        BONUS_FIREUP,
        BONUS_WALL_PASS,
        BONUS_SPEED,
        BBLOCKS,
        EMPTY,
        BLAST,
        P1_WIN,
        P2_WIN,
        LOSE,
        NOP
    };
    class Tile {
        public:
            Tile(boomberCase a);
            ~Tile();
            boomberCase getTile() const;
            void setTile(boomberCase newValue);
            bool getOnfire() const;
            void setOnFire(bool fire);
            
        private:
            boomberCase inside;
            bool onFire;

    };
}
#endif /* !TILE_HPP_ */
