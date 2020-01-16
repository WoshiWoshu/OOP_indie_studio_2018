/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

Menu::Menu(int w, int h) : 
w(w), 
h(h)
{
}

void Menu::setBackground(irr::video::IVideoDriver *driver)
{
    irr::video::ITexture *image = driver->getTexture("./source/media/bombwp.jpg");

    driver->draw2DImage(image,
            irr::core::position2d<irr::s32>(0, 0),
            irr::core::rect<irr::s32>(0, 0, w, h),
            0,
            irr::video::SColor(220, 220, 220, 220),
            true);
}

void Menu::setButtons(irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *gui)
{
    irr::core::rect<irr::s32> startRect = irr::core::rect<irr::s32>(w / 25, 2 * h / 3, w / 6, 2 * h / 3 + h / 14);
    irr::core::rect<irr::s32> optRect = irr::core::rect<irr::s32>(w / 25, 2 * h / 3 + h / 12, w / 6, 2 * h / 3 + h / 14 + h / 12);
    irr::core::rect<irr::s32> exitRect = irr::core::rect<irr::s32>(w / 25, 2 * h / 3 + 2 * h / 12, w / 6, 2 * h / 3 + h / 14 + 2 * h / 12);
    
    irr::gui::IGUIButton *startGameBtn = gui->addButton(startRect, 0, BUTTONS::GUI_ID_PLAY, L"PLAY");
    irr::gui::IGUIButton *optGameBtn = gui->addButton(optRect, 0, BUTTONS::GUI_ID_OPT, L"OPTIONS");
    irr::gui::IGUIButton *exitGameBtn = gui->addButton(exitRect, 0, BUTTONS::GUI_ID_QUIT, L"EXIT");
}

void Menu::setGOScreen(irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *gui)
{
    irr::video::ITexture *image = driver->getTexture("./source/media/terrain/gameover.png");

    driver->draw2DImage(image,
            irr::core::position2d<irr::s32>(0, 0),
            irr::core::rect<irr::s32>(0, 0, w, h),
            0,
            irr::video::SColor(255, 255, 255, 255),
            true);  
}