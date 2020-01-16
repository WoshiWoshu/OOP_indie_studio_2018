/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include "Tile.hpp"
#include "Menu.hpp"
#include "Animations.hpp"
#include "GraphicalInput.hpp"

using namespace IndieStudioGraphicalEngine;

namespace indie_graph {
    enum INPUT
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        PUTBOMB,
        EMPTY
    };

    enum GS
    {
        MENU,
        GAME,
        GO
    };
}

class CEventReceiver : public irr::IEventReceiver {
public:
    explicit CEventReceiver(irr::scene::IAnimatedMeshSceneNode* nModel,
    irr::scene::IAnimatedMeshSceneNode* nModel2,
    irr::scene::IAnimatedMeshSceneNode* nModelE1,
    irr::scene::IAnimatedMeshSceneNode* nModelE2,
    std::vector<irr::scene::IMeshSceneNode *> nbombNode,
    std::vector<irr::scene::IMeshSceneNode *> nCubeNodeTerrain);
    virtual bool OnEvent(const irr::SEvent &event) final;
    void setInputs(const irr::f32 frameDeltaTime, indie_game::boomberCase boomCase,
    irr::video::IVideoDriver *driver,
    irr::scene::ISceneManager *_sceneManager, int x, int y);
    inline input getInputP1(void) { return _inputInfo[0]; };
    inline input getInputP2(void) { return _inputInfo[1]; };
    inline indie_graph::GS getState(void) { return _state; };
    inline void cleanUpP2(void) { _inputInfo[1] = NOP; }
private:
    irr::scene::IAnimatedMeshSceneNode* _nModel;
    irr::scene::IAnimatedMeshSceneNode* _nModel2;
    irr::scene::IAnimatedMeshSceneNode* _nModelE1;
    irr::scene::IAnimatedMeshSceneNode* _nModelE2;
    std::vector<irr::scene::IParticleSystemSceneNode *> _particleSystem;
    std::vector<irr::scene::IMeshSceneNode *> _nbombNode;
    std::vector<irr::scene::IMeshSceneNode *> _nCubeNodeTerrain;
    bool _isMoving[8];
    bool _isBomb[2];
    bool _isWalking[2];
    bool _isStanding[2];
    input _inputInfo[2];
    int _iBomb;
    int _iParticule;
    int _iTerrain;
    Animations _animations;
    indie_graph::GS _state;
    void setInputsP1(const irr::f32 frameDeltaTime, indie_game::boomberCase boomCase,
    irr::video::IVideoDriver *driver,
    irr::scene::ISceneManager *sceneManager, int x, int y);
    void setInputsP2(const irr::f32 frameDeltaTime, indie_game::boomberCase boomCase,
    irr::video::IVideoDriver *driver,
    irr::scene::ISceneManager *sceneManager, int x, int y);
    inline void setState(indie_graph::GS g) { this->_state = g; };
    void triggerAnimPlayer1(indie_game::boomberCase boomCase);
    void triggerAnimPlayer2(indie_game::boomberCase boomCase);
};
