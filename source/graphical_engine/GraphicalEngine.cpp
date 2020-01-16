/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** GraphicalEngine.cpp
*/

#include "GraphicalEngine.hpp"

GraphicalEngine::GraphicalEngine() :
    _device(irr::createDevice(irr::video::EDT_OPENGL,
    irr::core::dimension2d<irr::u32>(1280, 720),
    32, false, false, false)),
    _driver(_device->getVideoDriver()),
    _sceneManager(_device->getSceneManager()),
    _sceneNodes(_sceneManager),
    _frameRate(_device),
    _eventReceiver(_sceneNodes.getBombermanP1(),
    _sceneNodes.getBombermanP2(),
    _sceneNodes.getBombermanE1(),
    _sceneNodes.getBombermanE2(),
    _sceneNodes.getBomb(),
    _sceneNodes.getTerrain()),
    _gui(_sceneManager->getGUIEnvironment()),
    _menu(1280, 720)
{}

void GraphicalEngine::setUp(indie_game::Monitor &monitor)
{
    _device->setEventReceiver(&_eventReceiver);
    _sceneNodes.configureSceneNodes(_driver, _device, monitor, _sceneManager);
    //_menu.setButtons(_driver, _gui);
    _sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(50, 50, 100),
    irr::core::vector3df(50, 50, 10));
    _sceneManager->setAmbientLight(irr::video::SColorf(1.0, 1.0, 1.0, 0.0));
}

void GraphicalEngine::loop(indie_game::Monitor &monitor)
{
    Graph output(0);
    IndieStudioGraphicalEngine::input inputValue[2];
    IndieStudioGraphicalEngine::GraphicalInput inputInfo;

    _frameRate.setNow(_device);
    _frameRate.setThen();
    while (_device->run()) {
        _frameRate.setFrameDeltaTime();
        _driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
        inputValue[0] = _eventReceiver.getInputP1();
        inputValue[1] = _eventReceiver.getInputP2();
        inputInfo.setP1(inputValue[0]);
        inputInfo.setP2(inputValue[1]);
        output = monitor.run(inputInfo);
        for (size_t i = 0; i < output.size(); i++) {
            _eventReceiver.setInputs(_frameRate.getFrameDeltaTime(),
            std::get<0>(output[i]), _driver, _sceneManager,
            std::get<2>(output[i]).getX(),
            std::get<2>(output[i]).getY());
        }
        _eventReceiver.cleanUpP2();
        if (_eventReceiver.getState() == indie_graph::GS::MENU) {
            _menu.setBackground(_driver);
            _menu.setButtons(_driver, _gui);
            _gui->drawAll();
        } else if (_eventReceiver.getState() == indie_graph::GS::GO) {
            _gui->clear();
            _menu.setGOScreen(_driver, _gui);
            _gui->drawAll();
        } else
            _sceneManager->drawAll();
        _driver->endScene();
    }
    _device->drop();
}
