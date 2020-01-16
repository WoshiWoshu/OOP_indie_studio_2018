/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** Menu.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

enum BUTTONS
{
    GUI_ID_QUIT = -1,
    GUI_ID_PLAY,
    GUI_ID_OPT,
    GUI_ID_RELOAD
};

class Menu {
    public:
        Menu(int, int);
        ~Menu() = default;
        void setButtons(irr::video::IVideoDriver *driver, 
                       irr::gui::IGUIEnvironment *gui);
        void setBackground(irr::video::IVideoDriver *driver);
        void setGOScreen(irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *gui);
    private:
        int w;
        int h;
        irr::core::dimension2d<irr::u32> _screenSize;
};
