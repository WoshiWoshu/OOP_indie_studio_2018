/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** GraphicalEngine.hpp
*/

#pragma once

#include "Menu.hpp"
#include "IGraph.hpp"
#include "SceneNodes.hpp"
#include "FrameRate.hpp"
#include "CEventReceiver.hpp"
#include "Animations.hpp"

class GraphicalEngine : public IGraph {
public:
    explicit GraphicalEngine();
    ~GraphicalEngine() = default;
    void setUp(indie_game::Monitor &monitor) final;
    void loop(indie_game::Monitor &monitor) final;
private:
    irr::IrrlichtDevice *_device;
    irr::video::IVideoDriver *_driver;
    irr::scene::ISceneManager *_sceneManager;
    SceneNodes _sceneNodes;
    FrameRate _frameRate;
    CEventReceiver _eventReceiver;
    irr::gui::IGUIEnvironment *_gui;
    Menu _menu;
};
